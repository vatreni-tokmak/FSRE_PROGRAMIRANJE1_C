#include <stdio.h>

int main(){

    int DDMMGGGG[3];
    int DD[3], MM[3], GGGG[3];
    int datumi[3];

    int i = 0;
    while(i < 3){
        printf("Unesite %d. godinu: ", i+1);
        scanf("%d", &DDMMGGGG[i]);

        //pretvorba u dane
        DD[i] = DDMMGGGG[i] / 1000000;
        MM[i] = (DDMMGGGG[i] / 10000) % 100;
        GGGG[i] = DDMMGGGG[i] % 1000;

        //provjera
        if(DD[i] < 1 || DD[i] > 30 || MM[i] < 1 || MM[i] > 12){
            printf("Neispravan datum\n");
        } else{
            i++;
        }
    }

    //formatiranje datuma za usporedjivanje
    for(int i = 0; i < 3; i++){
        datumi[i] = (GGGG[i]*360) + (MM[i]*30) + DD[i];
    }
    

    //sortiranje
    for(int i = 0; i < 2; i++){
        for(int j = i+1; j < 3; j++){
            if(datumi[i] < datumi[j]){
                int temp = datumi[i];
                datumi[i] = datumi[j];
                datumi[j] = temp;
            }
        }
    }

    //ispis
    printf("izmedju srednjeg i zadnjeg ima: %d dana\n", datumi[2] - datumi[1]);

    return 0;
}