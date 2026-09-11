#include <stdio.h>
#include <stdlib.h>

void brojDjelitelja(int **niz, int velicina, int **djelitelji){

    for(int a = 0; a < velicina; a++){
        for(int b = 1; b <= (*niz)[a]; b++){
            if((*niz)[a] % b == 0){
                (*djelitelji)[a]++;
            }
        }
    }
}


int main(){
    int *niz = NULL;
    int broj;
    int *umnozakZnam = NULL;
    int *brojDjeliteljakis = NULL;

    int i = 0;
    while(1){
        printf("Unesite broj: ");
        scanf("%d", &broj);

        brojDjeliteljakis = realloc(brojDjeliteljakis, (i + 1) * sizeof(int));
        umnozakZnam = realloc(umnozakZnam, (i + 1) * sizeof(int));
        niz = realloc(niz, (i + 1) * sizeof(int));
        niz[i] = broj;
        i++;

        int temp = broj;
        int umnozak = 1;
        while(temp > 0){
            umnozak *= temp % 10;
            temp /= 10;
        }

        umnozakZnam[i - 1] = umnozak;

        int poklapaSe = 0;
        for(int m = 0; m < i - 1; m++){
            if(broj == umnozakZnam[m]){
                poklapaSe = 1;
                break;
            }
        }
        
        if(poklapaSe) break;
    }
       

    brojDjelitelja(&niz, i, &brojDjeliteljakis);

    //ispis djelitelja i to
    for(int j = 0; j < i; j++){
        printf("Broj %d ima %d djelitelja.\n", niz[j], brojDjeliteljakis[j]);
    }

    int max = 0;
    int brMax = 0;
    for(int a = 0; a < i - 1; a++){
        if(brojDjeliteljakis[a] > max){
            max = brojDjeliteljakis[a];
            brMax = niz[a];
        }
    }

    printf("Broj %d ima najvise djelitelja - %d. To su: ", brMax, max);
    for(int l = 1; l <= brMax; l++){
        if(brMax % l == 0){
            printf("%d ", l);
        }
    }
    return 0;
}