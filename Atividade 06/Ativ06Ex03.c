#include <stdio.h>

void troca(double[], double[], int);

int main(int argc, char *argv[]) {
    double vA[] = { 0.1, 0.2, 0.3, 0.4, 0.5};
    double vB[] = { 1.1, 2.2, 3.3, 4.4, 5.5};
    double *p;
    int i;
    troca(vA, vB, 5);
    printf("vA: ");
    for (i = 0, p = vA; i < sizeof(vA) / sizeof(double); i++, p++) {
        printf("%.2lf ", *p);
    }
    printf("\nvB: ");
    for (i = 0, p = vB; i < sizeof(vB) / sizeof(double); i++, p++) {
        printf("%.2lf ", *p);
    }
    printf("\n");
    return 0;
}

void troca(double vA[], double vB[], int tam) {
    int i;
    double t, *pA, *pB;
    for (pA = vA, pB = vB, i = 0; i < tam; pA++, pB++, i++) {
        t = *pA;
        *pA = *pB;
        *pB = t;
    }
}
