#include <stdio.h>

unsigned long int fatorial(int);

int main(int argc, char *argv[]) {
	int numero;
	printf("Digite um número: ");
	scanf("%d", &numero);
	printf("Fatorial de %d é: %lu\n", numero, fatorial(numero));
	return 0;
}

unsigned long int fatorial(int numero) {
	int i;
	unsigned long int fatorial = 1;
	for (i = 2; i <= numero; i++) {
		fatorial *= i;
	}
	return fatorial;
}
