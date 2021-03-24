#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int valor;
	short int ativo;
} nodo;

void desativa(nodo*, int, int);

int main(int argc, char *argv[]) {
	srand(time(0));
	nodo n[10], *nP;
	int i, tam = sizeof(n) / sizeof(nodo), valor;
	printf("Nodos: ");
	for (i = 0, nP = n; i < tam; i++, nP++) {
		nP->valor = rand() % 10 + 1;
		printf("%d ", nP->valor);
		nP->ativo = 1;
	}
	printf("\nQual valor quer desativar? ");
	scanf("%d", &valor);
	desativa(n, valor, tam);
	printf("Nodos ativos: ");
	for (i = 0, nP = n; i < tam; i++, nP++) {
		if (nP->ativo) {
			printf("%d ", nP->valor);
		}
	}
	printf("\n");
	return 0;
}

void desativa(nodo *v, int valor, int tam) {
	int i;
	nodo *vP;
	for (i = 0, vP = v; i < tam; i++, vP++) {
		if (vP->valor == valor) {
			vP->ativo = 0;
		}
	}
}
