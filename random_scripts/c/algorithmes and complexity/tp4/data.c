#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reset(int *arr, int order, int n){
    if(order == 0){
        for (int i = 0; i < n; i++){
            arr[i] = rand() % n;
        }
    }else if (order == 1)
    {
        for (int i = 0; i < n; i++){
            arr[i] = i;
        }
    }else if (order==2)
    {
        for (int i = 0; i < n; i++){
            arr[i] = n-i;
        }
    }
}

int main(){
    FILE *bat = fopen("data.txt", "w");

    int n = 100;
    int *arr = malloc(sizeof(int)*n);
    reset(arr, 0, n);
    for (int i = 0; i < n; i++){
        fprintf(bat, "%d ", arr[i]);
    }

    free(arr); fclose(bat);
    
    return 0;
}