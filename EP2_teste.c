#include <stdio.h>
#include <math.h>

#define L 0.1

/* Read inputs */
void read_data(double *x0, double *v0, double *m0, double *x1, double *v1, double *m1, double *x2, double *v2, double *m2, double *x3, double *v3, double *m3, double *T_max) {
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", x0, v0, m0, x1, v1, m1, x2, v2, m2, x3, v3, m3, T_max);
}

/* Calculate time between collisions */
double t_(double x, double xx, double v, double vv) {
    if (x == xx) {
        return HUGE_VAL;
    } else if (v > vv) {
        return (xx - x - L) / (v - vv);
    } else {
        return (x - xx - L) / (vv - v);
    }
}

/* Calculate the minimum value among three values */
double min(double a, double b, double c, int *i) {
    double m = a;
    *i = 1;

    if (b < m) {
        m = b;
        *i = 2;
    }

    if (c < m) {
        m = c;
        *i = 3;
    }

    return m;
}

/* Calculate the final position and return the displacement */
double adv(double *x, double v, double t) {
    double s_total = v * t;
    *x += s_total;

    if (s_total < 0) {
        s_total = -s_total;
    }

    return s_total;
}

/* Execute a collision */
void resolve(double *v, double *vv, double m, double mm) {
    double A = (2 * (*v) * m + (*vv) * mm) / (m + mm);
    *v = A - *v;
    *vv = A - *vv;
}

/* Print the output */
void print_data(long c1, long c2, long c3, double x0, double x1, double x2, double x3, double v0, double v1, double v2, double v3, double d0, double d1, double d2, double d3) {
    printf("Numero de colisoes por bloco: %ld %ld %ld\n", c1, c2, c3);
    printf("Numero total de colisoes: %ld\n", c1 + c2 + c3);
    printf("Colisoes dos dois blocos a direita: %ld\n", c2 + c3);
    printf("x0 = %.6f v0 = %.6f d0 = %.6f\n", x0, v0, d0);
    printf("x1 = %.6f v1 = %.6f d1 = %.6f\n", x1, v1, d1);
    printf("x2 = %.6f v2 = %.6f d2 = %.6f\n", x2, v2, d2);
    printf("x3 = %.6f v3 = %.6f d3 = %.6f\n", x3, v3, d3);
}

int main() {
    double x0, x1, x2, x3, v0, v1, v2, v3, m0, m1, m2, m3, T_max;
    read_data(&x0, &v0, &m0, &x1, &v1, &m1, &x2, &v2, &m2, &x3, &v3, &m3, &T_max);

    double t1, t2, t3;
    double t = 0.0;
    long c0 = 0, c1 = 0, c2 = 0, c3 = 0;

    while (t < T_max) {
        t1 = t_(x0, x1, v0, v1);
        t2 = t_(x0, x2, v0, v2);
        t3 = t_(x0, x3, v0, v3);

        int i;
        double t_min = min(t1, t2, t3, &i);

        if (t_min == HUGE_VAL) {
            break;
        }

        double d = adv(&x0, v0, t_min);

        if (i == 1) {
            c1++;
            adv(&x1, v1, t_min);
            resolve(&v0, &v1, m0, m1);
            d += adv(&x1, v1, t_min);
        } else if (i == 2) {
            c2++;
            adv(&x2, v2, t_min);
            resolve(&v0, &v2, m0, m2);
            resolve(&v1, &v2, m1, m2);
            d += adv(&x2, v2, t_min);
        } else {
            c3++;
            adv(&x3, v3, t_min);
            resolve(&v0, &v3, m0, m3);
            resolve(&v1, &v3, m1, m3);
            resolve(&v2, &v3, m2, m3);
            d += adv(&x3, v3, t_min);
        }

        t += t_min;

        if (d > L) {
            d -= L;
        } else {
            d = L - d;
        }
    }

    print_data(c1, c2, c3, x0, x1, x2, x3, v0, v1, v2, v3, L - d0, L - d1, L - d2, L - d3);

    return 0;
}
