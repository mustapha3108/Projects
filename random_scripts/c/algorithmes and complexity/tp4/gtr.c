#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bull(int *vec, int n){
    int stop = 0;
    while(stop==0){
        int swap = 0;
        for(int i=0; i<n-1; i++){
            if(vec[i]>vec[i+1]){
                int y = vec[i];
                vec[i]=vec[i+1];
                vec[i+1] = y;
                swap = 1;
            }
        }
        if(swap == 0) stop = 1;
    }
}

void optbull(int *vec, int n){
    int stop = 0;
    int m = n-1;
    while(stop==0){
        int swap = 0;
        for(int i=0; i<n-1; i++){
            if(vec[i]>vec[i+1]){
                int y = vec[i];
                vec[i]=vec[i+1];
                vec[i+1] = y;
                swap = 1;
            }
        }
        m=m-1;
        if(swap == 0) stop = 1;
    }
}

void gnome(int *vec, int n){
    int i = 0;
    int temp;
    while (i<n){
        if(vec[i]<=vec[i+1]){
            i++;
        }else{
            temp = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = temp;
            if(i>0) i--;
        }
    }
}


int main(){
    int n = 2000;
    int *vecbull = malloc(sizeof(int)*n);
    int *vecoptbull = malloc(sizeof(int)*n);
    int *vecgnome = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        vecbull[i] = rand() % 1000;
        vecoptbull[i] = vecbull[i];
        vecgnome[i] = vecbull[i];
    }

    bull(vecbull, n);

    optbull(vecoptbull, n);

    gnome(vecgnome, n);

    free(vecbull); free(vecoptbull); free(vecgnome);
    
    return 0;
}