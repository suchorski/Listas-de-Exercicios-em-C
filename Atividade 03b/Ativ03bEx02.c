#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

double meuPow(int, int);
int consisteNumero(char *numeroTmp, int *numero);
double calculaTicks(long int);

int main(int argc, char *argv[]) {
	char numeroTmp[16], expoenteTmp[16];
	int numero, expoente;
	double resultado;
	long int ticks;
	do {
		printf("Digite um número para ser elevado: ");
		gets(numeroTmp);
	} while (!consisteNumero(numeroTmp, &numero));
	do {
		printf("Digite um número do expoente (maior ou igual a 0): ");
		gets(expoenteTmp);
	} while (!consisteNumero(expoenteTmp, &expoente) || expoente < 0);
	printf("Calculando %d elevado a %d:\n", numero, expoente);
	printf("Calculando no modo recursivo...");
	ticks = (long int) clock();
	/*
		Modo lento (recursivo) (uso excessivo da pilha)

		A partir do expoente sendo igual a 400000 está dando estouro de pilha
		e um pouco abaixo disso ele não dá discrepância de cálculo de valores.
	*/
	resultado = meuPow(numero, expoente);
	printf("\rModo recursivo: %.0lf (%.3lf segundos)\n", resultado, calculaTicks(ticks));
	printf("Calculando pela função pow()...");
	ticks = (long int) clock();
	resultado = pow(numero, expoente);
	printf("\rModo pow() da math.h: %.0lf (%.3lf segundos)\n", resultado, calculaTicks(ticks));
	return 0;
}

double meuPow(int numero, int expoente) {
	if (expoente == 1) {
		return numero;
	}
	return numero * meuPow(numero, expoente - 1);
}

int consisteNumero(char *numeroTmp, int *numero) {
	int i;
	if (strlen(numeroTmp) == 0) {
		return 0;
	}
	for (i = 0; i < strlen(numeroTmp); i++) {
		if (numeroTmp[i] == '-') {
			break;
		}
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
