#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int *brojevi = NULL;
    int n = 0;
    int broj;
    int prosjekSvih, prosjekPrviZadnji;
    int suma = 0;


    while(1){
        printf("Unesite broj");
        scanf("%d", &broj);

        brojevi = (int*)realloc(brojevi, (n+1)*sizeof(int));
        brojevi[n] = broj;
        n++;

        suma += broj;

        if(n >= 2){
            prosjekPrviZadnji = (brojevi[0] + brojevi[n - 1]) / 2;

            prosjekSvih = suma / n;

            if(prosjekPrviZadnji > prosjekSvih){
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", brojevi[i]);
        if(brojevi[i] < 2 || brojevi[i] % 2 == 0){
            printf("NIJE PROST\n");
            continue;
        }

        if(brojevi[i] == 2){
            printf("PROST\n");
            continue;
        }

        int jeProst = 1;
        int limit = (int)sqrt(brojevi[i]);
        for(int j = 3; j <= limit; j += 2){
            if(brojevi[i] % j == 0){
                jeProst = 0;
                break;
            }
        }

        if(jeProst){
            printf("PROST\n");
        }else{
            printf("NIJE PROST\n");
        }
    }

    return 0;
}