#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	printf("Digite um número:\n");
	scanf("%d", &n);
	printf(n % 2 ? "Número ímpar!" : "Número par!");
	return 0;
}
