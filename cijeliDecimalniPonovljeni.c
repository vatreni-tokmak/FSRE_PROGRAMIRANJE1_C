#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EPS 1e-4


int main(){

    double unos;
    double *brojevi = NULL;
    double *cijeli = NULL;
    double *decimalni = NULL;
    int ponavljanje = 0;
    int i = 0;
    
    while(!ponavljanje){
        printf("Unesite broj: ");
        scanf("%lf", &unos);

        brojevi = realloc(brojevi, (i + 1) * sizeof(double));
        brojevi[i] = unos;
        
        cijeli = realloc(cijeli, (i + 1) * sizeof(double));
        decimalni = realloc(decimalni, (i + 1) * sizeof(double));

        decimalni[i] = modf(unos, &cijeli[i]);

        if(i > 0){
            int cijeliPostoji = 0;
            int decimalniPostoji = 0;

            for(int j = 0; j < i; j++){
                if(fabs(cijeli[i]-cijeli[j]) < EPS) cijeliPostoji = 1;
                if(fabs(decimalni[i]-decimalni[j]) < EPS) decimalniPostoji = 1;

            }
            if(cijeliPostoji && decimalniPostoji) ponavljanje = 1;

            if(ponavljanje) break;
        }
        i++;
    }

    for(int k = 0; k < i; k++){
        if((int)cijeli[k] % 2 != 0){
            printf("%lf ", brojevi[k]);
        }
    }
    
    free(brojevi);
    free(cijeli);
    free(decimalni);

    return 0;
}
