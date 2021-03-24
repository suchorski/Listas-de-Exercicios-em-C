#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {A = 1, B, C, D, E} nota;

typedef struct {
	char nomeAluno[60];
	nota n;
} aluno;

void ler(aluno*);
void exibir(aluno*);
int consisteNota(char*);

int main(int argc, char *argv[]) {
	aluno a;
	ler(&a);
	exibir(&a);
	return 0;
}

void ler(aluno *a) {
	int nota;
	char notaTemp[3];
	do {
		printf("Digite o nome do aluno: ");
		gets(a->nomeAluno);
	} while (!strlen(a->nomeAluno));
	do {
		printf("Digite a nota do aluno (0 a 100): ");
		gets(notaTemp);
	} while ((nota = consisteNota(notaTemp)) < 0);
	if (nota <= 100 && nota >= 90) {
		a->n = A;
	} else if (nota >= 80) {
		a->n = B;
	} else if (nota >= 70) {
		a->n = C;
	} else if (nota >= 60) {
		a->n = D;
	} else if (nota >= 0) {
		a->n = E;
	}
}

void exibir(aluno *a) {
	switch (a->n) {
		case A:
			printf("Excelente %s!\n", a->nomeAluno);
			break;
		case B:
			printf("Otimo %s!\n", a->nomeAluno);
			break;
		case C:
		case D:
			printf("Caro %s, fez nada além de sua obrigação.", a->nomeAluno);
			break;
		case E:
			printf("Caro %s, voce foi reprovado.", a->nomeAluno);
			break;
	}
}

int consisteNota(char *notaTmp) {
	int i, nota;
	char *pN;
	for (i = 0, pN = notaTmp; i < strlen(notaTmp); i++, pN++) {
		if (!isdigit(*pN)) {
			return -1;
		}
	}
	if ((nota = atoi(notaTmp)) > 100) {
		return -1;
	}
	return nota;
}
