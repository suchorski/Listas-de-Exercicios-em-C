#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char texto[1000];
	int i, tamanho;
	printf("Digite um texto: ");
	gets(texto);
	tamanho = (int) strlen(texto);
	printf("Texto digitado: %s\n", texto);
	printf("Tamanho: %d\n", tamanho);
	printf("Inverso: ");
	for (i = (tamanho - 1); i >= 0; i--) {
		printf("%c", texto[i]);
	}
	printf("\n");
	return 0;
}
