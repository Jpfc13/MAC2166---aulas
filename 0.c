#include <stdio.h>
int main(){
    int n, i, F1, F2, F3, aux, aux2;
    scanf ("%d", &n);
    F1 = 1;
    F2 = 2;
    F3 = 3;
    while(n != 0){
        while(n > 0){
        if(n == 2)
            printf("10");
        if(n == 1)
            printf("1");
        while(F3 < n){
            F3 = F1 + F2;
            F2 = F1;
            F1 = F3;
            aux += 1;
        }  
        n = n - F3;
        printf("1");
        F3 = 0;
        F1 = 1;
        F2 = 2;
        while(F3 < n){
            F3 = F1 + F2;
            F2 = F1;
            F1 = F3;
            aux2 += 1;
        }
        for(i = aux2; i <= aux; i++){
            printf("0");
        }
        F3 = 0;
        aux = 0;
        aux2 = 0;
        }
        scanf("%d", &n);     
    }
    printf("\n");
    return 0;
}