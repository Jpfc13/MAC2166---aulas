/***************************************************************/
/**                                                           **/
/**   JOÃO PEDRO FROTA CANABRAVA          14681160            **/
/**   Exercício-Programa 1-a                                  **/
/**   Professor: Cristina G. Fernandes                        **/
/**   Turma: (02)                                             **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
int main(){
    int n, dig, soma, pot3, aux;
    printf("Escreva um número em trinário e insira o 0 para terminar.");
    scanf("%d", &n);
    while(n != 0){
    aux = n;
    soma = 0;
    pot3 = 1;
    while(n != 0){
        dig = n % 10;
        soma = soma + dig * pot3;
        pot3 = 3 * pot3;
        n = n / 10;
    }
    printf("O número %d em decimal será %d\n", aux, soma);
    scanf("%d", &n);
    }
    return 0;
}
