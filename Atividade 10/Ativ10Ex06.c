#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int tamanho, i;
	double *valores, *pV, soma = 0;
	if (argc != 2) {
		printf("Uso: exercicio \"arquivo\"\n");
		return -2;
	}
	fp = fopen(argv[1], "r");
	if (!fp) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	fscanf(fp, "%d", &tamanho);
	valores = (double*) malloc(tamanho * sizeof(double));
	for (i = 0; i < tamanho; i++) {
		fscanf(fp, "%lf", &valores[i]);
	}
	for (i = 0, pV = valores; i < tamanho; i++, pV++) {
		soma += *pV;
	}
	printf("Media: %lg\n", soma / tamanho);
	fclose(fp);
	free(valores);
	return 0;
}