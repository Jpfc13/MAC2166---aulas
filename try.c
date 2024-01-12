#include <stdio.h>

int main() {
    int n, i, F1, F2, F3, aux, aux2;
    scanf("%d", &n);
    F1 = 1;
    F2 = 2;
    F3 = 3;

    while (n != 0) {
        aux = 3; 
        while (n > 0) { 
            if (n == 2)
                printf("10");
            if (n == 1)
                printf("1");
            while (F3 < n) {
                F1 = F2;
                F2 = F3;
                F3 = F1 + F2;
                aux++;
            }
            aux--;
            n = n - F2;
            printf("1");
            F3 = 3;
            F1 = 1;
            F2 = 2;
            aux2 = 3; 
            while (F3 < n) {
                F1 = F2;
                F2 = F3;
                F3 = F1 + F2;
                aux2++;
            }
            aux2--;
            for (i = aux2; i < aux; i++) { 
                printf("0");
            }
            F3 = 3;
            F1 = 1;
            F2 = 2;
            aux2 = 3;
        }
        scanf("%d", &n);
    }

    printf("\n");
    return 0;
}
