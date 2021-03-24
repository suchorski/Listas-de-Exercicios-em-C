#include <stdio.h>
#include <string.h>

int primeiraVogal(char*);
int isVogal(char);

int main(int argc, char *argv[]) {
	char frase[100];
	printf("Digite uma frase: ");
	gets(frase);
	printf("Posição da primeira vogal encontrada: %d\n", primeiraVogal(frase));
	return 0;
}

int primeiraVogal(char *frase) {
	int i;
	for (i = 0; i < strlen(frase); i++) {
		if (isVogal(frase[i])) {
			return i;
		}
	}
	return -1;
}

int isVogal(char letra) {
	int vogais[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' }, i;
	for (i = 0; i < 10; i++) {
		if (letra == vogais[i]) {
			return 1;
		}
	}
	return 0;
}
