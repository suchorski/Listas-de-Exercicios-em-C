#include <stdio.h>

typedef struct {
	char logradouro[60];
	int numero;
	char bairro[60];
	char cidade[60];
	char uf[3];
	long int cep;
} endereco;

typedef struct {
	int codigo;
	char cpf[12];
	char nome[60];
	endereco end;
} cliente;

void leCliente(cliente*);
void imprimeCliente(cliente*);

int main(int argc, char *argv[]) {
	cliente c;
	leCliente(&c);
	imprimeCliente(&c);
	return 0;
}

void leCliente(cliente *c) {
	printf("Digite o codigo do cliente: ");
	scanf("%d", &c->codigo);
	printf("Digite o cpf do cliente: ");
	getc(stdin);
	gets(c->cpf);
	printf("Digite o nome do cliente: ");
	gets(c->nome);
	printf("Digite o logradouro do cliente: ");
	gets(c->end.logradouro);
	printf("Digite o numero da casa: ");
	scanf("%d", &c->end.numero);
	printf("Digite o bairro do cliente: ");
	getc(stdin);
	gets(c->end.bairro);
	printf("Digite a cidade do cliente: ");
	gets(c->end.cidade);
	printf("Digite o estado do cliente: ");
	gets(c->end.uf);
	printf("Digite o CEP do cliente: ");
	scanf("%ld", &c->end.cep);
}

void imprimeCliente(cliente *c) {
	printf("Codigo do cliente: %d\n", c->codigo);
	printf("Cpf do cliente: %s\n", c->cpf);
	printf("Nome do cliente: %s\n", c->nome);
	printf("Logradouro do cliente: %s\n", c->end.logradouro);
	printf("Numero da casa: %d\n", c->end.numero);
	printf("Bairro do cliente: %s\n", c->end.bairro);
	printf("Cidade do cliente: %s\n", c->end.cidade);
	printf("Estado do cliente: %s\n", c->end.uf);
	printf("CEP do cliente: %ld\n", c->end.cep);
}
