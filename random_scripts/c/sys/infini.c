#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>

void hello(int sig){
    printf("Hello ! I am Here \n");
    fflush(stdout);
}

int main(){

    signal(SIGINT, hello);

    while(true){

    }
    return 0;
}

/*
1/rien a passé, le signal associé est sigint 2, program stopped
2/SIGKILL 9 | killed and program stopped
3/infini stops with sigint
4/the process stops
*/