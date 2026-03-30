#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>

//I FIGURED THIS SHIT OUT!!!!!!

int fathesequence = 0;
int fatherstringpointer = 0;
int fathersequencesize[] = {1,2,3,4,5,6,5};
char fatherstring[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int sonsequence = 0;
int sonstringpointer = 0;
int sonsequencesize[] = {3,3,4,5,6,5};
char sonstring[] = "abcdefghijklmnopqrstuvwxyz";

pid_t fatherpid;
pid_t sonpid;
//int cancontinue;

void sonrecsig(int sig){
    //cancontinue = 1;
}

void fatherrecsig(int sig){
    //cancontinue = 0;
}

void printsonsequence(int i){
    sonsequence = i;
    int j = 0;
    while(j<sonsequencesize[i]){
        printf("%c", sonstring[sonstringpointer + j]);
        fflush(stdout);
        j++;
    }
    sonstringpointer = sonstringpointer + j;
}

void printfathersequence(int i){
    fathesequence = i;
    int j = 0;
    while(j<fathersequencesize[i]){
        printf("%c", fatherstring[fatherstringpointer + j]);
        fflush(stdout);
        j++;
    }
    fatherstringpointer = fatherstringpointer + j;
}

int main(){

    pid_t son;
    
    
    son = fork();
    if(son == 0){

        signal(SIGUSR1, sonrecsig);//sets cancontinue to 1
        //cancontinue = 0;
        for(int  i = 0; i<6; i++){
            /*
            while (cancontinue == 0){
                pause();
            }
            */
            pause();
            printsonsequence(i);
            kill(getppid(), SIGUSR1); 
            //cancontinue = 0;
        }

        exit(0);
    }

    //nanosleep(&(struct timespec){0, 500000000L}, NULL);


    fatherpid = getpid();
    sonpid = son;

    signal(SIGUSR1, fatherrecsig);//sets cancontinue to 0
    //cancontinue = 0;

    for(int i = 0; i<7; i++){
        /*
        while (cancontinue == 1){
            pause();
        }
        */
        if(i!=0){pause();}
        printfathersequence(i);
        kill(son, SIGUSR1); 
        //cancontinue = 1;
    }

    wait(NULL);
    printf("\nfather id: %d, son id: %d", fatherpid, sonpid);
    printf("\n");


    return 0;
}

