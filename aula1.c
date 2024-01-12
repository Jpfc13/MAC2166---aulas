#include <stdio.h>
int main(){
    int num, sum = 0;
    printf("Digite uma sequencia de numeros diferentes de zero, seguida de um zero: ");
    scanf("%d", &num);
    while(num != 0){
        sum = sum + num;
        scanf("%d", &num);
    }
    printf("A soma dos numeros da sequencia e' %d.\n", sum);
    return 0;
}