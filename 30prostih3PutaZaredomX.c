#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int obradaPodataka(int prosti[], int velicinaProsti, int *aritmeticka){
    int suma = 0;
    int aritSred;

    for(int i = 0; i < velicinaProsti; i++){
        suma += prosti[i];
    }

    aritSred = suma / velicinaProsti;

    *aritmeticka = aritSred;

    if(aritSred < 2) return 0;
    if(aritSred == 2) return 1;
    if(aritSred % 2 == 0) return 0;

    int limit = sqrt(aritSred);
    for(int i = 3; i < limit; i += 2){
        if(aritSred % i == 0){
            return 1;
        }
    }

    return 1;
}

int main(){

    int unos;
    int prosti[30];
    int *uneseni = NULL;
    int x = 0;
    int n = 0;
    int aritmeticka;

    while(1){
        printf("Unesite prost broj: ");
        scanf("%d", &unos);

        uneseni = (int*)realloc(uneseni, (x + 1) * sizeof(int));
        uneseni[x] = unos;
        x++;

        if(x > 1){
            if(uneseni[x - 3] == uneseni[x - 2] && uneseni[x - 2] == uneseni[x - 1]){
                break;
            }
        }

        if(unos <= 2){
            prosti[n] = unos;
            n++;
        }

        int jeProst = 1;
        int limit = sqrt(unos);
        for(int j = 3; j < limit; j += 2){
            if(unos % j == 0){
                jeProst = 0;
                continue;
            }   
        }

        if(jeProst){
            prosti[n] = unos;
            n++;
        }

        if(n == 30) break;
    }

    if(obradaPodataka(prosti, n, &aritmeticka)){
        printf("Aritmeticka sredina je %d sto je prost broj.", aritmeticka);
    }

    if(!obradaPodataka(prosti, n, &aritmeticka)){
        printf("Aritmeticka sredina je %d sto nije prost broj.", aritmeticka);
    }
    return 0;
}