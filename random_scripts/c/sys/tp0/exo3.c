#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h>

int main(){

    printf("the parent process is: %d \n", getpid());
    int pid1, pid2, pid5;
    
    pid1=fork();
    if(pid1 == 0){
        printf("pid1 process started: %d \n", getpid());
        int pid3, pid4;

        pid3 = fork();
        if(pid3 == 0){
            printf("pid3 process started: %d \n", getpid());
            sleep(10);
            exit(90);
        }

        pid4 = fork();
        if(pid4==0){
            printf("pid4 process started: %d \n", getpid());
            sleep(10);
            exit(0);
        }

        int status;
        waitpid(pid3, &status, 0);
        //printf("status est: %d \n", WEXITSTATUS(status));
        waitpid(pid4, &status, 0);
        sleep(10);
        exit(0);
    }

    pid2=fork();
    if(pid2 == 0){
        printf("pid2 process started: %d \n", getpid());
        sleep(10);
        exit(0);
    }

    int status;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    printf("all four processes are done \n");

    pid5 = fork();
    if(pid5 == 0){
        printf("pid5 process started: %d \n", getpid());
        sleep(10);
        exit(0);
    }

    waitpid(pid5, &status, 0);
    printf("all processes done \n");



    return 0;
}