#include <stdio.h>

int main(int argc, char *argv[]) {
	char c;
	printf("Digite uma letra de 'a' a 'z':\n");
	scanf("%c", &c);
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("%c é uma vogal.", c);
			break;
		default:
			printf("%c é uma consoante.", c);
	}
	return 0;
}
