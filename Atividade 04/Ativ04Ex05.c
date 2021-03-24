/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Protótipos */
int consisteNumero(char*, int*);
void matematica(int*, int, int*, int*, int*, float*);

/* Função principal */
int main(int argc, char *argv[]) {
	/* Variáveis utilizadas */
	int *numeros = calloc(1, sizeof(int)), *numErr, tamanho = 1;
	char numero[16];
	int menor, maior, soma;
	float media;
	/* Consistência e alocação dinâmica só para estudo */
	do {
		do {
			printf("Digite um número (X para sair): ");
			gets(numero);
		} while (toupper(numero[0]) != 'X' && !consisteNumero(numero, &numeros[tamanho - 1]));
		if (toupper(numero[0]) != 'X') {
			tamanho++;
			numErr = (int*) realloc(numeros, tamanho * sizeof(int));
			if (numErr == NULL) {
				printf("Erro de alocação de memória!");
				exit(1);
			} else {
				numeros = numErr;
			}
		} else {
			tamanho--;
		}
	} while (toupper(numero[0]) != 'X');
	/* Código pedido no exercício */
	matematica(numeros, tamanho, &menor, &maior, &soma, &media);
	if (tamanho) {
		printf("\nMenor: %d\n", menor);
		printf("Maior: %d\n", maior);
		printf("Soma: %d\n", soma);
		printf("Média: %.2f\n", media);
	} else {
		printf("Nenhum número cadastrado!");
	}
	return 0;
}

/*  Função de consistência */
int consisteNumero(char *temp, int *numero) {
	int i = (temp[0] == '-') ? 1 : 0;
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

/* Função pedida no exercício */
void matematica(int *numeros, int tamanho, int *menor, int *maior, int *soma, float *media) {
	int i;
	*menor = *maior = *soma = numeros[0];
	for (i = 1; i < tamanho; i++) {
		if (numeros[i] < *menor) {
			*menor = numeros[i];
		}
		if (numeros[i] > *maior) {
			*maior = numeros[i];
		}
		*soma += numeros[i];
	}
	*media = (float) *soma / tamanho;
}
