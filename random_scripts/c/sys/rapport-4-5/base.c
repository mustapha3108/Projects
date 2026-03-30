#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>



int main(){

    /*create shared memory and semaphores*/
    /*shared memory to check if all three arrived + semaphore for it*/
    /*semaphore to block , not inside the shm semaphore so gotta make a temp variable*/
    /*sem for the actual critical section*/
    key_t shmkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'M');
    int shmid = shmget(shmkey, sizeof(int), IPC_CREAT | IPC_EXCL | 0666);
    if(shmid == -1) shmid =  shmget(shmkey, sizeof(int), 0666);
    int *mem = shmat(shmid, NULL, 0);
    *mem = 0;

    key_t checkkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'C');
    int checkid = semget(checkkey, 1, IPC_CREAT | IPC_EXCL | 0666);
    if(checkid == -1) checkid = semget(checkkey, 1, 0666);
    semctl(checkid, 0, SETVAL, 1);

    key_t blockkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'B');
    int blockid = semget(blockkey, 1, IPC_CREAT | IPC_EXCL | 0666);
    if(blockid == -1) blockid = semget(blockkey, 1, 0666);
    semctl(blockid, 0, SETVAL, 0);

    key_t sectionkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'S');
    int sectionid = semget(sectionkey, 1, IPC_CREAT | IPC_EXCL | 0666);
    if(sectionid == -1) sectionid =  semget(sectionkey, 1, 0666);
    semctl(sectionid, 0, SETVAL, 1);

    shmdt(mem);

    return 0;
}