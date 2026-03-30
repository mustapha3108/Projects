//#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

struct sembuf P = {0, -1, 0};
struct sembuf V = {0, +1, 0};


int main(){
    

    /*single value semaphore*/

    //--1 creating semaphore
    key_t key =  ftok("/home/crow/uni/rsd-s1/sys", 67);
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);

    //--2 get semaphore
    if (semid == -1) semid = semget(key, 1, 0666);

    //--3 set semaphore
    semctl(semid, 0, SETVAL, 5);

    //--4 recieve semaphore value
    int crow = semctl(semid, 0, GETVAL);
    printf("semaphore value is: %d \n", crow);

    //--4 blocking and stuff
    semop(semid, &P, 1);

    //--5 delete semaphore
    semctl(semid, 0, IPC_RMID);


    /*-------------------------*/


    /*shared memory*/

    //--1 creating shared memory
    int shmid = shmget(key, sizeof(int), IPC_CREAT | IPC_EXCL |0666);

    //--2 get shared memory
    if(shmid == -1 ) shmid = shmget(key, sizeof(int), 0666);

    //--3 get sharedmemory value
    int *shmval = shmat(shmid, NULL, 0);
    printf("shared memory ol value: %d \n", *shmval);

    //--4 set sharedmemory value
    *shmval = 500;

    //--5 detach from memory
    shmdt(shmval);

    //--6 delete
    shmctl(shmid, IPC_RMID, NULL);


    /*--------------------------*/


    /*multi value semaphore*/

    key_t keya = ftok("/home/crow/uni/rsd-s1/sys", 5);
    int semida = semget(keya, 5, IPC_CREAT | IPC_EXCL | 0666);
    if (semida == -1) semida = semget(keya, 5, 0666);
    short arr[5] = {5,6,8,9,2};
    semctl(semida, 0, SETALL, arr);
    printf("semid %d \n", semida);
    semctl(semida, 0, IPC_RMID);
    /*
    union semun { int val; struct semid_ds *buf; unsigned short *array; };

    semctl(semid, 0, SETALL,
       (union semun){ .array = (unsigned short[5]){ [0 ... 4] = 7 } });

    */




    return 0;
}