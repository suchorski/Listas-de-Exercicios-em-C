#include <stdio.h>
#include <string.h>

typedef union {
    char senha[8];
    long int chave;
} minhaSenha;

int main(int argc, char *argv[]) {
    minhaSenha s;
    do {
        printf("Digite sua senha (8 caracteres): ");
        gets(s.senha);
    } while (strlen(s.senha) != 8);
    printf("Sua chave e: %ld.\n", s.chave);
    return 0;
}
