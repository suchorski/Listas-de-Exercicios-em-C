#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int consisteNumero(char*, int*);
void fatorialRecursivo(int, unsigned long int*);
void fatorialIterativo(int, unsigned long int*);

int main(int argc, char *argv[]) {
	int n = 0;
	char temp[16];
	unsigned long int fatorial;
	do {
		printf("Digite um número inteiro positivo: ");
		gets(temp);
	} while (!consisteNumero(temp, &n));
	fatorial = 1;
	fatorialRecursivo(n, &fatorial);
	printf("Calculando fatorial recursivo de %d: %lu\n", n, fatorial);
	fatorial = 1;
	fatorialIterativo(n, &fatorial);
	printf("Calculando fatorial iterativo de %d: %lu\n", n, fatorial);
	return 0;
}

int consisteNumero(char *temp, int *numero) {
	int i;
	if (strlen(temp) == 0) {
		return 0;
	}
	for (i = 0; i < strlen(temp); i++) {
		if (!isdigit(temp[i])) {
			return 0;
		}
	}
	*numero = atoi(temp);
	return 1;
}

void fatorialRecursivo(int n, unsigned long int *fatorial) {
	if (n <= 1) {
		return;
	}
	*fatorial *= n;
	fatorialRecursivo(n - 1, fatorial);
}

void fatorialIterativo(int n, unsigned long int *fatorial) {
	int i;
	for (i = 2; i <= n; i++) {
		*fatorial *= i;
	}
}
