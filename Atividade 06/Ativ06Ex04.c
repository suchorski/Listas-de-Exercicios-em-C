#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char*);

int main(int argc, char *argv[]) {
    char str[] = "Inversor de strings!";
    inverte(str);
    printf("%s\n", str);
    return 0;
}

void inverte(char *str) {
    int tam = strlen(str), i;
    char *p, *pI, *strInvertido;
    strInvertido = (char*) malloc(tam * sizeof(char));
    for (p = str, pI = strInvertido + tam - 1, i = 0; i < tam; p++, pI--, i++) {
        *pI = *p;
    }
    for (p = str, pI = strInvertido, i = 0; i < tam; p++, pI++, i++) {
        *p = *pI;
    }
}
