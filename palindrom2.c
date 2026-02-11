#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int jeLiPalindrom(char slova[], int pocetak, int kraj){
    if(pocetak >= kraj){
        return 1;
    }

    if(slova[pocetak] != slova[kraj]){
        return 0;
    }

    return jeLiPalindrom(slova, pocetak + 1, kraj - 1);
}

int main(){
    char *slova = NULL;
    char znak;
    int n = 0;

    while(1){
        printf("Unesite znak: ");
        scanf(" %c", &znak);
    
        if(isalpha(znak)){
            slova = (char*)realloc(slova, (n + 1) * sizeof(char));
            slova[n] = tolower(znak);
            n++; 
        }

        if(znak == '*'){
            break;
        }
    }

    if(n > 2 && jeLiPalindrom(slova, 0, n - 1)){
        printf("Unesena slova su palindrom.\n");
    }else{
        printf("Unesena slova nisu palindrom.\n");
    }

    return 0;
}