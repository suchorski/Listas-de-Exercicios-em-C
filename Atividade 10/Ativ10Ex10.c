#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CARROS 5

typedef struct {
	char nome[60];
	char modelo[60];
	int anoFabricacao;
	double valor;
} carro;

int consisteInteiro(char*);
double consisteReal(char*);

int main(int argc, char *argv[]) {
	FILE *fp;
	carro c[CARROS], *pC;
	int i;
	char temp[32];
	fp = fopen("carro.bin", "wb");
	if (!fp) {
		printf("Erro ao abrir o arquivo para gravacao de dados.\n");
		return -3;
	}
	for (i = 0, pC = c; i < CARROS; i++, pC++) {
		do {
			printf("Digite o nome do carro %d: ", i + 1);
			gets(pC->nome);
		} while (!strlen(pC->nome));
		do {
			printf("Digite o modelo do carro %d: ", i + 1);
			gets(pC->modelo);
		} while (!strlen(pC->modelo));
		do {
			do {
				printf("Digite o ano do carro %d (Formato: YYYY): ", i + 1);
				gets(temp);
			} while ((pC->anoFabricacao = consisteInteiro(temp)) < 0);
		} while (pC->anoFabricacao < 1000 || pC->anoFabricacao > 9999);
		do {
			printf("Digite o valor do carro %d: ", i + 1);
			gets(temp);
		} while ((pC->valor = consisteReal(temp)) < 0);
	}
	fwrite(c, sizeof(carro), CARROS, fp);
	if (ferror(fp)) {
		printf("Erro na escrita do arquivo.\n");
		remove("carro.bin");
	}
	fclose(fp);
	return 0;
}

int consisteInteiro(char *numero) {
	int i;
	char *pN;
	for (i = 0, pN = numero; i < strlen(numero); i++, pN++) {
		if (!isdigit(*pN)) {
			return -1;
		}
	}
	return atoi(numero);
}

double consisteReal(char *numero) {
	int i;
	short int contaPonto = 0;
	char *p;
	for (i = 0, p = numero; i < strlen(numero); i++, p++) {
		if (!isdigit(*p) && *p != '.') {
			return -1;
		}
		if (*p == '.' && contaPonto++) {
			return -1;
		}
		if (i == 0 || i == strlen(numero) - 1) {
			if (*p == '.') {
				return -1;
			}
		} else {
			if (*p == '.' && !isdigit(*(p-1)) && !isdigit(*(p+1))) {
				return -1;
			}
		}
	}
	return atof(numero);
}
