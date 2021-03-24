#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int consisteNumero(char*, int*);
void incr(int*);

int main(int argc, char *argv[]) {
	int x = 0;
	char temp[16];
	do {
		printf("Digite um número: ");
		gets(temp);
	} while (!consisteNumero(temp, &x));
	incr(&x);
	printf("Número incrementado: %d", x);
	return 0;
}

int consisteNumero(char *temp, int *numero) {
	int i = (temp[0] == '-') ? 1 : 0;
	if (strlen(temp) == 0) {
		return 0;
	}
	for (; i < strlen(temp); i++) {
		if (!isdigit(temp[i])) {
			return 0;
		}
	}
	*numero = atoi(temp);
	return 1;
}

void incr(int *p) {
	(*p)++;
}
