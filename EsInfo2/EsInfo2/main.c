#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
	long val;
	char str[50];
	struct Elem *next;
} Elem;
typedef Elem *List;

Elem *crea1() {
	Elem *a, *b;
	char f[50];
	FILE *x = fopen("text1.txt", "r");
	if (x == NULL)
		exit(1);

	a = (Elem *)malloc(sizeof(Elem));
	fgets(f, 50, x);
	sscanf(f, "%ld, \"%s\"", &a->val, a->str);
	int z;
	for (z = 0; a->str[z] != '\0'; z++);
	z--;
	a->str[z] = '\0';

	b = a;

	while (!feof(x)) {
		b->next = (Elem *)malloc(sizeof(Elem));
		b = b->next;
		fgets(f, 50, x);
		sscanf(f, "%ld, \"%s\"", &b->val, b->str);
		for (z = 0; b->str[z] != '\0'; z++);
		z--;
		b->str[z] = '\0';
	}
	b->next = NULL;
	fclose(x);
	return a;
}

void visualizza(Elem *a) {
	while (a != NULL) {
		printf("%d\t", a->val);
		puts(a->str);
		a = a->next;
	}
}

void main(void) {
	Elem *a;
	a = crea1();
	visualizza(a);
	//b = crea2();
}