#include <stdio.h>
#include <ctype.h>
#include <string.h>

int consisteNumero(char*, int*);
void soma(int, int, int*);
void subtrai(int, int, int*);
void multiplica(int, int, int*);
void divide(int, int, float*);

int main(int argc, char *argv[]) {
	int x = 0, y = 0, result;
	float resultdiv;
	char temp[16];
	do {
		printf("Digite o primeiro número: ");
		gets(temp);
	} while (!consisteNumero(temp, &x));
	do {
		printf("Digite o segundo número: ");
		gets(temp);
	} while (!consisteNumero(temp, &y));
	soma(x, y, &result);
	printf("Soma: %d\n", result);
	subtrai(x, y, &result);
	printf("Subtração: %d\n", result);
	multiplica(x, y, &result);
	printf("Multiplicação: %d\n", result);
	if (y != 0) {
		divide(x, y, &resultdiv);
		printf("Divisão: %.2lf\n", resultdiv);
	} else {
		printf("Impossível dividir por 0.\n");
	}
	return 0;
}

int consisteNumero(char *temp, int *numero) {
	int i = (temp[0] == '-') ? 1 : 0;
	if (strlen(temp) == 0) {
		return 0;
	}
	for (; i < strlen(temp); i++) {
		if (!isdigit(temp[i])) {
			return 0;
		}
	}
	return 1;
}

void soma(int x, int y, int *result) {
	*result = x + y;
}

void subtrai(int x, int y, int *result) {
	*result = x - y;
}

void multiplica(int x, int y, int *result) {
	*result = x * y;
}

void divide(int x, int y, float *result) {
	*result = ((float) x) / y;
}
