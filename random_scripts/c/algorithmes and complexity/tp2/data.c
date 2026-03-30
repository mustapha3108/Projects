#include <stdio.h>



int main(){


    int n;
    FILE *filetri = fopen("tri.txt", "w");
    FILE *filepastri = fopen("pastri.txt", "w");

    printf("Donnez la taille n : ");
    scanf("%d", &n);

    int *t1 = malloc(n * sizeof(int));
    int *t2 = malloc(n * sizeof(int));
    if (!t1 || !t2 )
    {
        printf("Erreur d�allocation m�moire !\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        t1[i] = rand() % (n * 100);
        
        fprintf(filepastri, "%d\n", t1[i]);
    }

    for (int i = 0; i < n; i=i+2){
        t2[i] = i;

        fprintf(filetri, "%d\n", t2[i]);
    }
   
    fclose(filetri);
    fclose(filepastri);

    


    return 0;
}