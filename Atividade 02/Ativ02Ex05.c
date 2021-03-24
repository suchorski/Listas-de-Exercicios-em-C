#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char texto[1000];
	int i, j, total = 0, c[] = { 32, 65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
	printf("Digite um texto: ");
	gets(texto);
	for (i = 0; i < strlen(texto); i++) {
		for (j = 0; j < (sizeof(c) / sizeof(int)); j++) {
			if (c[j] == texto[i]) {
				total++;
				break;
			}
		}
	}
	printf("Total de vogais e espaços: %d\n", total);
	return 0;
}
