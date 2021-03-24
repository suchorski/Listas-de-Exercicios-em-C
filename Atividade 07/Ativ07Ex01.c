#include <stdio.h>
#include <stdlib.h>

void extraiDados (int*, int, int*, int*, double*);

int main(int argc, char *argv[]) {
    int tam, *valores, *p, i, min, max;
    double avg;
    printf("Digite o número de notas: ");
    scanf("%d", &tam);
    valores = (int*) malloc(tam * sizeof(int));
    if (!valores) {
        printf("Erro de alocacao de memoria...\n");
        exit(-1);
    }
    for (i = 0, p = valores; i < tam; i++, p++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%d", p);
    }
    extraiDados(valores, tam, &min, &max, &avg);
    printf("Menor nota: %d\n", min);
    printf("Maior nota: %d\n", max);
    printf("Nota media: %.2lf\n", avg);
    free(valores);
    return 0;
}

void extraiDados (int *v, int tam, int *min, int *max, double *avg) {
    int *p = v, *pF = v + tam;
    *min = *max = *avg = *p;
    for (p++; p < pF; p++) {
        if (*p < *min) {
            *min = *p;
        }
        if (*p > *max) {
            *max = *p;
        }
        *avg += *p;
    }
    *avg /= tam;
}
