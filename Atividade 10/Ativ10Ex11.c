#include <stdio.h>

#define CARROS 5

typedef struct {
	char nome[60];
	char modelo[60];
	int anoFabricacao;
	double valor;
} carro;

int main(int argc, char *argv[]) {
	FILE *fp;
	carro c[CARROS], *pC;
	int i;
	fp = fopen("carro.bin", "rb");
	if (!fp) {
		printf("Erro ao abrir o arquivo para gravacao de dados.\n");
		return -3;
	}
	if (fread(c, sizeof(carro), CARROS, fp) != CARROS) {
		printf("Erro ao ler o arquivo de dados.\n");
	}
	for (i = 0, pC = c; i < CARROS; i++, pC++) {
		printf("[Carro %d]\n", i + 1);
		printf("Nome: %s\n", pC->nome);
		printf("Modelo: %s\n", pC->modelo);
		printf("Ano de fabricacao: %d\n", pC->anoFabricacao);
		printf("Valor: %.2lf\n\n", pC->valor);
	}
	fclose(fp);
	return 0;
}