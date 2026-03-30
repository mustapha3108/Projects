#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double now() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

// -----------------------
// tri bull
// -----------------------
void bull(long long *vec, long long n){
    int stop = 0;

    while(stop==0){
        int swap = 0;

        for(long long i=0; i<n-1; i++){
            if(vec[i] > vec[i+1]){
                long long y = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = y;
                swap = 1;
            }
        }
        if(swap == 0) stop = 1;
    }
}

// -----------------------
// tri bull optimisé
// -----------------------
void optbull(long long *vec, long long n){
    int stop = 0;
    long long m = n - 1;

    while(stop==0){
        int swap = 0;

        for(long long i=0; i < m; i++){
            if(vec[i] > vec[i+1]){
                long long y = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = y;
                swap = 1;
            }
        }

        m = m - 1;
        if(swap == 0) stop = 1;
    }
}

// -----------------------
// tri gnome
// -----------------------
void gnome(long long *vec, long long n){
    long long i = 0;
    long long temp;

    while (i < n - 1){
        if(vec[i] <= vec[i+1]){
            i++;
        } else {
            temp = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = temp;
            if(i > 0) i--;
        }
    }
}

// -----------------------
// tri par distribution
// -----------------------
long long cle(long long x, int i) {
    while (i-- > 0)
        x /= 10;
    return x % 10;
}

void TriAux(long long *T, long long n, int i) {
    long long count[10] = {0};
    long long *output = malloc(n * sizeof(long long));

    for (long long j = 0; j < n; j++) {
        long long d = cle(T[j], i);
        count[d]++;
    }

    for (long long d = 1; d < 10; d++)
        count[d] += count[d - 1];

    for (long long j = n - 1; j >= 0; j--) {
        long long d = cle(T[j], i);
        output[count[d] - 1] = T[j];
        count[d]--;
    }

    for (long long j = 0; j < n; j++)
        T[j] = output[j];

    free(output);
}

void TriBase(long long *T, long long n, int k) {
    for (int i = 0; i < k; i++)
        TriAux(T, n, i);
}

// -----------------------
// tri par tas
// -----------------------
void heapify(long long *arr, long long n, long long i) {
    long long largest = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        long long temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(long long *arr, long long n) {
    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (long long i = n - 1; i >= 0; i--) {
        long long temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// -----------------------
// tri rapide
// -----------------------
long long partition(long long *arr, long long n) {
    long long pivot = arr[n - 1];
    long long i = -1;

    for (long long j = 0; j < n - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            long long tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    long long tmp = arr[i + 1];
    arr[i + 1] = arr[n - 1];
    arr[n - 1] = tmp;

    return i + 1;
}

void quickSort(long long *arr, long long n) {
    if (n < 2)
        return;

    long long pi = partition(arr, n);
    quickSort(arr, pi);
    quickSort(arr + pi + 1, n - pi - 1);
}



int main(){

    long long size[] = {
    1000LL,
    50000LL,
    100000LL,
    200000LL,
    40000LL,
    800000LL,
    16000000LL,
    32000000LL,
    640000LL,
    128000000LL,
    256000000LL,
    512000000LL,
    1024000000LL,
    2048000000LL
    };


    int *number = malloc(sizeof(long long)*20);
    for (long long i = 0; i < 20; i++){
        number[i] = rand() % 1000;
        printf("%d ", number[i]);
    }
    printf("\n");


    quickSort(number, 20);
    printf("quicksort: ");
    for (long long i = 0; i < 20; i++){
        printf("%d ", number[i]);
    }
    printf("\n");
    for (long long i = 0; i < 20; i++){
        number[i] = rand() % 1000;
    }
    printf("\n");

    heapSort(number, 20);
    printf("heapsort: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", number[i]);
    }
    printf("\n");
    for (long long i = 0; i < 20; i++){
        number[i] = rand() % 1000;
    }
    printf("\n");

    TriBase(number, 20, 4);
    printf("tribase: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", number[i]);
    }
    printf("\n");

    bull(number, 20);
    printf("bull: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", number[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++){
        number[i] = rand() % 1000;
    }
    printf("\n");

    optbull(number, 20);
    printf("optbull: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", number[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++){
        number[i] = rand() % 1000;
    }
    printf("\n");

    gnome(number, 20);
    printf("gnome: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", number[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++){
        number[i] = rand() % 1000;
    }
    printf("\n");

    free(number);

    return 0;
}