#include <stdio.h>

int main() {
    int n, F1, F2, F3, aux;
    scanf("%d", &n);
    while (n != 0) {
        F1 = 1;
        F2 = 2;
        F3 = 3;
        aux = 3;
        if (n == 2) {
            printf("F_2\n");
        } 
        else if (n == 1) {
            printf("F_1\n");
        } 
        else {
            while (F3 <= n) {
                F1 = F2;
                F2 = F3;
                F3 = F1 + F2;
                aux++;
            }
            aux--;
            printf("F_%d", aux);
            n = n - F2;
            F1 = 1;
            F2 = 2;
            F3 = 3;
            aux = 3;
            while (n > 0) {
                if (n == 2) {
                    printf(" + F_2");
                    n -= 2;
                } 
                if (n == 1) {
                    printf(" + F_1");
                    n -= 1;
                } 
                if (n == 3) {
                    printf(" + F_3");
                    n -= 3;
                }
                if (n == 4){
                    printf(" + F_3 + F_1");
                    n -= 4;
                }
                if(n > 4){
                    while (F3 <= n) {
                        F1 = F2;
                        F2 = F3;
                        F3 = F1 + F2;
                        aux++;
                    }
                    aux--;
                    printf(" + F_%d", aux);
                    n = n - F2;
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

