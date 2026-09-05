#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int uvjetPrekida(char c){
    if((int)c == 4 || (int)c == 9 || (int)c == 25 || (int)c == 49 || (int)c == 121 || (int)c == 169) return 1;
    return 0;
}

void provjeraZnamenki(char **niz, int velicina, double **odgovarajuciASCII, int *velicinaPasu){
    
    for(int i = 0; i < velicina; i++){
        int temp = (int)(*niz)[i];
        int temp2 = temp;

        while(temp > 0){
            if(temp % 10 == 2 || temp % 10 == 4 || temp % 10 == 6){
                *odgovarajuciASCII = realloc(*odgovarajuciASCII, ((*velicinaPasu) + 1) * sizeof(double));
                (*odgovarajuciASCII)[*velicinaPasu] = temp2;
                (*velicinaPasu)++;
                break;
            }
            temp /= 10;
        }
    }
}

void ispis(double **odgovarajuciASCII, int velicinaOdgovarajucih){

    for(int i = 0; i < velicinaOdgovarajucih; i++){
        double korijen = sqrt((*odgovarajuciASCII)[i]);
        double cijeli = 0;
        double ostatak = modf(korijen, &cijeli);

        if(ostatak != 0){
            printf("Korijen nije cijeli broj.\n");
        }else{
            printf("%.0f\n", cijeli);
        }
    }
}

int main(){

    char c;
    char *niz = NULL;
    double *pasu = NULL;
    int veliPasu = 0;
    int n = 0;

    do{
        printf("Unesi znakijauuu: ");
        scanf(" %c", &c);

        niz = realloc(niz, (n + 1) * sizeof(char));
        niz[n] = c;
        n++;

    }while(!uvjetPrekida(c));

    //provjera ima li 2, 4 ili 6
    provjeraZnamenki(&niz, n, &pasu, &veliPasu);
    ispis(&pasu, veliPasu);

    return 0;
}