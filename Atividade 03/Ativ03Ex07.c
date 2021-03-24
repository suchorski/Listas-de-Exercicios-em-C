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
	if (numero <= 1) {
		return numero;
	}
	return fibonacci(numero - 1) + fibonacci(numero - 2);
}
