#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

int main(int argc, char *argv[]) {
    data d;
    char mes[16];
    printf("Digite o dia da data: ");
    scanf("%d", &d.dia);
    printf("Digite o mes da data: ");
    scanf("%d", &d.mes);
    printf("Digite o ano da data: ");
    scanf("%d", &d.ano);
    switch (d.mes) {
        case 1: strcpy(mes, "janeiro"); break;
        case 2: strcpy(mes, "fevereiro"); break;
        case 3: strcpy(mes, "marco"); break;
        case 4: strcpy(mes, "abril"); break;
        case 5: strcpy(mes, "maio"); break;
        case 6: strcpy(mes, "junho"); break;
        case 7: strcpy(mes, "julho"); break;
        case 8: strcpy(mes, "agosto"); break;
        case 9: strcpy(mes, "setembro"); break;
        case 10: strcpy(mes, "outubro"); break;
        case 11: strcpy(mes, "novembro"); break;
        case 12: strcpy(mes, "dezembro"); break;
    }
    printf("%d de %s de %d.\n", d.dia, mes, d.ano);
    return 0;
}
