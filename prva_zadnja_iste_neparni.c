#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int *neparni = NULL;
    int br;
    int i = 0;
    int prva;
    int zadnja;


    while(1){
        //unos brojeva
        printf("Unesite broj: \n");
        if(scanf("%d", &br) != 1){
            printf("Neispravan unos. \n");
            return 1;
        }

        //pohrana neparnih u niz
        if(br % 2 != 0){
            i++;
            int *tempArr = realloc (neparni, i * (sizeof(int)));
            if(!tempArr){
                printf("Greska pri alokaciji memorije!\n");
                free(neparni);
            }
            neparni = tempArr;
            neparni[i - 1] = br;
        }

        //trazi prvu i zadnju znamenku
        zadnja = abs(br % 10);
        int temp = br;
        while(temp >= 10){
            temp /= 10;
        }
        prva = temp;

        //provjera jesu li prva i zadnja iste, drugi uvjet sluzi da se program ne prekine nakon unosa jednoznamenkastog broja
        if(prva == zadnja && abs(br) >= 10){
            break;
        }
    }

    //sortiranje neparnih
    for(int m = 0; m < i - 1; m++){
        for(int n = m + 1; n < i; n++){
            int temp = neparni[m];
            neparni[m] = neparni[n];
            neparni[n] = temp;
        }
    }
    
    //ispis neparnih
    printf("Neparni uneseni: \n");
    for(int n = 0; n < i; n++){
        printf("%d\n", neparni[n]);
    }


    return 0;
}