#include <stdio.h>
#include <math.h>

int main(){

    int br; 
    int i = 0;
    int silazno[15];

    while(i < 15){
        scanf("%d", &br);
        if(br % 2 == 0){
            silazno[i] = br;
            i++;
        }
    }

    for(int i = 0; i < 14; i++){
        for(int j = i+1; j < 15; j++){
            if(silazno[i] < silazno[j]){
                int temp = silazno[i];
                silazno[i] = silazno[j];
                silazno[j] = temp;
            }
        }
    }

    for(int i = 0; i < 15; i++){
        printf("%d ", silazno[i]);
    }

    return 0;
}