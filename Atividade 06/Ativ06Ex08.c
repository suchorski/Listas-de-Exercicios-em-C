#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *pI, *pF, *pA, *pD;
    char nome[100];
    do {
        printf("Digite seu nome: ");
        gets(nome);
        if (strlen(nome) < 2) {
            printf("Nome precisa ter 2 ou mais caracteres.\n");
        }
    } while (strlen(nome) < 2);
    pI = nome;
    pF = nome + strlen(nome) - 1;
    printf("\"");
    for (; pI <= pF; pI++) {
        printf("%c", *pI);
    }
    pI = nome;
    printf("\" -> %c", *pI);
    if (strlen(nome) > 2) {
        pI++;
        for (; pI < pF; pI++) {
            pA = pI - 1;
            pD = pI + 1;
            if ((*pA + *pD) / 2 < *pI) {
                printf("%c", *pI);
            }
        }
    }
    printf("%c\n", *pF);
    return 0;
}
