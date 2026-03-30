#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int semcreate(key_t cle, int n){

    int semid=semget(cle, n, IPC_CREAT| IPC_EXCL| 0666);
    if(semid == -1){
        perror("semget: ");
        printf("un groupe exist deja pour cet clé\n");
        semid = semget(cle,n, 0);
        printf("can't see but i guess printing semid: %d\n", semid);
    }else{
        printf("cemaphore created");
    }
    return semid;
}


int main(){

    key_t key = ftok ("/home/crow/uni/rsd-s1/sys", 'c');
    printf("%d \n", semcreate(key, 4));

    return 0;
}