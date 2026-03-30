#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>

struct sembuf p = {0,-1,0};
struct sembuf v = {0,+1,0};

void bondHydrogen(){
    printf("hydrogen bonding %d \n", getpid());
}

void arrived(){

    int temp;

    key_t shmkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'M');
    int shmid = shmget(shmkey, sizeof(int), 0666);

    key_t checkkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'C');
    int checkid = semget(checkkey, 1, 0666);

    key_t blockkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'B');
    int blockid = semget(blockkey, 1, 0666);

    semop(checkid, &p, 1);
    int *mem = shmat(shmid, NULL, 0);
    *mem = *mem + 1;
    temp = *mem;
    semop(checkid, &v, 1);

    if(temp==3){
        semop(blockid, &v, 1);
        semop(blockid, &v, 1);
    }else{
        semop(blockid, &p, 1);
    }
}


int main(){

    key_t sectionkey = ftok("/home/crow/uni/rsd-s1/sys/tp1", 'S');
    int sectionid = semget(sectionkey, 1, 0666);


    int h2;
    h2 = fork();
    if (h2 == 0){
        arrived();
        semop(sectionid, &p, 1);
        bondHydrogen();
        semop(sectionid, &v, 1);
    }

    arrived();
    semop(sectionid, &p, 1);
    bondHydrogen();
    semop(sectionid, &v, 1);

    return 0;
}