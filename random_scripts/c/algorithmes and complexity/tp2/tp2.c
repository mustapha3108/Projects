#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
/*
double get_time() {
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / freq.QuadPart;
}
*/
double get_time()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
} /*linuuuuuuuuuuuuuux*/

int Rechelet_TabNonTries(int t[], int n, int v){
    int s = 0;
    int nonexist = 1;
    /*clock_t debut, fin;
    double temps;
    debut = clock(); */
    while ((s < n) && nonexist)
    {
        if (t[s] == v) nonexist = 0;
        else  s++;
    }

    /*fin = clock();*/ // Fin du temps

    // Calcul du temps d�ex�cution en secondes
    return (nonexist ? 0 : 1);
    }

int rechElets_TabTries(int t[], int n, int v){
int s = 0;
    int nonexist = 1;


    while ((s < n) && nonexist  )
    {
        if (t[s] == v) nonexist = 0;
       

        

    
        else if (t[s]>v) break;
              else s++;
        
    }

     // Fin du temps

    // Calcul du temps d�ex�cution en secondes





    return (nonexist ? 0 : 1);
    }
int rechElets_Dicho(int t[], int n, int v){
    int nonexist = 1;
    int debutt = 0;
    int fint = n - 1;
    int mid;

    // Start time

    while (debutt <= fint && nonexist)
    {
        mid = (debutt + fint) / 2;

        if (t[mid] == v)
            nonexist = 0;          // found
        else if (t[mid] < v)
            debutt = mid + 1;      // search right
        else
            fint = mid - 1;        // search left
    }

    return (nonexist ? 0 : 1);
}

void MaxEtMinA(int t[], int n, int *min, int *max, int *comparaisons1)
{
    *min = t[0];
    *max = t[0];
    *comparaisons1 = 0;  // compteur de comparaisons

    for (int i = 1; i < n; i++)
    {
        (*comparaisons1)++;            // comparaison pour min
        if (t[i] < *min)
            *min = t[i];

        (*comparaisons1)++;            // comparaison pour max
        if (t[i] > *max)
            *max = t[i];
    }
}
void MaxEtMinAeffwa(int t[], int n, int *min, int *max, int *comparaisons2)
{
    int p;
    *comparaisons2 = 0;  // compteur de comparaisons

    for (int i = 0; i < n; i++)
    {
                  // comparaison pour min
        if (t[i] > t[i+1])
            p = t[i];
            t[i]=t[i+1];
            t[i+1]=p;
            (*comparaisons2)++;
            i=i+2;



    }
    for (int i =0 ; i < n; i=i+4)
    {
        if(t[i] > t[i+2])
            *max = t[i];
            (*comparaisons2)++;
    }
     for (int i =1 ; i < n; i=i+4)
    {
        if(t[i] < t[i+2])
            *min = t[i];
            (*comparaisons2)++;
    }
}
void MaxEtMinB(int t[], int n, int *min, int *max, int *comparaisons2)
{
    *comparaisons2 = 0;

    int grands[n / 2 + 1];
    int petits[n / 2 + 1];
    int g = 0, p = 0;


    for (int i = 0; i < n - 1; i += 2)
    {
        (*comparaisons2)++;
        if (t[i] > t[i + 1]) {
            grands[g++] = t[i];
            petits[p++] = t[i + 1];
        } else {
            grands[g++] = t[i + 1];
            petits[p++] = t[i];
        }
    }


    if (n % 2 != 0) {
        grands[g++] = t[n - 1];
        petits[p++] = t[n - 1];
    }


    *max = grands[0];
    for (int i = 1; i < g; i++) {
        (*comparaisons2)++;
        if (grands[i] > *max)
            *max = grands[i];
    }


    *min = petits[0];
    for (int i = 1; i < p; i++) {
        (*comparaisons2)++;
        if (petits[i] < *min)
            *min = petits[i];
    }
}
void MaxEtMinB_SameArray(int t[], int n, int *min, int *max, int *comparaisons2)
{
    *comparaisons2 = 0;
    int half = n / 2;
    int g = 0, p = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        (*comparaisons2)++;
        if (t[i] > t[i + 1])
            {
            t[p++] = t[i + 1];
            t[half + g++] = t[i];
            }
        else
            {
            t[p++] = t[i];
            t[half + g++] = t[i + 1];
            }
    }
    if (n % 2 != 0)
        {
        t[p++] = t[n - 1];
        t[half + g++] = t[n - 1];
        }
    *min = t[0];
    for (int i = 1; i < half; i++)
        {
        (*comparaisons2)++;
        if (t[i] < *min)
            *min = t[i];
        }
    *max = t[half];
    for (int i = half + 1; i < n; i++)
        {
        (*comparaisons2)++;
        if (t[i] > *max)
            *max = t[i];
        }
}


int main()
{
    srand(time(NULL));
    int continuer = 1;

    while (continuer) {
    int n, v1, v2, v3, pire;
    double debut, fin, temps;

    printf("Donnez la taille n : ");
    scanf("%d", &n);

    int *t1 = malloc(n * sizeof(int));
    int *t2 = malloc(n * sizeof(int));
    int *t3 = malloc(n * sizeof(int));
    if (!t1 || !t2 || !t3)
    {
        printf("Erreur d�allocation m�moire !\n");
        return 1;
    }

    // Remplissage
    for (int i = 0; i < n; i++){
        t1[i] = rand() % (n * 10);
    } // Non tri�
    for (int i = 0; i < n; i++)
        t2[i] = i;
    for (int i = 0; i < n; i++)
        t3[i] = i;

    printf("Choisissez le cas d�etude (1 = pire, 2 = meilleur) : ");
    scanf("%d", &pire);

    if (pire == 1)
    {
        //SERIOUSLY NEGGA???? SERIOUSLY, ARE YOU FUCKING KIDDING ME 
        v1 =  -1;//n * 10 + 1;
        v2 = -1;//n * 10 + 1;
        v3 = -1;//n * 10 + 1;
        printf("\n=== PIRE CAS ===\n");
    }
    else
    {   int debut = 0;
        int fin = n - 1;
        int mid = (debut + fin) / 2;
        v1 = t1[0];
        v2 = t2[0];
        v3 = t3[mid];
        printf("\n=== MEILLEUR CAS ===\n");
    }

    // --- Non tri� ---
    debut = get_time();
    int found1 = Rechelet_TabNonTries(t1, n, v1);
    fin = get_time();
    temps = fin - debut;
    printf("EletsNonTries : %s | Temps = %.9f s\n", found1 ? "Trouve" : "Absent", temps);

    // --- Tri� s�quentiel ---
    debut = get_time();
    int found2 = rechElets_TabTries(t2, n, v2);
    fin = get_time();
    temps = fin - debut;
    printf("EletsTries : %s | Temps = %.9f s\n", found2 ? "Trouve" : "Absent", temps);

    // --- Dichotomique ---
    debut = get_time();
    int found3 = rechElets_Dicho(t3, n, v3);
    fin = get_time();
    temps = fin - debut;
    printf("EletsTriesDicho : %s | Temps = %.9f s\n", found3 ? "Trouve" : "Absent", temps);

    free(t1);
    free(t2);
    free(t3);
     }

    printf("\nProgramme termin�. Merci d�avoir test� !\n");
    return 0;

}
