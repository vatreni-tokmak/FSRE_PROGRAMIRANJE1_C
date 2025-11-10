#include <stdio.h>

int main(){

    int binarni;
    int dec = 0, baza = 1, ost;

    printf("Unesi binarni broj (najvise 10 znamenki): \n");
    scanf("%d", &binarni);

    while(binarni > 0){
        ost = binarni % 10;
        dec += ost * baza;
        baza *= 2;
        binarni /= 10;
    }

    printf("Dekadski zapis je: %d\n", dec);

    return 0;
}