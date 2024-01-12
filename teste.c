#include <stdio.h>

int main() {

    int n, F1, F2, F3, dif;
    scanf("%d", &n);

    while(n != 0){
        F1 = 1;
        F2 = 2;
        F3 = 3;
        while( F2 <= n){
         F1 = F2;
         F2 = F3;
            F3 = F1 + F2;
        }

        printf("1");

        dif = n - F1;


        while( F1 > 1){
            F3 = F2 - F1;
            F2 = F1;
            F1 = F3;
            if(F1 > dif){
                printf("0");
            }
            else{
                printf("1");
                dif = dif - F1;    
            }
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
