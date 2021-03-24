#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n[] = { 7, 1, 4, 5, 0, 0, 7, -2, 13, 8};
    //int n[] = { 3, 5, -1, 4, 1, 18, 0, -5, 2, 8};
    //int n[] = { 8, 1, 0, 4, 7, 18, 0, -5, 3, 8};
    //int n[] = {-1, 6, 3, 7, 7, 18, 0, -7, 3, 8};
    int v = 1, *p = n, *pF = n + 9, soma = *n, t;
    while (*p) {
        p += *p;
        while (p > pF || p < n) {
            p = p + ((p > pF) ? -10 : +10);
        }
        t = pow(2, (p - n + 1));
        if (t & v) {
            printf("Loop Eterno!\n");
            exit(0);
        }
        v += t;
        soma += *p;
    }
    printf("Soma: %d\n", soma);
    return 0;
}
