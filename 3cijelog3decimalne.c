#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    double broj;
    int cijeli;
    double decimalni, decimalniTri;
    int isti = 0;
    int razlika;
    double *validni = NULL;
    int n = 0;

    do{
        printf("Unesite broj: \n");
        scanf("%lf", &broj);

        cijeli = (int)broj;
        decimalni = modf(broj, &broj);

        decimalniTri = (int)(fabs(decimalni)*1000);

        razlika = abs(decimalni - cijeli);

        if(razlika == 0){
            isti = 1;
        }else{
            validni = (double*)realloc(validni, (n+1) * sizeof(double));
            validni[n] = broj;
        }

    }while(isti == 0);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(validni[i] < validni[j]){
                double temp = validni[i];
                validni[i] = validni[j];
                validni[j] = temp;
            }
        }
    }

    printf("Validni sortirani:");
    for(int i = 0; i < n; i++){
        printf("%lf ", validni[i]);
    }

    return 0;
}