#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


typedef struct{
    int tab[10];
    int indxl;
    int indxr;
} madata;

int main(){

    key_t key=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'b');
    int shmid=shmget(key,sizeof(madata),IPC_CREAT|IPC_EXCL|0666);
    if (shmid == -1) shmid = shmget(key, sizeof(madata), 0666);

    madata *shmval = shmat(shmid, NULL, 0);
    for (int i = 0; i < 9; i++){
        shmval->tab[i]=0;
    }
    shmval->indxl = 0;
    shmval->indxr = 0;

    shmdt(shmval);

    key_t mutexkey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'm');

    key_t fullkey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'f');
    key_t emptykey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'e');
    key_t prokey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'p');
    key_t conkey=ftok("/home/crow/uni/rsd-s1/sys/tp1/exo4", 'c');

    int mutex = semget(mutexkey, 1, IPC_CREAT | IPC_EXCL | 0666);
    int full = semget(fullkey, 1, IPC_CREAT | IPC_EXCL | 0666);
    int empty = semget(emptykey, 1, IPC_CREAT | IPC_EXCL | 0666);
    int pro = semget(prokey, 1, IPC_CREAT | IPC_EXCL | 0666);
    int con = semget(conkey, 1, IPC_CREAT | IPC_EXCL | 0666);

    if (full == -1) mutex = semget(mutexkey, 1, 0666);
    if (full == -1) full = semget(fullkey, 1, 0666);
    if (empty == -1) empty = semget(emptykey, 1, 0666);
    if (pro == -1) pro = semget(prokey, 1, 0666);
    if (con == -1) con = semget(conkey, 1, 0666);

    semctl(mutex, 0, SETVAL, 1);
    semctl(full, 0, SETVAL, 0);
    semctl(empty, 0, SETVAL, 10);
    semctl(pro, 0, SETVAL, 1);
    semctl(con, 0, SETVAL, 1);
    
    return 0;
}