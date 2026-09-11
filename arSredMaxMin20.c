#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void unos(float niz[], int n){
    
    printf("Unesite 20 brojeva: ");
    for(int i = 0; i < n; i++){
        printf("%d. : ", i+1);
        scanf("%f", &niz[i]);
    }

}

float obrada(float niz[], int n){

    float najmanji = niz[0];
    float najveci = niz[0];

    for(int i = 0; i < n; i++){
        if(niz[i] < najmanji) najmanji = niz[i];
        if(niz[i] > najveci) najveci = niz[i];
    }

    float arSred = (najmanji + najveci) / 2.0;

    return arSred;
}

void ispis(float niz[], int n){
    for(int i = 0; i < 20; i++){
        int cijeliDio = (int)niz[i];
        if(cijeliDio % 2 != 0) printf("%.2f ", niz[i]);
    }
}

int main(){

    float niz[20];
    int n = 20;
    float arSredina;

    unos(niz, n);
    arSredina = obrada(niz, n);
    printf("%.2f je aritmeticka sredina najveceg i najmanjeg", arSredina);
    ispis(niz, n);
}