/***************************************************************/
/**                                                           **/
/**   JOÃO PEDRO FROTA CANABRAVA          14681160            **/
/**   Exercício-Programa 1-b                                  **/
/**   Professor: Cristina G. Fernandes                        **/
/**   Turma: (02)                                             **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
int main(){
    int n, F1, F2, F3, soma, aux, opcao;
    scanf("%d", &opcao);
    
    if(opcao == 0){
        scanf("%d", &n);
        while(n > 0){
        F1 = 1;
        F2 = 2;
        F3 = 3;
        while( F2 <= n){
         F1 = F2;
         F2 = F3;
            F3 = F1 + F2;
        }
        printf("1");
        aux = n - F1;
        while( F1 > 1){
            F3 = F2 - F1;
            F2 = F1;
            F1 = F3;
            if(F1 > aux){
                printf("0");
            }
            else{
                printf("1");
                aux = aux - F1;    
            }
        }
        printf("\n");
        scanf("%d", &n);
    }}

    if(opcao == 1){
        scanf("%d", &n);
        while (n != 0) {
            F1 = 1;
            F2 = 2;
            F3 = 3;
            aux = 3;
            if (n == 2) {
                printf("F_2(2)\n");
            } 
            if (n == 1) {
                printf("F_1(1)\n");
            } 
            else {
                while (F3 <= n) {
                    F1 = F2;
                    F2 = F3;
                    F3 = F1 + F2;
                    aux++;
                }
            aux--;
            printf("F_%d(%d)", aux, F2);
            n = n - F2;
            F1 = 1;
            F2 = 2;
            F3 = 3;
            aux = 3;
            while (n > 0) {
                if (n == 2) {
                    printf(" + F_2(2)");
                    n -= 2;
                } 
                if (n == 1) {
                    printf(" + F_1(1)");
                    n -= 1;
                } 
                if (n == 3) {
                    printf(" + F_3(3)");
                    n -= 3;
                }
                if (n == 4){
                    printf(" + F_3(3) + F_1(1)");
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
                    printf(" + F_%d(%d)", aux, F2);
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
    }}
    
    
    if(opcao == 2){
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
    }
        scanf("%d", &n);
    }
  return 0;
}  
