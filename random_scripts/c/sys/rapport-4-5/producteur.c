#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>


typedef struct{
    int tab[10];
    int indxl;
    int indxr;
} madata;

struct sembuf p = {0, -1, 0};
struct sembuf v = {0, +1, 0};
// semop(semid, &p, 1);

void produce(madata *shm){
    int in = shm->indxr;
    shm->tab[in] = 1;
    if (in==9) shm->indxr = 0;   
    else shm->indxr = in + 1;
    sleep(1);
    printf("produced: %d \n", in);
}

int main(){

    key_t key=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'b');
    int shmid = shmget(key, sizeof(madata), 0666);

    madata *shmval = shmat(shmid, NULL, 0);

    key_t mutexkey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'm');
    key_t fullkey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'f');
    key_t emptykey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'e');
    key_t prokey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'p');
    key_t conkey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'c');

    int mutex = semget(mutexkey, 1, 0666);
    int full = semget(fullkey, 1, 0666);
    int empty = semget(emptykey, 1, 0666);
    int pro = semget(prokey, 1, 0666);
    int con = semget(conkey, 1, 0666);

    while (1)
    {
        semop(pro, &p, 1);
        semop(empty, &p, 1);
        semop(mutex, &p, 1);

        produce(shmval);

        semop(mutex, &v, 1);
        semop(full, &v, 1);
        semop(pro, &v, 1);
    }

    return 0;

}