#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jePalindrom(char *niz, int pocetak, int kraj) {
    if (pocetak >= kraj) {
        return 1; // Niz je palindrom
    }
    if (niz[pocetak] != niz[kraj]) {
        return 0; // Niz nije palindrom
    }
    return jePalindrom(niz, pocetak + 1, kraj - 1);
}


int main() {
    
    char unos;
    char *uneseniNiz = NULL;
    int duzinaNiza = 0;

    while(1){
        printf("Unesite niz karaktera: ");
        scanf(" %c", &unos);
        
        uneseniNiz = (char*)realloc(uneseniNiz, (duzinaNiza + 1) * sizeof(char));
        uneseniNiz[duzinaNiza] = unos;
        duzinaNiza++;

        if(duzinaNiza > 1){ 
            if(jePalindrom(uneseniNiz, 0, duzinaNiza - 1)){
                printf("Niz je palindrom.\n");
                break;
            } else {
                printf("Niz nije palindrom. Nastavite s unosom.\n");
            }

        }
    }

    free(uneseniNiz);

    return 0;
}