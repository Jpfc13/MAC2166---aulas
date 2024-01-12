#include<stdio.h>
int main(){
    int length, length2, num;
    length2 = 1;
    printf("Insira o tamanho da sequência de números ímpares desejados");
    scanf("%d", &length);
    while(length2 <= length){
        num = length2 * 2 - 1;
        printf(" O %d número da sequência é %d.\n", length2, num);
        length2 = length2 + 1;
    }
return 0;
}