#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void unos(int **niz, int *prosjek, int *velicina){

    int broj;
    int i = 0;
    int suma = 0;
    int aritSred;

    while(1){
        printf("PARDON MAJ FRENC al unesi broj: ");
        scanf("%d", &broj);

        *niz = realloc(*niz, (i + 1) * sizeof(int));
        (*niz)[i] = broj;
        i++;

        suma += broj;
        aritSred = suma / i;

        if(broj > aritSred) break;
    }

    *prosjek = aritSred;
    *velicina = i;
}

void statistika(int **niz, int *najveci, int *najmanji, int *prosjekMinMax, int velicina){
    int suma;
    int aritMinMax;
    int min = (*niz)[0];
    int max = (*niz)[0];

    for(int i = 0; i < velicina; i++){
        if((*niz)[i] > max) max = (*niz)[i];
        if((*niz)[i] < min) min = (*niz)[i];
    }

    suma = max + min;
    aritMinMax = suma / 2;

    *najmanji = min;
    *najveci = max;
    *prosjekMinMax = aritMinMax;
}

void ispis(int **niz, int velicina, int prosjekMinMax){

    printf("Brojevi manji od aritmeticke sredine najmanjeg i najveceg: \n");
    
    for(int i = 0; i < velicina; i++){
        if((*niz)[i] < prosjekMinMax) printf("%d\n", (*niz)[i]);
    }
}

int main(){

    int *niz = NULL;
    int najveci, najmanji, aritmetickaMinMax;
    int prosjek;
    int velicina = 0;

    unos(&niz, &prosjek, &velicina);
    
    statistika(&niz, &najveci, &najmanji, &aritmetickaMinMax, velicina);
    printf("Najmanji = %d\nNajveci = %d\nProsjekMinMax = %d\n", najmanji, najveci, aritmetickaMinMax);

    ispis(&niz, velicina, aritmetickaMinMax);

    return 0;
} 