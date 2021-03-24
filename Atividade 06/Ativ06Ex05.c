#include <stdio.h>

typedef struct {
    short int dia;
    short int mes;
    int ano;
} data;

void leData(data*);
void imprimeData(data*);

int main(int argc, char *argv[]) {
    data d;
    leData(&d);
    imprimeData(&d);
    return 0;
}

void leData(data *d) {
    printf("Digite o dia: ");
    scanf("%hd", &d->dia);
    printf("Digite o mes: ");
    scanf("%hd", &d->mes);
    printf("Digite o ano: ");
    scanf("%d", &d->ano);
}

void imprimeData(data *d) {
    printf("Data: %.2hd/%.2hd/%.4hd", d->dia, d->mes, d->ano);
}
