#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	short int dia;
	short int mes;
	int ano;
} data;

int consisteNumero(char*);

int main(int argc, char *argv[]) {
	FILE *fp;
	data d;
	char temp[8];
	fp = fopen("data.txt", "w");
	if (!fp) {
		printf("Erro ao abrir o arquivo data.txt.\n");
		return -3;
	}
	do {
		printf("Digite o dia: ");
		gets(temp);
	} while ((d.dia = (short int) consisteNumero(temp)) < 0 && (d.dia < 1 || d.dia > 31));
	do {
		printf("Digite o mes: ");
		gets(temp);
	} while ((d.mes = (short int) consisteNumero(temp)) < 0 && (d.mes < 1 || d.mes > 12));
	do {
		printf("Digite o ano: ");
		gets(temp);
	} while ((d.ano = consisteNumero(temp)) < 0 && d.ano < 1);
	fprintf(fp, "%hd %hd %d", d.dia, d.mes, d.ano);
	fclose(fp);
	return 0;
}

int consisteNumero(char *numero) {
	int i;
	char *pN;
	for (i = 0, pN = numero; i < strlen(numero); i++, pN++) {
		if (!isdigit(*pN)) {
			return -1;
		}
	}
	return atoi(numero);
}
