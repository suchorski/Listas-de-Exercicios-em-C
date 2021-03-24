#include <stdio.h>

int main(int argc, char *argv[]) {
	int numeros[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, soma = 0, i;
	for (i = 0; i < (sizeof(numeros) / sizeof(int)); i++) {
		soma += numeros[i];
	}
	printf("Soma dos números: %d\n", soma);
	return 0;
}
