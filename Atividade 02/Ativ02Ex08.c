#include <stdio.h>

int main(int argc, char *argv[]) {
	double numeros[15], soma = 0;
	int i;
	for (i = 0; i < (sizeof(numeros) / sizeof(double)); i++) {
		printf("Digite o número de posição %d: ", (i + 1));
		scanf("%lf", &numeros[i]);
		soma += (i + 1) * numeros[i];
	}
	printf("Soma usando a fórmula pedida: %.2lf\n", soma);
	return 0;
}
