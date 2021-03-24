#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

short int consisteNumero(char*);

int main(int argc, char *argv[]) {
    int *numeros, *numerosVisitados, *pN, *pNF, *pV, *pVF, soma = 0, tamanho = argc - 1, i;
    numeros = (int*) malloc(tamanho * sizeof(int));
    numerosVisitados = (int*) calloc(tamanho, sizeof(int));
    if (!numeros || !numerosVisitados) {
        printf("Erro de alocacao de memoria...");
        return -1;
    }
    for (i = 1, pN = numeros; i <= tamanho; i++, pN++) {
        if (!consisteNumero(argv[i])) {
            printf("Parametros incorretos. Todos os parametros devem ser numeros inteiros!\n");
            return -2;
        }
        *pN = atoi(argv[i]);
    }
    pN = numeros;
    pV = numerosVisitados;
    pNF = numeros + tamanho - 1;
    pVF = numerosVisitados + tamanho - 1;
    while (*pN) {
        soma += *pN;
        *pV = 1;
        pV += *pN;
        pN += *pN;
        while (pN > pNF || pN < numeros) {
            pN = pN + ((pN > pNF) ? -tamanho : tamanho);
            pV = pV + ((pV > pVF) ? -tamanho : tamanho);
        }
        if (*pV) {
            printf("Loop eterno!\n");
            return 0;
        }
    }
    printf("Soma: %d\n", soma);
    return 0;
}

short int consisteNumero(char *numero) {
    int i = 0;
    char *pN = numero;
    if (*pN == '-') {
        i++;
        pN++;
    }
    for (; i < strlen(numero); i++, pN++) {
        if (!isdigit(*pN)) {
            return 0;
        }
    }
    return 1;
}
