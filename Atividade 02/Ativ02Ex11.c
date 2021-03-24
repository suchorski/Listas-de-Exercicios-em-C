#include <stdio.h>

int main(int argc, char *argv[]) {
	int matriz[3][3], i, j, k, som = 0, dif = 0, tms = 1, tmd = 1;
	for (i = 0, j = 0; i < (sizeof(matriz) / sizeof(int)); i++) {
		printf("Digite o valor linha %d x coluna %d: ", (j + 1), (i % 3 + 1));
		scanf("%d", &matriz[j][(i % 3)]);
		if (i % 3 == 2) {
			j++;
		}
	}
	/*for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("Digite o valor linha %d x coluna %d: ", (i + 1), (j + 1));
			scanf("%d", &matriz[i][j]);
		}
	}*/
	for (i = 0, j = 0, k = 0; i < (sizeof(matriz) / sizeof(int)); i++, j++) {
		/* (i % 3)       de 0 até 8  =  0 1 2  0 1 2  0 1 2;
		   ((j + k) % 3) de 0 até 8  =  0 1 2  1 2 0  2 0 1 (k aumenta a cada 3 loops) e
		   ((8 - j + k) % 3) faz o contrário de ((j + k) % 3) */
		tms *= matriz[(i % 3)][((j + k) % 3)];
		tmd *= matriz[(i % 3)][((8 - j + k) % 3)];
		if (i % 3 == 2) {
			k++;
			som += tms;
			dif += tmd;
			tmd = tms = 1;
		}
	}
	printf("Determinante: %d\n", (som - dif));
	return 0;
}
