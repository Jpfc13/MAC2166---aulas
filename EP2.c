/***************************************************************/
/**                                                           **/
/**   João Pedro Frota Canabrava      Número USP : 14681160   **/
/**   Exercício-Programa 02                                   **/
/**   Professor: Cris                                         **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <math.h>

/*Lê entradas*/
void read_data(double *x0, double *v0, double *m0, double *x1, double *v1, double *m1, double *x2, double *v2, double *m2, double *x3, double *v3, double *m3, double *T_max){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", x0, v0, m0, x1, v1, m1, x2, v2, m2, x3, v3, m3, T_max);
}

/*Calcula tempo entre colisões*/
double t_(double x, double xx, double v, double vv){
    /*Tempo entre colisão baseado em dS/dT*/
    double t;

    if(v == vv){
        return HUGE_VAL;
    }else if(x < xx && v < vv){
        return HUGE_VAL;
    }else if(x < xx && v > vv){
        t = ((xx - x)-0.1)/(v - vv);
    }else if(x > xx && v < vv){
        t = ((xx - x)+0.1)/(v - vv);
    }

    return t;
}

/*Calcula o mínimo entre três valores*/
double min(double a, double b, double c, int *i){

    if(a < b && a < c){
        *i = 1;
        return a;
    }else if(b < a && b < c){
        *i = 2;
        return b;
    }else if(c < a && c < b){
        *i = 3;
        return c;
    }else if(a == b && a < c){
        *i = 1;
        return a;
    }else if(a == c && a < b){
        *i = 1;
        return a;
    }else if(c == b && b < a){
        *i = 2;
        return a;
    }else if(a == b & b == c){
        *i = 1;
        return a;
    }
}

/*Calcula a posição final e devolve o deslocamento*/
double adv(double *x, double v, double t){
    double s_total, Xi;

    Xi = *x;

    if(v < 0){
        v = v * (-1);
    }

    s_total = (v * t);

    *x = Xi + (v * t);

    return s_total;
}

/*Executa uma colisão*/
void resolve(double *v, double *vv, double m, double mm){
    double A; /*Calcula o A dado na parte 5 do EP*/

    double v1, v2;
  
        v1 = *v;
        v2 = *vv;

        A = (2*((v1 * m)+(v2 * mm)))/(m + mm);

        *v = A - v1;

        *vv = A - v2;
}

/*Imprime uma saída*/
void print_data(long c1, long c2, long c3,
double x0, double x1, double x2, double x3,
double v0, double v1, double v2, double v3,
double d0, double d1, double d2, double d3){

    printf("Numero de colisoes por bloco: %ld %ld % ld\n", c1, c2, c3);

    printf("Numero total de colisoes: %ld\n", c1 + c2 + c3);

    printf("Colisoes dos dois blocos a direita: %ld\n", c2 + c3);

    printf("x0 = %.6f v0 = %.6f d0 = %.6f\n", x0, v0, d0);

    printf("x1 = %.6f v1 = %.6f d1 = %.6f\n", x1, v1, d1);

    printf("x2 = %.6f v2 = %.6f d2 = %.6f\n", x2, v2, d2);

    printf("x3 = %.6f v3 = %.6f d3 = %.6f\n", x3, v3, d3);

}

int main(){

    double x0, x1, x2, x3, v0, v1, v2, v3, m0, m1, m2, m3, d0, d1, d2, d3, T_Max, t = 0, t1, t2, t3, t_min, T_aux = 0;
    long c1 = 0, c2 = 0, c3 = 0;
    int i = 0;

    read_data(&x0, &v0, &m0, &x1, &v1, &m1, &x2, &v2, &m2, &x3, &v3, &m3, &T_Max);

    /*Calcula o tempo minimo entre duas colisões, realiza o movimento dos blocos e executa a colisão*/
    while(T_Max > 0){

        t1 = t_(x0, x1, v0, v1);
        t2 = t_(x1, x2, v1, v2);
        t3 = t_(x2, x3, v2, v3);

        t_min = min(t1, t2, t3, &i);

        T_aux = T_Max;

        if(t_min == HUGE_VAL){
            T_aux = T_Max;
            T_Max = 0;
            t_min == 0;
        }
        if(T_Max - t_min < 0){
            T_aux = T_Max;
            T_Max = 0;
            i = 0;
            t_min == 0;
        }

        T_Max = T_Max - t_min;

        if(i == 1 && t1 != HUGE_VAL){
           d0 += adv(&x0, v0, t1);
           d1 += adv(&x1, v1, t1);
           d2 += adv(&x2, v2, t1);
           d3 += adv(&x3, v3, t1);
           if(t1 < t2 && t1 < t3){
            resolve(&v0, &v1, m0, m1);
            c1++;
           }
           if(t1 == t2 && t2 < t3){
            resolve(&v0, &v1, m0, m1);
            resolve(&v1, &v2, m1, m2);
            c1++;
            c2++;
           }
           if(t1 == t3 && t1 < t2){
            resolve(&v0, &v1, m0, m1);
            resolve(&v2, &v3, m2, m3);
            c1++;
            c3++;
           }
           if(t1 == t2 && t2 == t3){
            resolve(&v0, &v1, m0, m1);
            resolve(&v1, &v2, m1, m2);
            resolve(&v2, &v3, m2, m3);
            c1++;
            c2++;
            c3++;
           }
           i = 0;
        }

        if(i == 2 && t2 != HUGE_VAL){
           d0 += adv(&x0, v0, t2);
           d1 += adv(&x1, v1, t2);
           d2 += adv(&x2, v2, t2);
           d3 += adv(&x3, v3, t2);
           if(t2 < t1 && t2 < t3){
            resolve(&v1, &v2, m1, m2);
            c2++;
           }
           if(t2 == t3 && t2 < t1){
            resolve(&v1, &v2, m1, m2);
            resolve(&v2, &v3, m2, m3);
            c2++;
            c3++;
           }
           i = 0;
        }

        if(i == 3 && t3 != HUGE_VAL){
           d0 += adv(&x0, v0, t3);
           d1 += adv(&x1, v1, t3);
           d2 += adv(&x2, v2, t3);
           d3 += adv(&x3, v3, t3);
           resolve(&v2, &v3, m2, m3);
           c3++;
           i = 0;
        }
    }

    
    d0 += adv(&x0, v0, T_aux);
    d1 += adv(&x1, v1, T_aux);
    d2 += adv(&x2, v2, T_aux);
    d3 += adv(&x3, v3, T_aux);
    
    
    print_data(c1, c2, c3, x0, x1, x2, x3, v0, v1, v2, v3, d0, d1, d2, d3);

    t1 = t_(x0, x1, v0, v1);
    t2 = t_(x1, x2, v1, v2);
    t3 = t_(x2, x3, v2, v3);

    if(t1 == HUGE_VAL && t2 == HUGE_VAL && t3 == HUGE_VAL){
        printf("Nao ha mais colisoes\n");
    }
    else{
        printf("Ainda ha colisoes\n");
    }
    
    return 0;
}