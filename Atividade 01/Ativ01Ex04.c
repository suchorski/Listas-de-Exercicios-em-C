#include <stdio.h>

int main(int argc, char *argv[]) {
	int nota;
	printf("Digite sua nota:\n");
	scanf("%d", &nota);
	if (nota >= 90 && nota <= 100) {
		printf("Nota: A");
	} else if (nota >= 80) {
		printf("Nota: B");
	} else if (nota >= 70) {
		printf("Nota: C");
	} else {
		printf("Reprovado!");
	}
	return 0;
}
