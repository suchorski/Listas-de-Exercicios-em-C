#include <stdio.h>

typedef struct {
	short int dia;
	short int mes;
	int ano;
} data;

int main(int argc, char *argv[]) {
	FILE *fp;
	data d;
	fp = fopen("data.txt", "r");
	if (!fp) {
		printf("Erro ao abrir o arquivo data.txt.\n");
		return -3;
	}
	fscanf(fp, "%hd %hd %d", &d.dia, &d.mes, &d.ano);
	printf("Data: %.2hd/%.2hd/%.4d\n", d.dia, d.mes, d.ano);
	fclose(fp);
	return 0;
}
