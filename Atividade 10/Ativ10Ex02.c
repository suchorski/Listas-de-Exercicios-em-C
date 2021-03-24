#include <stdio.h>

#ifndef BUFSIZ
	#define BUFSIZ 2048
#endif // BUFSIZ

int main(int argc, char *argv[]) {
	FILE *fp[2];
	char buffer[BUFSIZ];
	size_t bytesLidos;
	if (argc != 3) {
		printf("Sintaxe: exercicio \"arquivo_origem\" \"arquivo_destino\"\n");
		return -2;
	}
	fp[0] = fopen(argv[1], "rb");
	fp[1] = fopen(argv[2], "wb");
	if (!fp[0] || !fp[1]) {
		printf("Erro ao abrir o arquivo.\n");
		return -3;
	}
	while (!feof(fp[0])) {
		bytesLidos = fread(buffer, sizeof(char), BUFSIZ, fp[0]);
		if (ferror(fp[0])) {
			printf("Erro ao ler o arquivo.\n");
			remove(argv[2]);
			return -3;
		}
		fwrite(buffer, sizeof(char), bytesLidos, fp[1]);
		if (ferror(fp[1])) {
			printf("Erro ao escrever no arquivo.\n");
			remove(argv[2]);
			return -3;
		}
	}
	fclose(fp[0]);
	fclose(fp[1]);
	return 0;
}
