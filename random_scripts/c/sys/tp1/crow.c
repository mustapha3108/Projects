#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>



int main(){


    key_t key = ftok ("/home/etudiant/", 'c');
    int semid=semget(key, 2, IPC_CREAT| IPC_EXCL| 0666);
    if(semid == -1){
        perror("semget: ");
        printf("un groupe exist deja pour cet clé\n");
        semid = semget(key,2, 0);
        printf("can't see but i guess printing semid: %d\n", semid);
    }
    unsigned short vals[2] = {100,5};
    int r = semctl(semid, 0, SETALL, vals);
    if(r==-1){
        perror("something went horribly wrong, we need chandler's sacrasm for this: ");

    }

    return 0;
}