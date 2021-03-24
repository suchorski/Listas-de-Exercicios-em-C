#include <stdio.h>

int main(int argc, char *argv[]) {
	int matriz[][] = { {11, 12, 13, 14}, {21, 22, 23, 24}, {31, 32, 33, 34}}, i;
	/* For Básico
	int j;
	for (i = 0; i < (sizeof(matriz) / sizeof(*matriz)); i++) {
		for (j = 0; j < (sizeof(*matriz) / sizeof(int)); j++) {
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	*/
	/* For Especial (Economizando 4 bytes de memória no inteiro 'j' que pode ser removido) */
	for (i = 0; i < (sizeof(matriz) / sizeof(int)); i++) {
		/*	i = 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 (em binário)
			i >> 2 = 00 00 00 00 01 01 01 01 10 10 10 10
				Remove os dois primeiros bits e com o restante faz-se uma contagem de 0 0 0 0, 1 1 1 1, 2 2 2 2, ...
			i & 3 = 00 01 10 11 00 01 10 11 00 01 10 11
				Com os dois primeiros bits faz-se uma contagem de 0 1 2 3, 0 1 2 3, 0 1 2 3, ... */
		printf("%d%c", matriz[(i >> 2)][(i & 3)], (i % 4 == 3) ? '\n' : '\t');
	}
	return 0;
}
