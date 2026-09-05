#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int jeProst(int n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0) return 0;
    }
    return 1;
}

void unosPodataka(int niz[], int *x){
    int broj;
    int brojacNeProsth = 0;

    while(*x < 30){
        printf("Unesi prost broj: ");
        scanf("%d", &broj);

        if(jeProst(broj)){
            niz[*x] = broj;
            (*x)++;
            brojacNeProsth = 0;
        }

        if(!jeProst(broj)){
            brojacNeProsth++;
            if(brojacNeProsth == 3) break;
        }
    }
}

void obradaPodataka(int niz[], int *aritSred){
    int suma = 0;
    int brojac = 0;

    for(int i = 0; i < 30; i++){
        if(niz[i] != 0){
            suma += niz[i];
            brojac++;
        }
    }

    *aritSred = suma / brojac;

    if(jeProst(*aritSred)){
        printf("Aritmeticka sredina je prost broj.\n");
    } else {
        printf("Aritmeticka sredina nije prost broj.\n");
    }
}   

int main(){

    int niz[30] = {0};
    int aritSred, x;

    x = 0;
    
    unosPodataka(niz, &x);
    if(x == 30){
        obradaPodataka(niz, &aritSred);
        printf("Aritmeticka sredina prostih brojeva je: %d\n", aritSred);
    }else{
        printf("Nije unesen dovoljan broj prostih brojeva.\n");
    }

    return 0;
}