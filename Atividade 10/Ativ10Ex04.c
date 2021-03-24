#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp[2];
	char ch[2];
	if (argc != 3) {
		printf("Uso: exercicio \"arquivo1\" \"arquivo2\"\n");
		return -2;
	}
	fp[0] = fopen(argv[1], "r");
	fp[1] = fopen(argv[2], "r");
	if (!fp[0] || !fp[1]) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	while (!feof(fp[0]) || !feof(fp[1])) {
		ch[0] = fgetc(fp[0]);
		ch[1] = fgetc(fp[1]);
		if (ch[0] != EOF && ch[1] != EOF && ch[0] == ch[1]) {
			printf("POSICAO %ld - %c (%d)\n", ftell(fp[0]) + 1, ch[0], ch[0]);
		}
	}
	fclose(fp[0]);
	fclose(fp[1]);
	return 0;
}