#include <stdio.h>

int soma(int*, int);
float media(int*, int);

int main(int argc, char *argv[]) {
	int numeros[5], i;
	for (i = 0; i < sizeof(numeros) / sizeof(int); i++) {
		printf("Digite o número %d: ", i + 1);
		scanf("%d", &numeros[i]);
	}
	printf("Média: %.2f\n", media(numeros, sizeof(numeros) / sizeof(int)));
	printf("Soma: %d\n", soma(numeros, sizeof(numeros) / sizeof(int)));
	return 0;
}

int soma(int *numeros, int tamanho) {
	int i, soma = 0;
	for (i = 0; i < tamanho; i++) {
		soma += numeros[i];
	}
	return soma;
}

float media(int *numeros, int tamanho) {
	return (float) soma(numeros, tamanho) / tamanho;
}
