#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


struct sembuf p = {0, -1, 0};
struct sembuf v = {0, +1, 0};
// semop(semid, &p, 1);

int main(){

/*
future notes:
for n consumer and n producers

3 semaphore, three twice:
 2*once with check if you can consume or produce
 once with only consume or produce once at a time
 once for producing or consuming and not both at the same time
 
 
then to free
 conditional freeing consumer or producer
 once for freeing producer/consumer
 once for freeing process as a whole
 
 something like :
 
 PRODUCER:
 
 p1()
 if nb==max pp()
 nb++
 v1()
 
 po()
 produce
 vo()
 
 p1()
 if nb!=0 vc()
 v1()
 
 END PRODUCER
 
 
 CONSUMER:
 p1()
 if nb==0 pc()
 nb--
 v1()
 
 po()
 consume
 vo()
 
 p1()
 if nb!=max vp()
 v1()
 
 END CONSUMER
NOPE FORGET ALL THAT

*/




    return 0;
}
