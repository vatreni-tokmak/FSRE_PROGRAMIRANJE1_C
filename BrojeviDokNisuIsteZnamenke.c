#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int broj;
    int *niz = NULL;
    
    int i = 0;
    while(1){
        printf("WAuaWauwW bRoj UneSi: ");
        scanf("%d", &broj);

        int temp = broj;
        int prva = temp % 10;
        int sveIste = 1;

        while(temp > 0){
           if(temp % 10 != prva){
            sveIste = 0;
            break;
           }
           temp /= 10;
        }
        
        if(sveIste) break;

        niz = realloc(niz, (i + 1) * sizeof(int));
        niz[i] = broj;
        i++;
    }

    int *nepBrojZnamenki = NULL;
    int *zbrojZnamenki = NULL;
    int *brojZnamenki = NULL;
    int vel = 0;

    for(int k = 0; k < i; k++){

        int temp = niz[k];
        int brZnamenki = 0;
        int suma = 0;

        while(temp > 0){
            suma += temp %10;
            temp /= 10;
            brZnamenki++;
        }
        
        if(brZnamenki % 2 != 0){
            nepBrojZnamenki = realloc(nepBrojZnamenki, (vel + 1) * sizeof(int));
            zbrojZnamenki = realloc(zbrojZnamenki, (vel + 1) * sizeof(int));
            brojZnamenki = realloc(brojZnamenki, (vel + 1) * sizeof(int));
            
            nepBrojZnamenki[vel] = niz[k];
            zbrojZnamenki[vel] = suma;
            brojZnamenki[vel] = brZnamenki;
            vel++;
        }
    }

    for(int p = 0; p < vel - 1; p++){
        for(int l = 0; l < vel - 1 - p; l++){
            int zamijeni = 0;
            if(brojZnamenki[l] > brojZnamenki[l + 1]) zamijeni = 1;
            else if(brojZnamenki[l] == brojZnamenki[l + 1] && zbrojZnamenki[l] < zbrojZnamenki[l + 1]) zamijeni = 1;


            if(zamijeni){
                int temp = brojZnamenki[l]; brojZnamenki[l] = brojZnamenki[l + 1]; brojZnamenki[l + 1] = temp;
                temp = zbrojZnamenki[l]; zbrojZnamenki[l] = zbrojZnamenki[l + 1]; zbrojZnamenki[l + 1] = temp;
                temp = nepBrojZnamenki[l]; nepBrojZnamenki[l] = nepBrojZnamenki[l + 1]; nepBrojZnamenki[l + 1] = temp;
            }
        }
    }

    for(int a = 0; a < vel; a++){
        printf("Broj: %d | Broj znamenki: %d | Zbroj znamenki: %d\n", nepBrojZnamenki[a], brojZnamenki[a], zbrojZnamenki[a]);
    }

    free(niz);
    free(nepBrojZnamenki);
    free(zbrojZnamenki);
    free(brojZnamenki);

    return 0;
}