#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindrom(char niz[], int pocetak, int kraj){
    if(pocetak >= kraj){
        return 1;
    }

    if(niz[pocetak] != niz[kraj]){
        return 0;
    }

    return palindrom(niz, pocetak + 1, kraj - 1);
}


int main(){

    char trenutni;
    char niz[30];
    int i = 0;

    while(i < 30){
        printf("Unesite slovo: ");
        scanf(" %c", &trenutni);

        if(!isalpha(trenutni)){
            break;
        }

        niz[i] = trenutni;
        i++;
    }

    if(palindrom(niz, 0, i - 1)){
        printf("Unesena slova tvore palindrom.\n");
    }else{
        printf("Unesena slova ne tvore palindrom.\n");
    }

    return 0;
}