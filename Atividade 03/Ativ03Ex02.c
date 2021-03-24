#include <stdio.h>
#include <string.h>

void imprimeFrase(char*);
int seVogal(char);

int main(int argc, char *argv[]) {
	char frase[100];
	printf("Digite uma frase: ");
	gets(frase);
	imprimeFrase(frase);
	return 0;
}

void imprimeFrase(char *frase) {
	int i;
	for (i = 0; i < strlen(frase); i++) {
		printf("%c: %s\n", frase[i], (seVogal(frase[i])) ? "Vogal" : "Consoante");
	}
}

int seVogal(char letra) {
	int vogais[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' }, i;
	for (i = 0; i < 10; i++) {
		if (letra == vogais[i]) {
			return 1;
		}
	}
	return 0;
}
