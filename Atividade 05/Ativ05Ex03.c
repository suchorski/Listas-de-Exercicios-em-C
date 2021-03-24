#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[50];
    short int idade;
    char telefone[16];
    short int ativo;
} aluno;

void gravaAluno(aluno[], int, int, short int);
void salvar(aluno[], int);
void atualizar(aluno[], int);
void excluir(aluno[], int);
void pesquisar(aluno[], int);
void listar(aluno[], int);

int main(int argc, char *argv[]) {
    int menu, i;
    aluno a[100];
    for (i = 0; i < sizeof(a) / sizeof(aluno); i++) {
        a[i].ativo = 0;
    }
    do {
        printf("========================\n");
        printf("   Cadastro de alunos\n");
        printf("========================\n");
        printf("1 - Salvar\n");
        printf("2 - Atualizar\n");
        printf("3 - Excluir\n");
        printf("4 - Pesquisar\n");
        printf("5 - Listar\n");
        printf("6 - Encerrar\n");
        printf("Comando: ");
        scanf("%d", &menu);
        switch (menu) {
        case 1:
            salvar(a, sizeof(a) / sizeof(aluno));
            break;
        case 2:
            atualizar(a, sizeof(a) / sizeof(aluno));
            break;
        case 3:
            excluir(a, sizeof(a) / sizeof(aluno));
            break;
        case 4:
            pesquisar(a, sizeof(a) / sizeof(aluno));
            break;
        case 5:
            listar(a, sizeof(a) / sizeof(aluno));
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Código inválido\n\n");
        }
    } while (menu != 6);
    return 0;
}

void salvar(aluno a[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (!a[i].ativo) {
            break;
        }
    }
    gravaAluno(a, tam, i, 1);
}

void atualizar(aluno a[], int tam) {
    int matricula, i;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    for (i = 0; i < tam; i++) {
        if (matricula == a[i].matricula && a[i].ativo) {
            gravaAluno(a, tam, i, 0);
            printf("Aluno alterado!\n");
            break;
        }
    }
    if (i == tam) {
        printf("Aluno não encontrado!\n");
    }
}

void excluir(aluno a[], int tam) {
    int matricula, i;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    for (i = 0; i < tam; i++) {
        if (matricula == a[i].matricula && a[i].ativo) {
            a[i].ativo = 0;
            printf("Aluno excluído!\n");
            break;
        }
    }
    if (i == tam) {
        printf("Aluno não encontrado!\n");
    }
}

void pesquisar(aluno a[], int tam) {
    int matricula, i;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    for (i = 0; i < tam; i++) {
        if (matricula == a[i].matricula && a[i].ativo) {
            printf("Matrícula: %d\n", a[i].matricula);
            printf("Nome: %s\n", a[i].nome);
            printf("Idade: %hd\n", a[i].idade);
            printf("Telefone: %s\n", a[i].telefone);
            break;
        }
    }
    if (i == tam) {
        printf("Aluno não encontrado!\n");
    }
}

void listar(aluno a[], int tam) {
    int i, vazio = 1;
    for (i = 0; i < tam; i++) {
        if (a[i].ativo) {
            vazio = 0;
            printf("%d: '%s', %hd anos (Telefone: %s)\n", a[i].matricula, a[i].nome, a[i].idade, a[i].telefone);
        }
    }
    if (vazio) {
        printf("Nenhum aluno cadastrado!\n");
    }
}

void gravaAluno(aluno a[], int tam, int pos, short int novaMatricula) {
    int i;
    if (novaMatricula) {
        do {
            printf("Digite a matricula do aluno: ");
            scanf("%d", &a[pos].matricula);
            for (i = 0; i < tam; i++) {
                if (a[pos].matricula == a[i].matricula && a[i].ativo) {
                    break;
                }
            }
        } while (i != tam);
    }
    a[pos].ativo = 1;
    printf("Digite o nome do aluno: ");
    getc(stdin);
    gets(a[pos].nome);
    printf("Digite a idade do aluno: ");
    scanf("%hd", &a[pos].idade);
    printf("Digite o telefone do aluno: ");
    getc(stdin);
    gets(a[pos].telefone);
}
