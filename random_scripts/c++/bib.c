#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    int x;
    int y;
} examplestruct;

void changep(int *p){
    *p=20;
}

int main(){
    int x=5;
    float f;
    double d;
    char c = 'c';
    int vec[25];
    //bool open=true;
    char string[100] = "hellow world";
    strcat(string, " hello world 2");
    printf("%s \n", string);
    printf("%d \n", x);

    if(x<2){
        //
    }else{
        //
    }

    for(int i=0; i<10; i++){

    }
    while(x<5){

    }

    examplestruct xx={5,6};


    int *p = &x;
    *p=50;
    changep(&p);

    float *v = (float *)malloc(sizeof(float)*5);
    for (int i =0; i<5; i++){
        v[i]=10;
    }
    v = realloc(v, sizeof(float)*6);
    v[5]=2;
    for (int i=0; i<6; i++){
        printf("%f  ", v[i]);
    }
    free(v);

    int m;
    float dd;

    int vect[5];
    for(int i=0; i<5;i+=2){
        vect[i]=i+4;
       printf("%d ",vect[i]);
    }




    
    
    return 0;
}