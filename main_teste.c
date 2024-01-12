#include <stdio.h>

double min(double a, double b, double c, int *i){

    if(a <= b && a <= c){
        *i = 1;
        return a;
    }else if(b <= a && b <= c){
        *i = 2;
        return b;
    }else if(c <= a && c <= b){
        *i = 3;
        return c;
    }

}

int main(){
    double a, b, c, e;
    int i=0;
    scanf("%lf%lf%lf", &a, &b, &c);
    e = min(a, b, c, &i);
    printf("%f / %d", e, i);

}