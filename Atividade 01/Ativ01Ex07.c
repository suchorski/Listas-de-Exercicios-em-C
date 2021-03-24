#include <stdio.h>

int main(int argc, char *argv[]) {
	char c;
	printf("Digite um caracter do teclado:\n");
	scanf("%c", &c);
	printf("O caracter %c tem o valor ASCII %d.", c, c);
	return 0;
}
