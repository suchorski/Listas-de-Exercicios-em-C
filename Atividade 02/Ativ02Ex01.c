#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned int termial, total = 0;
	printf("Digite um número inteiro: ");
	scanf("%d", &termial);
	while (termial) {
		total += termial--;
	}
	printf("Soma: %d\n", total);
	return 0;
}
