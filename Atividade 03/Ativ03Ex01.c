#include <stdio.h>

int soma(int, int);
int subtrai(int, int);
int multiplica(int, int);
float divide(int, int);
int resto(int, int);

int main(int argc, char *argv[]) {
	int x, y;
	printf("Digite um número: ");
	scanf("%d", &x);
	printf("Digite outro número: ");
	scanf("%d", &y);
	printf("Soma: %d\n", soma(x, y));
	printf("Subtração: %d\n", subtrai(x, y));
	printf("Multiplicação: %d\n", multiplica(x, y));
	if (y) {
		printf("Divisão: %.2f\n", divide(x, y));
		printf("Resto: %d\n", resto(x, y));
	} else {
		printf("Impossível dividir por zero.\n");
	}
	return 0;
}

int soma(int x, int y) {
	return x + y;
}
int subtrai(int x, int y) {
	return x - y;
}
int multiplica(int x, int y) {
	return x * y;
}
float divide(int x, int y) {
	return (float) x / y;
}
int resto(int x, int y) {
	return x % y;
}
