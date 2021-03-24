#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	if (argc != 2) {
		printf("Sintaxe: exercicio \"arquivo\"\n");
		return -2;
	}
	fp = fopen(argv[1], "r");
	if (!fp) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	fseek(fp, 0, SEEK_END);
	printf("Caracteres no arquivo: %ld\n", ftell(fp));
	fclose(fp);
	return 0;
}
