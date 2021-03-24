#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

unsigned long int f(int);
int consisteNumero(char*, int*);

int main(int argc, char *argv[]) {
	char numeroTmp[16];
	int numero;
	do {
		printf("Digite um número inteiro maior ou igual a zero: ");
		gets(numeroTmp);
	} while (!consisteNumero(numeroTmp, &numero));
	printf("f(%d) = %lu\n", numero, f(numero));
	return 0;
}

unsigned long int f(int numero) {
	/* return (unsigned long int) pow(2, (numero / 2)); // Função */
	if (numero <= 1) {
		return 1;
	} else if (numero % 2) {
		return f(numero - 1);
	} else {
		return f(numero - 1) * 2;
	}
}

int consisteNumero(char *numeroTmp, int *numero) {
	int i;
	if (strlen(numeroTmp) == 0) {
		return 0;
	}
	for (i = 0; i < strlen(numeroTmp); i++) {
		if (numeroTmp[i] < '0' || numeroTmp[i] > '9') {
			return 0;
		}
	}
	*numero = atoi(numeroTmp);
	return 1;
}
