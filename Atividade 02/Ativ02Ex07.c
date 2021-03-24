#include <stdio.h>

int main(int argc, char *argv[]) {
	int numeros[10], soma = 0, i;
	for (i = 0; i < (sizeof(numeros) / sizeof(int)); i++) {
		printf("Digite o inteiro de posição %d: ", (i + 1));
		scanf("%d", &numeros[i]);
	}
	for (i = 0; i < (sizeof(numeros) / sizeof(int)); i++) {
		printf("%d %c ", numeros[i], ((i == 9) ? '=' : '+'));
		soma += numeros[i];
	}
	printf("%d\n", soma);
	return 0;
}
