#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define doisNumeros

typedef enum { erro, somar, subtrair, multiplicar, dividir } oper;

int consisteNumero(char*);
void executaOperacao(float*, int, oper, float*);

int main(int argc, char *argv[]) {
	oper op = erro, i;
	char opers[][15] = { "somar", "subtrair", "multiplicar", "dividir" };
	float *numeros, *p, resultado;
	#ifdef doisNumeros
	if (argc != 4) {
		printf("Metodo de uso: matematica.exe <Operacao> <Numero 1> <Numero 2>\nAs operacoes sao: somar, subtrair, multiplicar, dividir.\n");
		return -2;
	}
	#else
	if (argc < 4) {
		printf("Metodo de uso: matematica.exe <Operacao> <Numero 1> <Numero 2> ... <Numero N>\nAs operacoes sao: somar, subtrair, multiplicar, dividir.\n");
		return -2;
	}
	#endif
	for (i = 0; i < sizeof(opers) / sizeof(opers[i]); i++) {
		if (!strcmp(opers[i], argv[1])) {
			op = i + 1;
			break;
		}
	}
	if (!op) {
		printf("As operacoes disponiveis sao: somar, subtrair, multiplicar, dividir.\n");
		return -2;
	}
	numeros = (float*) malloc((argc - 2) * sizeof(float));
	if (!numeros) {
		printf("Erro de alocacao de memoria.\n");
		return -1;
	}
	for (i = 2, p = numeros; i < argc; i++, p++) {
		if (!consisteNumero(argv[i])) {
			printf("O argumento %d precisa ser um numero.\n", i);
			return -2;
		}
		*p = atof(argv[i]);
		if (i > 2 && !*p && op == dividir) {
			printf("Impossivel dividir por zero.\n");
			return 0;
		}
	}
	executaOperacao(numeros, argc - 2, op, &resultado);
	printf("%.5f\n", resultado);
	return 0;
}

int consisteNumero(char *numero) {
	int i;
	short int contaPonto = 0;
	char *p;
	for (i = 0, p = numero; i < strlen(numero); i++, p++) {
		if (!isdigit(*p) && *p != '-' && *p != '.') {
			return 0;
		}
		if (i == 0 && *p == '-' && *(p+1) == '\0') {
			return 0;
		}
		if (i > 1 && *p == '-') {
			return 0;
		}
		if (*p == '.' && contaPonto++) {
			return 0;
		}
		if (i == 0 || i == strlen(numero) - 1) {
			if (*p == '.') {
				return 0;
			}
		} else {
			if (*p == '.' && !isdigit(*(p-1)) && !isdigit(*(p+1))) {
				return 0;
			}
		}
	}
	return 1;
}

void executaOperacao(float *numeros, int tam, oper op, float *resultado) {
	int i;
	float *p;
	*resultado = *numeros;
	for (i = 1, p = numeros + 1; i < tam; i++, p++) {
		switch (op) {
			case somar:
				*resultado += *p;
				break;
			case subtrair:
				*resultado -= *p;
				break;
			case multiplicar:
				*resultado *= *p;
				break;
			case dividir:
				*resultado /= *p;
				break;
			default:
				break;
		}
	}
	return;
}
