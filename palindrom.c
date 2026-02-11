#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX  100

int jeLiPalindrom(char unos[], int pocetak, int kraj){

    if(pocetak >= kraj){
        return 1;
    }

    if(unos[pocetak] != unos[kraj]){
        return 0;
    }

    return jeLiPalindrom(unos, pocetak + 1, kraj - 1);
}

int main(){
    char unos[MAX];
    char slova[MAX];

    int pozicija = 0;
    int brojSlova = 0;

    while(pozicija <= MAX){
        char trenutni;
        printf("Unesite znak: \n");
        scanf(" %c", &trenutni);
        unos[pozicija] = trenutni;
        pozicija++;

        if(isalpha(trenutni)){
            slova[brojSlova] = tolower(trenutni);
            brojSlova++;
        }

        slova[brojSlova] = '\0';

        if(brojSlova > 2 && jeLiPalindrom(slova, 0, brojSlova - 1)){
            printf("\nRazlog prestanka: PALINDROM");
            break;
        }
        
    }  

    if(pozicija >= MAX){
        printf("\nRazlog prestanla: MAX");
    }

    unos[pozicija] = '\0';
    printf("Uneseno: %s\n", unos);
    printf("Slova %s", slova);


    return 0;
}