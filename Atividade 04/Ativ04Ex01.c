#include <stdio.h>

int main(int argc, char *argv[]) {
	char c = 'T';
	char *p = &c;
	printf("Valor de c: %c\n", c);
	printf("Valor da variável apontado por p: %c\n", *p);
	printf("O endereço de c: %p\n", &c);
	printf("O endereço apontando por p: %p\n", p);
	printf("O endereço de p: %p\n", &p);
	return 0;
}
