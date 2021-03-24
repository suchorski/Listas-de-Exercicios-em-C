#include <stdio.h>

unsigned long int fibonacci(int);

int main(int argc, char *argv[]) {
	int numero;
	printf("Digite um número: ");
	scanf("%d", &numero);
	printf("Fibonacci de %d é: %lu\n", numero, fibonacci(numero));
	return 0;
}

unsigned long int fibonacci(int numero) {
	unsigned long int resultado = 1;
	unsigned int ft1 = 1, ft2 = 1, i;
	for (i = 3; i <= numero; i++) {
		resultado = ft1 + ft2;
		ft2 = ft1;
		ft1 = resultado;
	}
	return resultado;
}
