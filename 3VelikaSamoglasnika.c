#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* unos(int *velicina){

    char *niz = NULL;
    char znak;
    int brVelikih = 0;
    int brSamoglasnika = 0;
    int n = 0;

    while(brVelikih < 10 && brSamoglasnika < 3){
        printf("Unesite znak: ");
        scanf(" %c", &znak);

        niz = (char*)realloc(niz, (n+1) * sizeof(char));
        niz[n] = znak;
        n++;

        if(isupper(znak)){
            brVelikih++;
        }

        if(unos == 'A' || unos == 'E' || unos == 'I' || unos == 'O' || unos == 'U'){
            brSamoglasnika++;
        }
    }

    *velicina = n;

    return niz;
}

int razlika(char *niz, int velicinaNiza, int *najmanji, int *najveci, char *najcesceSlovo, int *maxFrekvencija){

    *najveci = niz[0];
    *najmanji = niz[0];
    
    for(int i = 0; i < velicinaNiza; i++){

        if(niz[i] > *najveci) *najveci = niz[i];
        if(niz[i] < *najmanji) *najmanji = niz[i];
    }

    int razlikaASCII = *najveci - *najmanji;

    int frekvencija[256] = {0};

    for(int i = 0; i < velicinaNiza; i++){
        if(isalpha(niz[i])){
            frekvencija[(int)niz[i]]++;
        }
    }
    
    *najcesceSlovo = '\0';
    *maxFrekvencija = 0;

    for(int i = 0; i < 256; i++){
        if(frekvencija[i] > *maxFrekvencija){
            *maxFrekvencija = frekvencija[i];
            *najcesceSlovo = (char)i;
        }
    }

    return razlikaASCII;    
}

void ispis(char *niz, int velicinaNiza, int razlikaASCII, int najveci, int najmanji, char najcesceSlovo, int maxFrekvencija){
    printf("Razlika najveceg i najmanjeg ASCII: %d.\n", razlikaASCII);
    printf("Najcesce slovo je %c, pojavljuje se %d puta. \n", najcesceSlovo, maxFrekvencija);
}

int main(){
    int velicina;
    char *niz;
    int razlikaASCII;
    int najveci, najmanji;
    char najcesceSlovo;
    int maxFrekvencija;

    niz = unos(&velicina);

    razlikaASCII = razlika(niz, velicina, &najveci, &najveci, &najcesceSlovo, &maxFrekvencija);
    
    ispis(niz, velicina, razlikaASCII, najveci, najmanji, najcesceSlovo, maxFrekvencija);

    return 0;
}