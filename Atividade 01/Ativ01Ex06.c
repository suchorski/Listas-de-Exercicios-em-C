#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	float a, b, c, d, r1, r2;
	printf("Digite o valor de a:\n");
	scanf("%f", &a);
	printf("Digite o valor de b:\n");
	scanf("%f", &b);
	printf("Digite o valor de c:\n");
	scanf("%f", &c);
	d = pow(b, 2) - 4 * a * c;
	printf(d >= 0 ? "Equação toca no eixo x\n" : "Equação não toca no eixo x\n");
	if (d >= 0) {
		r1 = (-1 * b + sqrt(d)) / (2 * a);
		r2 = (-1 * b - sqrt(d)) / (2 * a);
		printf("Raizes: %.2f e %.2f", r1, r2);
	}
	return 0;
}
