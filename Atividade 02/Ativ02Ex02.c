#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char texto[100];
	unsigned int total = 0, i;
	printf("Digite um texto: ");
	gets(texto);
	for (i = 0; i < strlen(texto); i++) {
		if (texto[i] == 'a' || texto[i] == 'A') {
			total++;
		}
	}
	printf("Total de 'a' e 'A' no texto: %d\n", total);
	return 0;
}

