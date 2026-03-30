#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <time.h>


void algo1(int prime, char path[100]){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int isprime = 0;
    for(int i = 2; i<prime; i++){
        if(prime%i == 0){
            isprime = 1;
        }
    }

    if(isprime == 0){printf("le nombre %d est premier,  ", prime);}
    else{printf("le nombre %d n'est pas premier \n", prime);}



    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("temps d'execution pour algo 1, nombre %d : %.6f seconds\n", prime ,elapsed);
    FILE *res = fopen(path, "a");
    fprintf(res, "%d %f\n", prime, elapsed);
    fclose(res);
    if (prime == 100000000003)
    {
        exit(0);
    }
    

}

void algo2(int prime,char path[100]){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int isprime = 0;
    for(int i = 2; i<=prime/2; i++){
        if(prime%i == 0){
            isprime = 1;
        }
    }

    if(isprime == 0){printf("le nombre %d est premier,  ", prime);}
    else{printf("le nombre %d n'est pas premier \n", prime);}



    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("temps d'execution pour algo 2, nombre %d : %.6f seconds\n", prime ,elapsed);
    FILE *res = fopen(path, "a");
    fprintf(res, "%d %f\n", prime, elapsed);
    fclose(res);

}

void algo3(int prime,char path[100]){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int isprime = 0;
    for(int i = 2; i<=sqrt(prime); i++){
        if(prime%i == 0){
            isprime = 1;
        }
    }

    if(isprime == 0){printf("le nombre %d est premier,  ", prime);}
    else{printf("le nombre %d n'est pas premier \n", prime);}



    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("temps d'execution pour algo 3, nombre %d : %.6f seconds\n", prime ,elapsed);
    FILE *res = fopen(path, "a");
    fprintf(res, "%d %f\n", prime, elapsed);
    fclose(res);

}

void algo4(int prime,char path[100]){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int isprime = 0;
    if(prime%2!=0){
        for(int i = 3; i<=sqrt(prime); i=i+2){
            if(prime%i == 0){
                isprime = 1;
            }
        }
    }

    if(isprime == 0){printf("le nombre %d est premier,  ", prime);}
    else{printf("le nombre %d n'est pas premier \n", prime);}



    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("temps d'execution pour algo 4, nombre %d : %.6f seconds\n", prime ,elapsed);
    FILE *res = fopen(path, "a");
    fprintf(res, "%d %f\n", prime, elapsed);
    fclose(res);

}

void fillvec(const char *filename, int *vector) {
    FILE *file = fopen(filename, "r");
    int value;
    int i = 0;
    while (fscanf(file, "%d", &value) == 1) {
        vector[i] = value;
        i++;
    }
    fclose(file);
}


int main(){

    int primes[12] = {1000003, 2000003, 4000037, 8000009, 16000057, 32000011, 64000031, 
                      128000003, 256000001, 512000009, 1024000009, 2048000011};
    
    printf("----------algo 1------------\n");
    for(int i = 0; i<12; i++){
        algo1(primes[i], "outputnumber.txt");
    }

    printf("----------algo 2------------\n");
    for(int i = 0; i<12; i++){
        algo2(primes[i], "outputnumber.txt");
    }

    printf("----------algo 3------------\n");
    for(int i = 0; i<12; i++){
        algo3(primes[i], "outputnumber.txt");
    }

    printf("----------algo 4------------\n");
    for(int i = 0; i<12; i++){
        algo4(primes[i], "outputnumber.txt");
    }

    /*--------------------tp0 tests-----------------*/

    struct timespec start, end;
    double elapsed;
    FILE *res = fopen("output.txt", "w");
    int *random100 = malloc(sizeof(int)*100);
    int *random1000 = malloc(sizeof(int)*1000);
    int *test1 = malloc(sizeof(int)*100);
    int *test2 = malloc(sizeof(int)*100);
    int *test3 = malloc(sizeof(int)*100);

    fillvec("random100.txt", random100);
    fillvec("random1000.txt", random1000);
    fillvec("test-1.txt", test1);
    fillvec("test-2.txt", test2);
    fillvec("test-3.txt", test3);

    printf("-------------random100--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(random100[i], "random100algo1.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo1: %f seconds \n", elapsed);
    printf("random100 algo1: %f seconds\n", elapsed);

    sleep(20);
    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(random100[i], "random100algo2.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo2: %f seconds \n", elapsed);
    printf("random100 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(random100[i], "random100algo3.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo3: %f seconds \n", elapsed);
    printf("random100 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(random100[i], "random100algo4.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random100->algo4: %f seconds \n", elapsed);
    printf("random100 algo4: %f seconds\n", elapsed);

    //clock algo 2
    printf("-------------random1000--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo1(random1000[i], "random1000algo1.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo1: %f seconds \n", elapsed);
    printf("random1000 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo2(random1000[i], "random1000algo2.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo2: %f seconds \n", elapsed);
    printf("random1000 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo3(random1000[i], "random1000algo3.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo3: %f seconds \n", elapsed);
    printf("random1000 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<1000; i++){ algo4(random1000[i], "random1000algo4.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "random1000->algo4: %f seconds \n", elapsed);
    printf("random1000 algo4: %f seconds\n", elapsed);



    printf("-------------test1--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(test1[i], "test1algo1.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo1: %f seconds \n", elapsed);
    printf("test1 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(test1[i], "test1algo2.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo2: %f seconds \n", elapsed);
    printf("test1 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(test1[i], "test1algo3.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo3: %f seconds \n", elapsed);
    printf("test1 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(test1[i], "test1algo4.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test1->algo4: %f seconds \n", elapsed);
    printf("test1 algo4: %f seconds\n", elapsed);


    printf("-------------test2--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(test2[i], "test2algo1.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo1: %f seconds \n", elapsed);
    printf("test2 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(test2[i], "test2algo2.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo2: %f seconds \n", elapsed);
    printf("test2 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(test2[i], "test2algo3.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo3: %f seconds \n", elapsed);
    printf("test2 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(test2[i], "test2algo4.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test2->algo4: %f seconds \n", elapsed);
    printf("test2 algo4: %f seconds\n", elapsed);


    printf("-------------test3--------------\n");

    //algo1
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo1(test3[i], "test3algo1.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo1: %f seconds \n", elapsed);
    printf("test3 algo1: %f seconds\n", elapsed);

    //algo2
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo2(test3[i], "test3algo2.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo2: %f seconds \n", elapsed);
    printf("test3 algo1: %f seconds\n", elapsed);

    //algo3
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo3(test3[i], "test3algo3.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo3: %f seconds \n", elapsed);
    printf("test3 algo3: %f seconds\n", elapsed);

    //algo4
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i<100; i++){ algo4(test3[i], "test3algo4.txt"); }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    fprintf(res, "test3->algo4: %f seconds \n", elapsed);
    printf("test3 algo4: %f seconds\n", elapsed);

    fclose(res);

    return 0;
}