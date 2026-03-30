#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double now() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

void matrixmulti(int n, int **m1, int **m2, int **res){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res[i][j] = 0;
            for (int k = 0; k < n; k++){
                res[i][j] = res[i][j] + m1[i][k] * m2[k][j];
            }
        }
    }

}


int main(){

    while (1)
    {
    
    //data creation
    int n;
    printf("donnez la taille de la matrice: ");
    scanf("%d", &n);

    int **m1 = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        m1[i] = malloc(n * sizeof(int));
        for (int j = 0; j< n; j++){
            m1[i][j] = rand() % (n*10 +1);
        }
        
    }

    int **m2 = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        m2[i] = malloc(n * sizeof(int));
        for (int j = 0; j< n; j++){
            m2[i][j] = rand() % (n*10 +1);
        }
    }

    int **res = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        res[i] = malloc(n * sizeof(int));
    }

    //executing the function with benchmarls
    double t0 = now();
    matrixmulti(n, m1, m2, res);
    double t1 = now();

    //print out results
    FILE* fm1 = fopen("m1.txt", "w");
    FILE* fm2 = fopen("m2.txt", "w");
    FILE* fres = fopen("res.txt", "w");
    FILE* ftime = fopen("time.txt", "a");


    //printf("-----matrice 1-----\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fprintf(fm1, "%d ", m1[i][j]);
        }
        fprintf(fm1, "\n");
    }

    //printf("-----matrice 2-----\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fprintf(fm2, "%d ", m2[i][j]);
        }
        fprintf(fm2, "\n");
    }

    //printf("-----result-----\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fprintf(fres, "%d ", res[i][j]);
        }
        fprintf(fres, "\n");
    }
    

    // free matrix memory
    for (int i = 0; i < n; i++) free(m1[i]);
    free(m1);
    for (int i = 0; i < n; i++) free(m2[i]);
    free(m2);
    for (int i = 0; i < n; i++) free(res[i]);
    free(res);

    printf("Execution time: %.6f seconds\n", t1 - t0);
    fprintf(ftime, "%d -> %.6f \n", n, t1-t0);

    fclose(fm1); fclose(fm2); fclose(fres); fclose(ftime);

    }

    return 0;
}



/*
me : test | redaction
wail : données | redaction
razika : code | donnée
ikram : code | test


me :  redaction
wail : données 
razika : code 
ikram : test

*/