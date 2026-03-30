#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gx;
int intfunc(){
    return 5;
}
typedef struct{   
    int si;
    float sf;
} str;

float stf_func(str x){
    return x.sf;
}

void pfunc(int *x){
    *x = 1000;
}


int main() {

    //variables
    int x = intfunc();
    float y = 10.5;
    char c ='c';
    char ogstring[] = "hello world";
    char string[20];
    strcpy(string, ogstring);
    strcat(string, " yo");
    str mystr = {5, 5.6};
    mystr.sf=5.1;
    printf("%s and %d and %f and %c and %f \n",string, x, y, c, stf_func(mystr));
    printf("size of string is: %zu \n", sizeof(string));

    //logic
    for(int i = 0; i<10; i++){
        x=x+2;
    }
    while(x<100){
        x++;
    }

    if(x==100){
        printf("duh, x = 100 \n");
    }else if(x>100){
        printf("wtf \n");
    }

    switch (c){
    case 'a':
        printf("c is a");
        break;
    case 'b':
        printf("c is b");
        break;
    default:
        printf("c is c");
        break;
    }

    //pointers
    int *ip = &x;
    *ip = 200;
    printf("\nx is now: %d and the pointer says %d \n", x, *ip);
    pfunc(&x);
    printf("x is now: %d and the pointer says %d \n", x, *ip);

    //memory allocation
    int size = 5;
    int *v = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        v[i] = 10;
    }
    for(int i = 0; i<size; i++){
        printf("%d ", v[i]);
    }
    size = 10;
    v = realloc(v, sizeof(int) * size);
    for(int i = 5; i<size; i++){
        v[i] = 20;
    }
    for(int i = 5; i<size; i++){
        printf("%d ", v[i]);
    }
    free(v);

    return 0;
}