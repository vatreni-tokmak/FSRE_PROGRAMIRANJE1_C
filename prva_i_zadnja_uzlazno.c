#include <stdio.h>

int main(){

    int br;
    int prva;
    int temp;
    int uzlazno[10];

    int i = 0;
    while(i < 10){
        printf("Unesite broj: ");
        scanf("%d", &br);

        br = temp;

        while(br >= 10){
            br /= 10;
            prva = br;
        }

        if(temp % 10 == prva){
            temp = uzlazno[i];
            i++;
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 10; j++){
            if(uzlazno[i] > uzlazno[j]){
                int temp = uzlazno[i];
                uzlazno[i] = uzlazno[j];
                uzlazno[j] = temp;
            }
        }
    }

    printf("\nUzlazno: ");
    for(int i = 0; i < 10; i++){
        printf("%d \n", uzlazno[i]);
    }

    return 0;
}