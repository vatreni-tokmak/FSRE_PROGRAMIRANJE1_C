#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(){

    char unos;
    int redniBrUnosa[10] = {0};
    int pozicija = 0;
    int brojZnamenki = 0;

    while(brojZnamenki < 10){
        printf("unesite znak: ");
        scanf(" %c", &unos);

        pozicija++;

        if(isdigit(unos)){
            int znamenka = unos - '0';

            if(redniBrUnosa[znamenka] == 0){
                redniBrUnosa[znamenka] = pozicija;
                brojZnamenki++;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%d (%d)\n", i, redniBrUnosa[i]);
    }
 

    return 0;
}