#include <stdio.h>
#include <unistd.h> // fork
#include <stdlib.h> // exit

int main(){
    int npid = 5;
    int pid;
    for(int i=0; i<npid; i++){
        pid = fork();
        if (pid == - 1){ 
            /* code si échec : */
            perror ("fork") ;
            exit(1) ; //sortir sur un code d’erreur
        }
        if (pid==0){
        // Code du fils
            printf("hello Processus fils de pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(6);
            printf("see ya Processus fils de pid=%d, ppid=%d\n", getpid(), getppid());
            exit(0);
        // Fin du processus fils
        }
    }
    // Suite code du père, si pid > 0
    sleep(10);
    printf("Processus père de pid=%d, ppid=%d \n", getpid(), getppid());
    return 0;
}