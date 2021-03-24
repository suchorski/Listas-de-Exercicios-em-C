#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int *modas = NULL;

typedef struct {
	int numero;
	int quantidade;
} guardaModa;

int consisteNumero(char*, int*, int);
void erroDeAlocacao(void);
int comparar(const void*, const void*);
double mediana(int*, int);
int moda(int*, int);
double desvioPadrao(int*, int);
double variancia(int*, int);

int main(int argc, char *argv[]) {
	int *numeros, tam, *p, i, modaTotal;
	char texto[8];
	do {
		printf("Digite o numero de inteiros a declarar: ");
		gets(texto);
	} while (!consisteNumero(texto, &tam, 0));
	numeros = (int*) malloc(tam * sizeof(tam));
	if (!numeros) {
		erroDeAlocacao();
	}
	for (p = numeros, i = 0; i < tam; p++, i++) {
		do {
			printf("Digite o numero %d: ", i + 1);
			gets(texto);
		} while (!consisteNumero(texto, p, 10));
	}
	qsort(numeros, tam, sizeof(int), comparar);
	printf("\nMediana: %.2lf\n", mediana(numeros, tam));
	printf("Moda(s): ");
	modaTotal = moda(numeros, tam);
	if (modaTotal == tam) {
		printf("moda inexistente.");
	} else {
		for (i = 0, p = modas; i < modaTotal; i++, p++) {
			printf("%d ", *p);
		}
	}
	printf("\nDesvio padrao: %.5lf\n", desvioPadrao(numeros, tam));
	printf("Variancia: %.5lf\n", variancia(numeros, tam));
	free(numeros);
	return 0;
}

int consisteNumero(char *texto, int *numero, int variacao) {
	int i;
	char *p;
	if (!strlen(texto)) {
		return 0;
	}
	for (i = 0, p = texto; i < strlen(texto); i++, p++) {
		if (!isdigit(*p)) {
			return 0;
		}
	}
	*numero = atoi(texto);
	if (variacao && (*numero < 1 || *numero > 10)) {
		return 0;
	} else if (*numero <= 0) {
		return 0;
	}
	return 1;
}

void erroDeAlocacao(void) {
	printf("Erro de alocacao de memoria...\n");
	exit(-1);
}

int comparar(const void *x, const void *y) {
	return *((int*) x) - *((int*) y);
}

double mediana(int *v, int tam) {
	int *p = v + tam / 2, *pPar = p - 1;
	if (tam % 2) {
		return *p;
	}
	return ((double) *pPar + *p) / 2;
}

int moda(int *v, int tam) {
	guardaModa *moda = NULL, *erroModa, *pM;
	int *pV, i, j, modaTam = 0, modaMaior = 1, modasTotal = 0, *erroModas, *pMS;
	for (i = 0, pV = v; i < tam; i++, pV++) {
		for (j = 0, pM = moda; j < modaTam; j++, pM++) {
			if (pM->numero == *pV) {
				break;
			}
		}
		if (j == modaTam) {
			erroModa = (guardaModa*) realloc(moda, ++j * sizeof(guardaModa));
			if (!erroModa) {
				erroDeAlocacao();
			}
			moda = erroModa;
			pM = moda + modaTam++;
			pM->numero = *pV;
			pM->quantidade = 1;
		} else {
			if (++pM->quantidade > modaMaior) {
				modaMaior = pM->quantidade;
			}
		}
	}
	for (i = 0, pM = moda, pMS = modas; i < modaTam; i++, pM++) {
		if (pM->quantidade == modaMaior) {
			erroModas = (int*) realloc(modas, ++modasTotal * sizeof(int));
			if (!erroModas) {
				erroDeAlocacao();
			}
			modas = erroModas;
			pMS = modas + modasTotal -1;
			*pMS = pM->numero;
		}
	}
	free(moda);
	return modasTotal;
}

double desvioPadrao(int *v, int tam) {
	return sqrt(variancia(v, tam));
}

double variancia(int *v, int tam) {
	double media = 0, resultado = 0;
	int i, *p;
	if (tam == 1) {
		return 0;
	}
	for (i = 0, p = v; i < tam; i++, p++) {
		media += *p;
	}
	media /= tam;
	for (i = 0, p = v; i < tam; i++, p++) {
		resultado += pow(*p - media, 2);
	}
	resultado /= tam;
	return resultado;
}
