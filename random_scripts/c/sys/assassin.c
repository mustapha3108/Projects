#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>

int main(){

    int pid;
    scanf("%d", &pid);
    kill(pid, SIGINT);
    printf("processus tué");
    return 0;
}