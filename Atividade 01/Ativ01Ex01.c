#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b;
	printf("Digite o primeiro número:\n");
	scanf("%d", &a);
	printf("Digite o segundo número:\n");
	scanf("%d", &b);
	printf("Soma: %d\n", a + b);
	printf("Subtração: %d\n", a - b);
	printf("Multiplicação: %d\n", a * b);
	if (b != 0) {
		printf("Divisão: %d\n", a / b);
		printf("Resto: %d\n", a % b);
	} else {
		printf("Divisão impossível!");
	}
	return 0;
}
