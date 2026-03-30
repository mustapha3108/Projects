#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <errno.h>

pid_t pid_h = 0, pid_m = 0, pid_s = 0;

void kill_children_and_exit(int status) {
    if (pid_h > 0) kill(pid_h, SIGTERM);
    if (pid_m > 0) kill(pid_m, SIGTERM);
    if (pid_s > 0) kill(pid_s, SIGTERM);

    int w;
    while (waitpid(-1, &w, 0) > 0) {}
    _exit(status);
}

void parent_sigint(int sig) {
    (void)sig;
    kill_children_and_exit(EXIT_SUCCESS);
}

void run_hour(int read_fd) {
    prctl(PR_SET_PDEATHSIG, SIGTERM);
    setvbuf(stdout, NULL, _IOLBF, 0);

    unsigned char buf;
    int hours = 0;

    while (read(read_fd, &buf, 1) == 1) {
        hours++;
        if (hours >= 24) hours = 0;
        printf("hours: %d\n", hours);
    }
    _exit(0);
}

void run_minute(int read_fd, int write_fd) {
    prctl(PR_SET_PDEATHSIG, SIGTERM);
    setvbuf(stdout, NULL, _IOLBF, 0);

    unsigned char buf;
    int minutes = 58;

    while (read(read_fd, &buf, 1) == 1) {
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            unsigned char one = 1;
            if (write(write_fd, &one, 1) != 1) {
                perror("minute: write to hour");
                break;
            }
        }
        printf("minutes: %d\n", minutes);
    }
    _exit(0);
}

void run_second(int write_fd) {
    prctl(PR_SET_PDEATHSIG, SIGTERM);
    setvbuf(stdout, NULL, _IOLBF, 0);

    int s = 55;
    while (1) {
        sleep(1);
        s++;
        if (s >= 60) {
            s = 0;
            unsigned char one = 1;
            if (write(write_fd, &one, 1) != 1) {
                perror("second: write to minute");
                break;
            }
        }
        printf("second: %d\n", s);
    }
    _exit(0);
}

int main(void) {
    int sec_min[2];
    int min_hour[2];
    if (pipe(sec_min) == -1) { perror("pipe sec_min"); exit(1); }
    if (pipe(min_hour) == -1) { perror("pipe min_hour"); exit(1); }

    struct sigaction sa = {0};
    sa.sa_handler = parent_sigint;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    /* fork hour */
    pid_h = fork();
    if (pid_h < 0) { perror("fork hour"); exit(1); }
    if (pid_h == 0) {
        close(sec_min[0]); close(sec_min[1]);
        close(min_hour[1]);
        run_hour(min_hour[0]);
    }

    /* fork minute */
    pid_m = fork();
    if (pid_m < 0) { perror("fork minute"); kill_children_and_exit(1); }
    if (pid_m == 0) {
        close(sec_min[1]);
        close(min_hour[0]);
        run_minute(sec_min[0], min_hour[1]);
    }

    /* fork second */
    pid_s = fork();
    if (pid_s < 0) { perror("fork second"); kill_children_and_exit(1); }
    if (pid_s == 0) {
        close(sec_min[0]);
        close(min_hour[0]); close(min_hour[1]);
        run_second(sec_min[1]);
    }

    close(sec_min[0]); close(sec_min[1]);
    close(min_hour[0]); close(min_hour[1]);

    /* wait for any child death */
    int status;
    while (wait(&status) > 0) {
        kill_children_and_exit(EXIT_FAILURE);
    }

    return 0;
}

