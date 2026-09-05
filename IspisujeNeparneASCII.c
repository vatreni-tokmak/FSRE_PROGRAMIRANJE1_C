#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int uvjetPrekida(char c){
    if(c % 11 == 0) return 1;
    return 0;
}

void provjeraZnamenki(char **niz, int velicina, char **odgovarajuciASCII, int *velicinaPasu){
    
    for(int i = 0; i < velicina; i++){
        int temp = (int)(*niz)[i];

        while(temp > 0){
            int znamenka = temp % 10;
            int sveNeparne = 1;
            if(znamenka % 2 == 0){
                sveNeparne = 0;
                break;
            }
            temp /= 10;
            if(sveNeparne){
                *odgovarajuciASCII = realloc(*odgovarajuciASCII, ((*velicinaPasu) + 1) * sizeof(char));
                (*odgovarajuciASCII)[*velicinaPasu] = (*niz)[i];
                (*velicinaPasu)++;
            }
        }
    }
}

void ispis(char **odgovarajuciASCII, int velicinaOdgovarajucih){
    for(int i = 0; i < velicinaOdgovarajucih; i++){
        printf("%c [%d]\n", (*odgovarajuciASCII)[i], (*odgovarajuciASCII)[i]);
    }
}

int main(){

    char c;
    char *niz = NULL;
    char *pasu = NULL;
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