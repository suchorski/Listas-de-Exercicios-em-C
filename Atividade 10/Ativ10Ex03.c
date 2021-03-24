#include <stdio.h>
#include <string.h>

#define TAMANHO 10
#define COPIAS 10

int main(int argc, char *argv[]) {
	FILE *fp;
	int i, j;
	char texto[TAMANHO], *p, ch;
	do {
		printf("Digite um texto de 10 caracteres: ");
		gets(texto);
	} while (strlen(texto) != 10);
	fp = fopen("exercicio.txt", "w+");
	if (!fp) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	for (i = 0, p = texto; i < TAMANHO; i++, p++) {
		for (j = 0; j < COPIAS; j++) {
			fprintf(fp, "%c", *p);
		}
	}
	rewind(fp);
	printf("Conteudo do arquivo:\n");
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch != EOF) {
			printf("%c", ch);
		}
	}
	printf("\n");
	fclose(fp);
	return 0;
}