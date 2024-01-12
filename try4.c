#include <stdio.h>

int main() {
    int n, F1, F2, F3, aux, aux2;
    scanf("%d", &n);
    while (n != 0) {
        F1 = 1;
        F2 = 2;
        F3 = 3;
        aux = 3;
        aux2 = 0;
        if (n == 2) {
            printf("10\n");
        } 
        if (n == 1) {
            printf("1\n");
        } 
        else {
            while (F3 <= n) {
                F1 = F2;
                F2 = F3;
                F3 = F1 + F2;
                aux++;
            }
            aux--;
            if(aux2 < aux){
                aux2 = aux;
            }
            printf("1");
            n = n - F2;
            F1 = 1;
            F2 = 2;
            F3 = 3;
            aux = 3;
            while (n > 0) {
                if (n == 2) {
                    printf("10");
                    n -= 2;
                } 
                else if (n == 1) {
                    printf("1");
                    n -= 1;
                } 
                else if (n == 3) {
                    printf("100");
                    n -= 3;
                }
                else if (n == 4){
                    printf("101");
                    n -= 4;
                }
                else {
                    while (F3 <= n) {
                        F1 = F2;
                        F2 = F3;
                        F3 = F1 + F2;
                        aux++;
                    aux--;
                    n = n - F2;
                    }
                    F1 = 1;
                    F2 = 2;
                    F3 = 3;
                    while(F3 <= n){
                        F1 = F2;
                        F2 = F3;
                        F3 = F1 + F2;
                        aux2++;
                    }
                    while(aux2 > aux + 1){ 
                        printf("0");
                        aux += 1;
                    }
                    printf("1");
                    F1 = 1;
                    F2 = 2;
                    F3 = 3;
                    aux = 3;
                }
            }
            printf("\n");
        }
        scanf("%d", &n);
    }

    return 0;
}
