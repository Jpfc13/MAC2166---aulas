#include <stdio.h>
int main () {
    int num, soma = 0;
    printf("Escreva uma sequência numérica seguida de zero que o programa lhe dará o tamanho da sequência");
    scanf("%d", &num);
    while(num != 0) {
        soma += 1;
        printf("Escreva mais um número ou insira o 0 para encerrar a sequência");
        scanf("%d", &num);
    }
printf("A sequência tem %d números", soma);
return 0;
}