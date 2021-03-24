#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nomeAluno[60];
	int nota;
} pontuacao;

void extraiDados (pontuacao*, int, pontuacao*, pontuacao*, double*);

int main(int argc, char *argv[]) {
	int tam, i;
	double avg;
	pontuacao *alunos, *p, min, max;
	printf("Digite o número de alunos: ");
	scanf("%d", &tam);
	alunos = (pontuacao*) malloc(tam * sizeof(pontuacao));
	if (!alunos) {
		printf("Erro de alocacao de memoria...\n");
		exit(-1);
	}
	for (i = 0, p = alunos; i < tam; i++, p++) {
		printf("Digite o nome do aluno %d: ", i + 1);
		getc(stdin);
		gets(p->nomeAluno);
		printf("Digite o nota do aluno %d: ", i + 1);
		scanf("%d", &p->nota);
	}
	extraiDados(alunos, tam, &min, &max, &avg);
	printf("Pior aluno (%s) tirou: %d\n", min.nomeAluno, min.nota);
	printf("Melhor aluno (%s) tirou: %d\n", max.nomeAluno, max.nota);
	printf("Nota media: %.2lf\n", avg);
	free(alunos);
	return 0;
}

void extraiDados (pontuacao *v, int tam, pontuacao *min, pontuacao *max, double *avg) {
	pontuacao *p = v, *pF = v + tam;
	strcpy(min->nomeAluno, p->nomeAluno);
	strcpy(max->nomeAluno, p->nomeAluno);
	min->nota = max->nota = p->nota;
	*avg = p->nota;
	for (p++; p < pF; p++) {
		if (p->nota < min->nota) {
			strcpy(min->nomeAluno, p->nomeAluno);
			min->nota = p->nota;
		}
		if (p->nota > max->nota) {
			strcpy(max->nomeAluno, p->nomeAluno);
			max->nota = p->nota;
		}
		*avg += p->nota;
	}
	*avg /= tam;
}
