#include <stdio.h>

int main(int argc, char *argv[]) {
	int nota;
	printf("Digite sua nota:\n");
	scanf("%d", &nota);
	printf(nota > 70 ? "Aprovado!" : "Reprovado!");
	return 0;
}
