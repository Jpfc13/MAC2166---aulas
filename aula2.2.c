#include<stdio.h>
int main(){
    int lenght, lenght2, num, soma = 0;
    printf("Insira o tamanho da sequência que será somada");
    scanf("%d", &lenght);
    lenght2 = 1;
    while(lenght2 <= lenght){
        printf("Insira o %d número da sequência", lenght2);
        scanf("%d", &num);
        lenght2 += 1;
        soma += num;
    }
    printf("O resultado da soma será %d.\n", soma);
    return 0;
}