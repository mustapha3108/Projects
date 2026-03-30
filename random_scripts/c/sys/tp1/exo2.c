#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>





void seminit (int idsem, int numsem, /*int initval*/ unsigned short vals[4]){

    int r = semctl(idsem, numsem, /*SETVAL*/ SETALL, /*initval*/ vals);
    if(r==-1){
        //negga i hate that line
        perror("something went horribly wrong, we need chandler's sacrasm for this: ");

    }
    
    int pid = semctl(idsem, 2, GETPID);
    printf("the pid is: %d \n", pid);

}

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void printsem(int idsem, int numsem) {
    unsigned short vals[4];
    union semun arg;
    arg.array = vals;

    if (semctl(idsem, 0, GETALL, arg) == -1) { 
        perror("semctl GETALL");
        return;
    }

    printf("Semaphore values: ");
    for (int i = 0; i < 4; i++) {
        printf("%hu ", vals[i]);   
    }
    printf("\n");
}

void p(int idsem, int numsem){
    int val =  semctl(idsem, numsem, GETVAL);
    int x = val--;
    semctl(idsem, numsem, SETVAL, x);
    while (1){

        if(semctl(idsem, numsem, GETVAL) <0){
            wait();
        }
    }
    
}
void v(int idsem, int numsem){
    int val =  semctl(idsem, numsem, GETVAL);
    int x = val++;
    semctl(idsem, numsem, SETVAL, x);
}

void barriere(int semid, int n){

}

int main(){

    unsigned short vals[4] = {100,5, 90, 60};
    //seminit(0, 3, 900);
    seminit(0, 3, vals);
    printsem(0,3);



    return 0;
}