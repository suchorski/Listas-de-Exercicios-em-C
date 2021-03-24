#include <stdio.h>
#include <stdlib.h>

/* #define TAMANHO // define se o tamanho (primeiro inteiro) está incluído no arquivo a ser lido */

int main(int argc, char *argv[]) {
	FILE *fp;
	int tamanho, *numeros, cercadosTotal = 0, *cercados = NULL, *cercadosTemp, i, *p;
	if (argc != 2) {
		printf("Uso: exercicio \"arquivo\"\n");
		return -2;
	}
	fp = fopen(argv[1], "rb");
	if (!fp) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	#ifdef TAMANHO
		fread(&tamanho, sizeof(int), 1, fp);
		if (ferror(fp)) {
			printf("Erro ao ler o arquivo.\n");
			return -3;
		}
	#else
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) % sizeof(int)) {
			printf("O arquivo pode estar danificado, tente outro.\n");
			return -4;
		}
		tamanho = ftell(fp) / sizeof(int);
		rewind(fp);
	#endif // TAMANHO
	numeros = (int*) malloc((tamanho + 2) * sizeof(int));
	if (!numeros) {
		printf("Erro de alocacao de memoria.\n");
		return -1;
	}
	fread(numeros + 1, sizeof(int), tamanho, fp);
	if (ferror(fp)) {
		printf("Erro ao ler o arquivo.\n");
		return -3;
	}
	numeros[0] = numeros[tamanho];
	numeros[tamanho + 1] = numeros[1];
	for (i = 0, p = numeros + 1; i < tamanho; i++, p++) {
		if (*(p - 1) > *p && *(p + 1) > *p) {
			cercadosTemp = (int*) realloc(cercados, ++cercadosTotal * sizeof(int));
			if (!cercadosTemp) {
				printf("Erro de alocacao de memoria.\n");
				free(cercados);
				return -1;
			}
			cercados = cercadosTemp;
			cercados[cercadosTotal - 1] = *p;
		}
	}
	printf("%d (", cercadosTotal);
	for (i = 0, p = cercados; i < cercadosTotal - 1; i++, p++) {
		printf("%d, ", *p);
	}
	printf("%d)\n", *p);
	fclose(fp);
	free(numeros);
	free(cercados);
	return 0;
}
