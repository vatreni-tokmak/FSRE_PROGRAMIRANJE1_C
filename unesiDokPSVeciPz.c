#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double prosjekPZ = 0;
    double prosjekUK = 0;
    int zbroj = 0;
    int uneseni;
    int *niz = NULL;
    int i = 0;

    while(prosjekUK <= prosjekPZ){
        printf("Unesi broj: ");
        scanf("%d", &uneseni);

        niz = realloc(niz, (i + 1) * sizeof(int));
        niz[i] = uneseni;

        zbroj += niz[i];

        prosjekPZ = (niz[0] + niz[i]) / 2.0;
        
        if(i > 1){
            prosjekUK =(double)zbroj / (i+1);
        }

        i++;
    }


    for (int j = 0; j < i; j++) {

    int jeProst = 1;

    if (niz[j] < 2) {
        jeProst = 0;
    }

    for (int k = 2; k <= sqrt(niz[j]); k++) {
        if (niz[j] % k == 0) {
            jeProst = 0;
            break;
        }
    }

    if (jeProst) { 
        printf("%d, Prost\n", niz[j]);
    }
}



    return 0;
}