#include <stdio.h>

int main(){

    int hhmmss;
    int vrijeme;
    int sek;
    int ponoc = 24*3600;

    printf("Unesite vrijeme u formatu HHMMSS: \n");
    scanf("%d", &hhmmss);

    int ss = hhmmss % 100;
    hhmmss /= 100;

    printf("%d s\n", ss);

    int mm = hhmmss % 100;
    mm *= 60;
    hhmmss /= 100;

    printf("%d m\n", mm);

    int hh = hhmmss * 3600;

   printf("%d h\n", hh);
 
    

    if(hh < ponoc && mm < 3600 && ss < 60){
        vrijeme = hh + mm + ss;
        sek = ponoc - vrijeme;
    } else {
        printf("Uneseno vrijeme je neispravno.");
    }
    
    printf("Do ponoci je ostalo %d sekundi. \n", sek);
 
    return 0;
}