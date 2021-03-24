#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int **matriz, linhas, colunas, i, j, soma = 0, **pL, *pC;
	if (argc != 2) {
		printf("Uso: exercicio \"arquivo.bin\"\n");
		return -2;
	}
	fp = fopen(argv[1], "r");
	if (!fp) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	fscanf(fp, "%d %d", &linhas, &colunas);
	matriz = (int**) malloc(linhas * sizeof(int));
	if (!matriz) {
		printf("Erro de alocacao de memoria.\n");
		return -1;
	}
	for (i = 0, pL = matriz; i < linhas; i++, pL++) {
		*pL = (int*) malloc(colunas * sizeof(int));
		if (!(*pL)) {
			printf("Erro de alocacao de memoria.\n");
			return -1;
		}
	}
	for (i = 0, pL = matriz; i < linhas; i++, pL++) {
		for (j = 0, pC = *pL; j < colunas ; j++, pC++) {
			fscanf(fp, "%d", pC);
			soma += *pC;
		}
	}
	printf("Somatorio: %d.\n", soma);
	for (i = 0, pL = matriz; i < linhas; i++, pL++) {
		free(*pL);
	}
	free(matriz);
	fclose(fp);
	return 0;
}
