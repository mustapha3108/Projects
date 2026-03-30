#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double now() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

//tri bull
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

//tri bull optimisé
void optbull(int *vec, int n){
    int stop = 0;
    int m = n-1;
    while(stop==0){
        int swap = 0;
        for(int i=0; i<m; i++){
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

//tri gnome
void gnome(int *vec, int n){
    int i = 0;
    int temp;
    while (i<n-1){
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


//tri par distribution
int cle(int x, int i) {
    while (i-- > 0)
        x /= 10;
    return x % 10;
}

void TriAux(int *T, int n, int i) {
    int count[10] = {0};
    int *output = malloc(n * sizeof(int));

    for (int j = 0; j < n; j++) {
        int d = cle(T[j], i);
        count[d]++;
    }

    for (int d = 1; d < 10; d++)
        count[d] += count[d - 1];

    for (int j = n - 1; j >= 0; j--) {
        int d = cle(T[j], i);
        output[count[d] - 1] = T[j];
        count[d]--;
    }

    for (int j = 0; j < n; j++)
        T[j] = output[j];

    free(output);
}

void TriBase(int *T, int n, int k) {
    for (int i = 0; i < k; i++)
        TriAux(T, n, i);
}

//tri par tas
void heapSort(int *arr, int n) {
    void heapify(int *arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

//tri rapid
void quickSort(int *arr, int n) {
    int partition(int *arr, int n) {
        if (n <= 1) return 0; // Guard against arrays with 0 or 1 elements
        int pivot_index = rand() % n;
        int temp_pivot = arr[pivot_index];
        arr[pivot_index] = arr[n - 1];
        arr[n - 1] = temp_pivot;

        int pivot = arr[n - 1];
        int i = -1;

        for (int j = 0; j < n - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        int tmp = arr[i + 1];
        arr[i + 1] = arr[n - 1];
        arr[n - 1] = tmp;

        return i + 1;
    }
    if (n < 2)
        return;

    int pi = partition(arr, n);
    quickSort(arr, pi);
    quickSort(arr + pi + 1, n - pi - 1);
}

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

int numDigits(int x) {
    if (x == 0) return 1;
    int count = 0;
    while (x != 0) {
        x /= 10;
        count++;
    }
    return count;
}



int main(){

    FILE *bat = fopen("heavyresults.txt", "w");
    int size[] = { 1000, 50000, 100000, 200000, 400000, 800000, 16000000, 32000000, 64000000, 128000000, 256000000, 512000000, 1024000000};

    for (int i = 0; i < 13; i++)
    {
        fprintf(bat, "----------size: %d \n", size[i]);

        for (int order = 0; order < 3; order++)
        {

            fprintf(bat, "order: %d \n", order);

            int *number = malloc(sizeof(int)*size[i]);
            if (number == NULL) {
                fprintf(stderr, "Failed to allocate memory for size %d\n", size[i]);
                continue;
            }
            reset(number, order, size[i]);
            double t1 , t2;
            /*
            t1 = now();
            quickSort(number, size[i]);
            t2 = now();
            fprintf(bat, "quicksort: %.8f \n", t2 - t1);
            reset(number, order, size[i]);

            t1 = now();
            heapSort(number, size[i]);
            t2 = now();
            fprintf(bat, "heapsort: %.8f \n", t2 - t1);
            reset(number, order, size[i]);

            int digits = numDigits(size[i]);
            t1 = now();
            TriBase(number, size[i], digits);
            t2 = now();
            fprintf(bat, "destribution: %.8f \n", t2 - t1);
            reset(number, order, size[i]);
            

            t1 = now();
            bull(number, size[i]);
            t2 = now();
            fprintf(bat, "bull: %.8f \n", t2 - t1);
            reset(number, order, size[i]);
            */
            t1 = now();
            optbull(number, size[i]);
            t2 = now();
            fprintf(bat, "optbull: %.8f \n", t2 - t1);
            reset(number, order, size[i]);
/*
            t1 = now();
            gnome(number, size[i]);
            t2 = now();
            fprintf(bat, "gnome: %.8f \n \n \n", t2 - t1);
*/  
            
            fflush(bat);
            free(number);

        }

        printf("%d done\n", size[i]);
    }

    fclose(bat);
    return 0;
}