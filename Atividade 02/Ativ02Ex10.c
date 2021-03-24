#include <stdio.h>

int main(int argc, char *argv[]) {
	int matriz[2][3], i, j;
	for (i = 0; i < (sizeof(matriz) / sizeof(*matriz)); i++) {
		for (j = 0; j < (sizeof(*matriz) / sizeof(int)); j++) {
			printf("Digite o valor da linha %d x coluna %d: ", (i + 1), (j + 1));
			scanf("%d", &matriz[i][j]);
		}
	}
	for (i = 0; i < (sizeof(matriz) / sizeof(*matriz)); i++) {
		for (j = 0; j < (sizeof(*matriz) / sizeof(int)); j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
