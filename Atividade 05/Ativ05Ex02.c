#include <stdio.h>

typedef struct {
    char materia[50];
    char professor[50];
} disciplina;

typedef struct {
    int matricula;
    char nome[50];
    disciplina d;
} aluno;

int main(int argc, char *argv[]) {
    aluno a;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &a.matricula);
    printf("Digite o nome do aluno: ");
    getc(stdin);
    gets(a.nome);
    printf("Digite o nome da disciplina: ");
    gets(a.d.materia);
    printf("Digite o nome do professor: ");
    gets(a.d.professor);
    printf("A matricula %d pertence ao aluno(a) %s que momentaneamente esta cursando a disciplina %s com o professor(a) %s.", a.matricula, a.nome, a.d.materia, a.d.professor);
    return 0;
}
