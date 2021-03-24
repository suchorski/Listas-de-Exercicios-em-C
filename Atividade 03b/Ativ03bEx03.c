#include <stdio.h>

double maiorNumero(double*, int);

int main(int argc, char *argv[]) {
	double numeros[] = { 10.2, 2, 3, 4, 5, 6, 7, 8, 9, 10}, numeroMaior;
	numeroMaior = maiorNumero(numeros, sizeof(numeros) / sizeof(double));
	printf("Maior número: %.2lf\n", numeroMaior);
	return 0;
}

double maiorNumero(double *numeros, int tamanho) {
	numeros[tamanho - 2] = (numeros[tamanho - 1] > numeros[tamanho - 2]) ? numeros[tamanho - 1] : numeros[tamanho - 2];
	if (tamanho == 2) {
		return numeros[0];
	}
	return maiorNumero(numeros, tamanho - 1);
}
