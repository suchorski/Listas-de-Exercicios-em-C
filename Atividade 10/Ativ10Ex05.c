#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp[3];
	char ch[2];
	if (argc != 3) {
		printf("Uso: exercicio \"arquivo1\" \"arquivo2\"\n");
		return -2;
	}
	fp[0] = fopen(argv[1], "r");
	fp[1] = fopen(argv[2], "r");
	fp[2] = fopen("resultadoMerge.txt", "w");
	if (!fp[0] || !fp[1] || !fp[2]) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	while (!feof(fp[0]) || !feof(fp[1])) {
		ch[0] = fgetc(fp[0]);
		ch[1] = fgetc(fp[1]);
		if (ch[0] != EOF && ch[1] != EOF && ch[0] == ch[1]) {
			fprintf(fp[2], "POSICAO %ld - %c (%d)\n", ftell(fp[0]) + 1, ch[0], ch[0]);
		}
	}
	fclose(fp[0]);
	fclose(fp[1]);
	fclose(fp[2]);
	return 0;
}