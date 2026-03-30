#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

struct sembuf p = {0, -1, 0};
struct sembuf v = {0, +1, 0};


void printer(int semid, int id){
    printf("process %d entered the printer", id);
    semop(semid, &p, 1);
    sleep(rand()%3);
    semop(semid, &v, 1);
    printf("process %d exited the printer", id);
    exit(0);
}








int main(){

    struct sembuf p = {0, -1, 0};
    struct sembuf v = {0, +1, 0};

    for(int i=0, i<3, i++){
        int pid = fork();
        if(pid!=1){
            printer()
        }
    }


    //semop(semid, &p, 1);
    //semop(semid, &v, 1);





    return 0;
}