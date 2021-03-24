#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	float a, b, c, d;
	printf("Digite um número\n");
	scanf("%f", &a);
	printf("Digite outro número\n");
	scanf("%f", &b);
	printf("Digite outro número\n");
	scanf("%f", &c);
	printf("Digite o último número\n");
	scanf("%f", &d);
	printf("Calculando %.2f", pow(a, 3) + (b/c) * sqrt(d));
	return 0;
}
