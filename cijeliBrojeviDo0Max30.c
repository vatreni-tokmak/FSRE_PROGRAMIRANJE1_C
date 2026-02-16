#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int zbrajanje(int niz[], int pocetak, int kraj){

    int suma = 0;
    if(pocetak >= kraj){
        return niz[pocetak];
    }

    suma = niz[pocetak] + niz[kraj];

    return suma + zbrajanje(niz, pocetak + 1, kraj -1);
}

int zbrojZnam(int suma){

    int sumaZnam = 0;
    
    if(suma == 0) return sumaZnam;

    sumaZnam += (suma % 10);

    return sumaZnam + zbrojZnam(suma / 10);
}

int main(){
    int niz[30];
    int n = 0;
    int broj;
    int zbrojNiza, zbrojZnamenki;

    for(int i = 0; i < 30; i++){
        printf("Unesite cijeli broj: ");
        scanf("%d", &broj);

        if(broj == 0) break;

        niz[i] = broj;
        n = i;
    }

    zbrojNiza = zbrajanje(niz, 0, n);
    zbrojZnamenki = zbrojZnam(zbrojNiza);

    printf("Zbroj svih znamenaka je %d, a zbroj znamenaka tog broja je %d.\n", zbrojNiza, zbrojZnamenki);
}