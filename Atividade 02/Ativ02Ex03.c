#include <stdio.h>

int main(int argc, char *argv[]) {
	int num = 0, ler, total = 0;
	do {
		printf("Digite um número (0 para sair): ");
		scanf("%d", &ler);
		if (ler != 0) {
			num++;
			total += ler;
		}
	} while (ler != 0);
	printf("Número de leituras realizadas: %d\n", num);
	printf("Soma dos números lidos: %.0f\n", total);
	printf("Média dos números lidos: %.2f\n", ((float) total / num));
	return 0;
}
