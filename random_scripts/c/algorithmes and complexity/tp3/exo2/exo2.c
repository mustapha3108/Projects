#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double now() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

void sousMat1(int **mb, int **ms, int n1, int n2){

    int found = 0; int skip = 0;
    for (int i = 0; i < n1-n2; i++){
        for (int j = 0; j < n1-n2; j++){
            if (mb[i][j] == ms[0][0]){
                found = 1;
                skip = 0;
                for (int k = 0; k < n2; k++){
                    for (int kk = 0; kk < n2; kk++){
                        if (mb[i+k][j+kk] != ms[k][kk]){
                            skip = 1;
                            found = 0;
                            break;
                        }   
                    } 
                    if (skip == 1) break;
                }               
            }  
            if(found == 1 ){
                printf("MATRIX FOUND\n");
                return;
            }         
        }       
    }  
    if (found == 0) printf("matrix NOT found\n");
}

void sousMat2(int **mb, int **ms, int n1, int n2){

    int found = 0; int skip = 0; int start; int finish;
    for (int i = 0; i < n1-n2; i++){
        if(mb[i][n1/2] > ms[0][0]){
            start = 0; finish = n1/2 - 1;
        }else if (mb[i][n1/2] < ms[0][0]){
            start = n1/2 + 1;
            finish = n1-n2;
            }else if(mb[i][n1/2] == ms[0][0]){
                found = 1;
                skip = 0;
                for (int k = 0; k < n2; k++){
                    for (int kk = 0; kk < n2; kk++){
                        if (mb[i+k][n1/2 + kk] != ms[k][kk]){
                            skip = 1;
                            found = 0;
                            break;
                        }   
                    } 
                    if (skip == 1) break;
                }                
            }
        if(found == 1 ){
            printf("MATRIX FOUND\n");
            return;
        }
        else{     
            for (int j = start; j < finish; j++){
                if (mb[i][j] == ms[0][0]){
                    found = 1;
                    skip = 0;
                    for (int k = 0; k < n2; k++){
                        for (int kk = 0; kk < n2; kk++){
                            if (mb[i+k][j+kk] != ms[k][kk]){
                                skip = 1;
                                found = 0;
                                break;
                            }   
                        } 
                        if (skip == 1) break;
                    }               
                }  
            }
        }
        if(found == 1 ){
            printf("MATRIX FOUND\n");
            return;
        }
    }
    if (found == 0) printf("matrix NOT found\n");
}


int main(){

while (1)
{
    //basic data entry
    int n1, n2, tr;
    printf("donnez la taille de grande matrice: ");
    scanf("%d", &n1);
    printf("donnez la taille de la petitle matrice: ");
    scanf("%d", &n2);
    if (n2>n1/2){
        printf("n2 dit etre inferieur que n1/2");
        exit(1);
    }
    
    printf("appuiyer 1 pour trié et 2 pour non trié: ");
    scanf("%d", &tr);
    if (tr != 1 && tr != 2){
        printf("vous devez apuyer 1 ou 2");
        exit(1);
    }
    
    //creating the data
    int **mb = malloc(n1 * sizeof(int*));
    for (int i = 0; i < n1; i++) {
        mb[i] = malloc(n1 * sizeof(int));
        for (int j = 0; j< n1; j++){
            if(tr==2) mb[i][j] = rand() % (100);
            else {
                if(j==0) mb[i][j] = rand() % 10;
                else mb[i][j] =  mb[i][j-1] + rand() % 10;
            }
        }
    }

    int **ms = malloc(n2 * sizeof(int*));
    for (int i = 0; i < n2; i++) {
        ms[i] = malloc(n2 * sizeof(int));
        for (int j = 0; j< n2; j++){
            ms[i][j] = mb[n1/2 + i][n1/2 + j];
        }
    }

    double t1;
    double t2;


    if (tr==2){
        t1 = now();
        sousMat1(mb, ms, n1, n2);
        t2 = now();
    }
    else{
        t1 = now();
        sousMat2(mb, ms, n1, n2);
        t2 = now();
    }


    FILE* fmb = fopen("mb.txt", "w");
    FILE* fms = fopen("ms.txt", "w");
    FILE* ftime = fopen("time.txt", "a");


    //printf("matrice big\n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            fprintf(fmb,"%d  ", mb[i][j]);
        }
        fprintf(fmb,"\n");
        
    }
    //printf("matrice small\n");
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            fprintf(fms,"%d  ", ms[i][j]);
        }
        fprintf(fms,"\n");
        
    }
    
    for (int i = 0; i < n1; i++) free(mb[i]);
    free(mb);
    for (int i = 0; i < n2; i++) free(ms[i]);
    free(ms);

   printf("Execution time: %.6f seconds\n", t2 - t1);
   fprintf(ftime, "%d and %d and %d -> %.6f \n", n1, n2, tr, t2-t1);
   fclose(fmb); fclose(fms); fclose(ftime);
}
    return 0;
}