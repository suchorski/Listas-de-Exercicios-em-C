#include <stdio.h>

void copiaComIndexacao(int[], int[], int);
void copiaSemIndexacao(int*, int*, int);

int main(int argc, char *argv[]) {
    int vA[] = { 1, 2, 3, 4, 5}, vS[5], vC[5], *p, i, tam = sizeof(vA) / sizeof(int);
    copiaSemIndexacao(vA, vS, tam);
    copiaComIndexacao(vA, vC, tam);
    printf("Sem: ");
    for (i = 0, p = vS; i < tam; i++, p++) {
        printf("%d ", *p);
    }
    printf("\nCom: ");
    for (i = 0, p = vC; i < tam; i++, p++) {
        printf("%d ", *p);
    }
    printf("\n");
    return 0;
}

void copiaComIndexacao(int vA[], int vB[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vB[i] = vA[i];
    }
}

void copiaSemIndexacao(int *vA, int *vB, int tam) {
    int i, *pA = vA, *pB = vB;
    for (i = 0; i < tam; i++, pA++, pB++) {
        *pB = *pA;
    }
}
