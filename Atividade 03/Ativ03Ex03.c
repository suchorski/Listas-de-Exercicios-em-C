#include <stdio.h>

void imprimeNumeros(int*, int);

int main(int argc, char *argv[]) {
	int numeros[5], i;
	for (i = 0; i < sizeof(numeros) / sizeof(int); i++) {
		printf("Digite o número %d: ", i + 1);
		scanf("%d", &numeros[i]);
	}
	imprimeNumeros(numeros, sizeof(numeros) / sizeof(int));
	return 0;
}

void imprimeNumeros(int *numeros, int tamanho) {
	int i;
	printf("Números: ");
	for (i = 0; i < tamanho; i++) {
		printf("%d%s", numeros[i], (i == tamanho - 1) ? ".\n" : ", ");
	}
	return;
}
