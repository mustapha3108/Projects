#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

typedef enum { PROC_FATHER, PROC_HOUR, PROC_MIN, PROC_SEC } role_t;

pid_t pid_h, pid_m, pid_s, pid_f;
int h = 0;
int m = 58;
int s = 55;
bool link_ready = false;
role_t role = PROC_FATHER;


void handler_hour(int sig, siginfo_t *info, void *ctx) {
    if (info->si_pid == pid_m) /*link_ready = true*/;
}

void handler_min(int sig, siginfo_t *info, void *ctx) {
    if (info->si_pid == pid_s) /*link_ready = true*/;
    if (info->si_pid == pid_f) pid_h = info->si_value.sival_int;
}

void handler_sec(int sig, siginfo_t *info, void *ctx) {
    pid_m = info->si_value.sival_int;
    link_ready = true;
}

void setup_handler(void (*fn)(int, siginfo_t *, void *)) {
    struct sigaction sa = {0};
    sa.sa_sigaction = fn;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
}

void run_hour() {
    setup_handler(handler_hour);
    //while (!link_ready) pause();
    while (1) {
        pause();
        h++;
        printf("houres: %d\n", h);
        fflush(stdout);
    }
}

void run_min() {
    setup_handler(handler_min);
    while (!link_ready) pause();
    while (1) {
        pause();
        m++;
        if (m == 60) {
            m = 0;
            union sigval zero = {.sival_int = 0};
            sigqueue(pid_h, SIGUSR1, zero);
        }else{
            printf("minutes: %d\n", m);
            fflush(stdout);
        }
    }
}

void run_sec() {
    setup_handler(handler_sec);
    while (!link_ready) pause();
    while (1) {
        sleep(1);
        s++;

        union sigval v = {.sival_int = s};
        sigqueue(pid_f, SIGUSR1, v);
        if (s == 60) {
            s = 0;
            union sigval zero = {.sival_int = 0};
            sigqueue(pid_m, SIGUSR1, zero);
        }else{
            printf("second: %d\n", s);
            fflush(stdout);
        }
    }
}

int main(void) {
    pid_f = getpid();

    if ((pid_h = fork()) == 0) {
        role = PROC_HOUR;
        run_hour();
        exit(0);
    }

    if ((pid_m = fork()) == 0) {
        role = PROC_MIN;
        run_min();
        exit(0);
    }

    if ((pid_s = fork()) == 0) {
        role = PROC_SEC;
        run_sec();
        exit(0);
    }

    sleep(1);
    union sigval v = {.sival_int = pid_m};
    sigqueue(pid_s, SIGUSR1, v);
    v.sival_int = pid_h;
    sigqueue(pid_m, SIGUSR1, v);

    while (1) pause();
}
