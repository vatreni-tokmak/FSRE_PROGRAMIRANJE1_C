#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int uvjetPrekida(char **niz, int velicina){
    int razlika = abs((int)(*niz)[velicina - 2] - (int)(*niz)[velicina - 3]);
    int zadnjiUneseni = (*niz)[velicina - 1];

    return zadnjiUneseni == razlika;
}

void brojParnihZnamenki(char **niz, int velicina, int **brojParnih){
    
    for(int i = 0; i < velicina; i++){
        int temp = (int)(*niz)[i];
        while(temp > 0){
            int x = temp % 10;
            if(x % 2 == 0){
                (*brojParnih)[i]++;
            }
            temp /= 10;
        }
    }
}

void ispis(char **niz, int **brojParnih, int velicina){
    for(int i = 0; i < velicina; i++){
        if((*brojParnih)[i] >= 2){
            printf("%c, ASCII - %d, Broj parnih znamenki - %d\n", (*niz)[i], (*niz)[i], (*brojParnih)[i]);
        }
    }
}

int main(){
    char c;
    char *niz = NULL;
    int n = 0;

    int *brParnih = NULL;

    do{
        printf("Unesite znak: ");
        scanf(" %c", &c);

        niz = realloc(niz, (n + 1) * sizeof(char));
        niz[n] = c;
        n++;
    }while(!uvjetPrekida(&niz, n));


    brParnih = calloc(n, sizeof(int));
    brojParnihZnamenki(&niz, n, &brParnih);
    ispis(&niz, &brParnih, n);

    return 0;
}