#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long int fatorialIterativo(int);
long int fatorialRecursivo(int);
int consisteNumero(char*, int*);
double calculaTicks(long int);

int main(int argc, char *argv[]) {
	char numeroTmp[16];
	int numero;
	long int resultado, ticks;
	do {
		printf("Digite um inteiro maior ou igual a zero para calcular o fatorial: ");
		gets(numeroTmp);
	} while (!consisteNumero(numeroTmp, &numero));
	printf("\nCalculanto fatorial de %d:\n", numero);
	printf("Calculando fatorial Iterativo...");
	ticks = (long int) clock();
	/* Modo otimizado (iterativo) */
	resultado = fatorialIterativo(numero);
	printf("\rModo iterativo: %ld (%.3lf segundos)\n", resultado, calculaTicks(ticks));
	printf("Calculando fatorial Recursivo...");
	ticks = (long int) clock();
	/*
		Modo lento (recursivo) (uso excessivo da pilha)

		A partir do 34! o C já não calcula mais a multiplicação do fatorial
		e até o 33! aqui não deu discrepância de clocks/segundo.
	*/
	resultado = fatorialRecursivo(numero);
	printf("\rModo recursivo: %ld (%.3lf segundos)\n", resultado, calculaTicks(ticks));
	return 0;
}

long int fatorialIterativo(int numero) {
	long int fatorial = 1;
	int i;
	for (i = 2; i <= numero; i++) {
		fatorial *= i;
	}
	return fatorial;
}

long int fatorialRecursivo(int numero) {
	if (numero <= 1) {
		return 1;
	} else {
		return numero * fatorialRecursivo(numero - 1);
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

double calculaTicks(long int ticks) {
	return (double) ((long int) clock() - ticks) / CLOCKS_PER_SEC;
}
