#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define imprime printf
#define escreve scanf
#define enquanto while
#define para for
#define se if
#define senao else

#define PI 3.141596

#define teste

typedef struct {
	int numero;
	int quantidade;
} contador;

int consisteNumero(char*);
int compararContagem(const void*, const void*);

int main(int argc, char *argv[]) {
	int tamanho, *numeros, i, *pN, maior;
	char numTemp[16];
	contador *contagem, *pC;
	do {
		printf("Digite o tamanho do vetor (>= 1): ");
		gets(numTemp);
	} while(!(tamanho = consisteNumero(numTemp)));
	srand(time(NULL));
	numeros = (int*) malloc(tamanho * sizeof(int));
	contagem = (contador*) calloc(tamanho + 1, sizeof(contador));
	if (!numeros || !contagem) {
		printf("Erro de alocacao de memoria...\n");
		return -1;
	}
	#ifdef teste
		printf("Lixos no vetor:\n");
		for (i = 0, pN = numeros; i < tamanho; i++, pN++) {
			printf("%d\n", *pN);
		}
		printf("\n");
	#endif // teste
	for (i = 0, pN = numeros, pC = contagem; i < tamanho; i++, pN++, pC++) {
		*pN = rand() % (tamanho + 1);
		pC->numero = i;
	}
	pC->numero = i;
	for (i = 0, pN = numeros; i < tamanho; i++, pN++) {
		contagem[*pN].quantidade++;
	}
	qsort(contagem, tamanho + 1, sizeof(contador), compararContagem);
	#ifdef teste
		printf("Tabela geral:\n");
		for (i = 0, pC = contagem; i <= tamanho; i++, pC++) {
			printf("%d\t%d\n", pC->numero, pC->quantidade);
		}
		printf("\n");
	#endif // teste
	printf("Ganhador(es): ");
	for (pC = contagem, maior = pC->quantidade; maior == pC->quantidade; pC++) {
		printf("%d ", pC->numero);
	}
	printf("\n");
	return 0;
}

int consisteNumero(char *numTemp) {
	int i;
	char *pN;
	for (i = 0, pN = numTemp; i < strlen(numTemp); i++, pN++) {
		if(!isdigit(*pN)) {
			return 0;
		}
	}
	return atoi(numTemp);
}

int compararContagem(const void *x, const void *y) {
	return ((contador*) y)->quantidade - ((contador*) x)->quantidade;
}
