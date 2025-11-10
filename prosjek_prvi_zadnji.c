#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int a;
    int i = 0;
    int zbroj_pz = 0;
    int zbroj = 0;
    int prosjek_pz;
    int prosjek;
    int *uneseni = NULL;

    while(1){
        printf("Unesite broj: ");
        if(scanf("%d", &a) != 1){
            printf("Neispravan unos!\n");
            return 1;
        }

        //pohrana u niz
        i++;
        int *temp = realloc(uneseni, i * sizeof(int));  //dinamicka alokacija memorije 
        if(!temp){
            printf("Greska pri alokaciji memorije! \n");
            free(uneseni);
            return 1;
        }
        uneseni = temp;
        uneseni[i-1] = a;
        
        //racunanje prosjeka
        zbroj += a;
        prosjek = (double)zbroj / i;

        if(i >= 2){
            prosjek_pz = (uneseni[i-1] + uneseni[i-2] / 2.0);
            if(prosjek > prosjek_pz){
                break;
            }
        }
    }

    //ispis
    for(int n = 0; n < i; n++){
        int prost = 1;

        if(uneseni[n]<1){
            prost = 0;
        } else{
            for(int j = 2; j <= sqrt(uneseni[n]); j++){
                if(uneseni[n] % j == 0){
                    prost = 0;
                    break;
                } 
            }
        } 
        
    if (prost) {
        printf("%d je prost broj\n", uneseni[n]);
    } else {
        printf("%d je slozen broj\n", uneseni[n]);
    }
    }
   
    free(uneseni);
    
    return 0;
}