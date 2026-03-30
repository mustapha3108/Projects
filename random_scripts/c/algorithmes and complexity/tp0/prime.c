#include <stdio.h>
#include <math.h>

int main(){

    int prime = 7819;
    /*
    //for loop method
    for(int i = 2; i<prime; i++){
        if(prime%i == 0){
            printf("the number is not prime \n");
            return 0;
        }
    }
    */

    /*
    //1-while loop to the max
    int i = 2;
    while(i<prime){
        if(prime%i == 0){
            printf("the number is not prime \n");
            return 0;
        }
        i++;
    }
    */

    /*
    //2-half way through
    int i=2;
    int p=prime/2
    while(i<p){
        if(prime%i == 0){
            printf("the number is not prime \n");
            return 0;
        }
        i++;
    }
    */

    //3-square root
    int i = 2;
    int rt = sqrt(prime);
    while (i<rt){
        if(prime%i == 0){
            printf("the number is not prime \n");
            return 0;
        }
        i++;
    }
    


    printf("the number is prime \n");


    return 0;
}