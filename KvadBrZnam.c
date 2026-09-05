#include <stdio.h>
#include <stdlib.h>

int main(){

    int broj;
    int *niz = NULL;
    int max;
    
    int i = 0;
    do{
        printf("Unesite broj: ");
        scanf("%d", &broj);

        niz = realloc(niz, (i + 1) * sizeof(int));
        niz[i] = broj;
        i++;

        if(broj > max) max = broj;
    }while(i < max);

    int *zbrKvadZnamNiz = malloc(i * sizeof(int));
    int *brZnamNiz = malloc(i * sizeof(int));

    for(int j = 0; j < (i-1); j++){

        int zbrKvadZnam = 0;
        int brZnam = 0;
        int temp = niz[j];

        if(temp == 0) brZnam = 0;

        while(temp > 0){
            int ostatak = temp % 10;
            temp /= 10;
            zbrKvadZnam += ostatak * ostatak;
            brZnam++;
        }

        zbrKvadZnamNiz[j] = zbrKvadZnam;
        brZnamNiz[j] = brZnam;
    }

    for(int a = 0; a < i - 1; a++){
        for(int s = 0; s < i - 1 - a; s++){

            if(zbrKvadZnamNiz[s] < zbrKvadZnamNiz[s+1]){
                
                int t;
                t = zbrKvadZnamNiz[s]; zbrKvadZnamNiz[s] = zbrKvadZnamNiz[s+1]; zbrKvadZnamNiz[s+1] = t;
                t = brZnamNiz[s]; brZnamNiz[s] = brZnamNiz[s+1]; brZnamNiz[s+1] = t;
                t = niz[s]; niz[s] = niz[s+1]; niz[s+1] = t;
            }
        }
    }

    for(int j = 0; j < i; j++){
        if(zbrKvadZnamNiz[j] % brZnamNiz[j] == 0){
            printf("%d [%d, %d]\n", niz[j], zbrKvadZnamNiz[j], brZnamNiz[j]);
        }
    }

    free(niz);
    free(zbrKvadZnamNiz);
    free(brZnamNiz);

    return 0;
}