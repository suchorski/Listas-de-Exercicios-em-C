#include <stdio.h>
#include <stdlib.h>

struct lista {
	char info;
	struct lista *prox;
};

typedef struct lista TLista;


TLista* inicializa() {
	return NULL;
}

TLista* insere(TLista* l, char c) {
	TLista* novo = (TLista*) malloc(sizeof(TLista));
	novo->info = c;
	novo->prox = l;
	return novo;
}

void imprime(TLista* l) {
	TLista* aux;
	for (aux=l; aux != NULL; aux = aux->prox) {
		printf("info = %c\n", aux->info);
	}
}

void imprimeInvertido(TLista* l) {
	if (!l->prox) {
		printf("info = %c\n", l->info);
		return;
	}
	imprimeInvertido(l->prox);
	printf("info = %c\n", l->info);
}

int tamanho(TLista* l) {
	int tamanho = 0;
	TLista *pl = l;
	#ifdef HARDCORE
		for (; pl; pl = pl->prox, tamanho++);
	#else
		while (pl) {
			tamanho++;
			pl = pl->prox;
		}
	#endif
	return tamanho;
}

TLista* retira(TLista* l, char c) {
	TLista *pl = l, *aux = l;
	if (!pl) {
		return NULL;
	} else if (pl->info == c) {
		pl = pl->prox;
		free(aux);
		return pl;
	} else {
		while ((aux = pl->prox) != NULL) {
			if (aux->info == c) {
				pl->prox = aux->prox;
				free(aux);
				break;
			}
			pl = aux;
		}
	}
	return l;
}

TLista* limpar(TLista* l) {
	#ifdef HARDCORE
		while ((l = retira(l, l->info)));
	#else
		while (l) {
			l = retira(l, l->info);
		}
	#endif
	return NULL;
}

int main (int argc, char* argv[]) {
	TLista* Listax;
	Listax = inicializa();
	Listax = insere(Listax, 'D');
	Listax = insere(Listax, 'I');
	Listax = insere(Listax, 'O');
	Listax = insere(Listax, 'L');
	Listax = insere(Listax, 'A');
	Listax = insere(Listax, 'X');
	Listax = insere(Listax, 'O');
	printf("Tamanho: %d\n", tamanho(Listax));

	Listax = retira(Listax,'D');
	Listax = retira(Listax,'I');
	Listax = retira(Listax,'X');
	Listax = retira(Listax,'O');
	printf("Tamanho: %d\n", tamanho(Listax));

	Listax = retira(Listax,'Z');
	printf("Tamanho: %d\n", tamanho(Listax));

	imprime(Listax);
	imprimeInvertido(Listax);

	Listax = limpar(Listax);
	printf("Tamanho: %d\n", tamanho(Listax));

	return 0;
}
