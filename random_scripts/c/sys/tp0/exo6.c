#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>

pid_t H, M, S, F;
int houres = 0, minutes = 59, seconds = 55;
bool ready = false;

void Frec(int sig, siginfo_t *info, void *context)
{
    if (info->si_pid == S)
    {
        seconds = info->si_value.sival_int;
        if (seconds != 60)
        {
            printf("%02d : %02d : %02d \n", houres, minutes, seconds);
            fflush(stdout);
        }
    }
    if (info->si_pid == M)
    {
        minutes = info->si_value.sival_int;
        if (minutes != 60)
        {
            printf("%02d : %02d : %02d \n", houres, minutes, 0);
            fflush(stdout);
        }
    }
    if (info->si_pid == H)
    {
        houres = info->si_value.sival_int;
        minutes = 0;
        printf("%02d : %02d : %02d \n", houres, 0, 0);
        fflush(stdout);
    }
}

void Hrec(int sig, siginfo_t *info, void *context) {}
void Mrec(int sig, siginfo_t *info, void *context)
{
    if (info->si_pid == F)
    {
        H = info->si_value.sival_int;
        ready = true;
    }
    if (info->si_pid == S)
    {
        //
    }
}
void Srec(int sig, siginfo_t *info, void *context)
{
    M = info->si_value.sival_int;
    ready = true;
}

int main()
{

    /*
    ---------sending---------
    union sigval sv;
    sv.sival_int = value;
    sigqueue(pid, SIGUSR1, sv)

    --------receiving---------
    void handler(int sig, siginfo_t *info, void *context) {
    printf("Got value: %d\n", info->si_value.sival_int);
    }
    int main(void) {
        struct sigaction sa = {0};
        sa.sa_sigaction = handler; //nom de fonction a decalancher
        sa.sa_flags = SA_SIGINFO;

        sigaction(SIGUSR1, &sa, NULL);
    */

    F = getpid();

    H = fork();
    if (H == 0)
    {
        // receive M signals
        struct sigaction sa = {0};
        sa.sa_sigaction = Hrec;
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &sa, NULL);

        while (true)
        {
            pause();
            houres++;
            union sigval svv;
            svv.sival_int = houres;
            sigqueue(F, SIGUSR1, svv);
        }

        exit(0);
    }

    M = fork();
    if (M == 0)
    {
        // recieve H id and S signals
        struct sigaction sa = {0};
        sa.sa_sigaction = Mrec;
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &sa, NULL);

        while (!ready)
        {pause();}

        union sigval svv;

        while (true)
        {
            pause();
            minutes++;
            svv.sival_int = minutes;
            sigqueue(F, SIGUSR1, svv);

            if (minutes == 60)
            {
                minutes = 0;
                union sigval sv;
                sv.sival_int = 0;
                sigqueue(H, SIGUSR1, sv);
                svv.sival_int = minutes;
                sigqueue(F, SIGUSR1, svv);
            }
        }

        exit(0);
    }

    S = fork();
    if (S == 0)
    {
        // receive M id
        struct sigaction sa = {0};
        sa.sa_sigaction = Srec;
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &sa, NULL);

        while (!ready)
        {
            pause();
        }

        union sigval svv;

        while (true)
        {

            sleep(1);

            seconds++;
            svv.sival_int = seconds;
            sigqueue(F, SIGUSR1, svv);

            if (seconds == 60)
            {
                seconds = 0;
                union sigval sv;
                sv.sival_int = 0;
                sigqueue(M, SIGUSR1, sv);
            }
        }

        exit(0);
    }

    sleep(1);

    // send M pid to S
    union sigval sv;
    sv.sival_int = M;
    sigqueue(S, SIGUSR1, sv);

    // send H pid to S
    union sigval svv;
    svv.sival_int = H;
    sigqueue(M, SIGUSR1, svv);

    // receive values
    struct sigaction sa = {0};
    sa.sa_sigaction = Frec;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    printf("father: %d H:%d M:%d S:%d \n", getpid(), H, M, S);

    while (true)
    {
        pause();
    }

    return 0;
}