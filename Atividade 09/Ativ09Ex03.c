#include <stdio.h>

typedef union {
    int i;
    short int s;
    char ch;
} u_num;

int main(int argc, char *argv[]) {
    u_num u;
    u.i = 33489761;
    printf("Short int: %hd\n", u.s);
    printf("Char: %c\n", u.ch);
    return 0;
}

/*
    | 0000 0001 | 1111 1111 | 0000 0011 | 0110 0001 | = 33489761
    |                      int                      | = 33489761
                            |       short int       | =      865
                                        |    char   | =        a
*/
