#include <stdio.h>
int main() {
    int n, F1, F2, F3, soma, aux;
    scanf("%d", &n);
    while (n != 0) {
        F1 = 1;
        F2 = 1;
        F3 = 1;
        soma = 0;
        aux = 1;
        while (n > 0) {
            if (n % 10 == 1) {
                soma += F3;
            }
            F1 = F2;
            F2 = F3;
            F3 = F1 + F2;
            n /= 10;
            aux++;
        }
        printf("%d\n", soma);
        scanf("%d", &n);
    }
    return 0;
}
