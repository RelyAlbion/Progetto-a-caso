#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//
typedef struct Elem {
	long val;
	char str[50];
	struct Elem *next;
}Elem;
typedef Elem *List;


List crea1() {
	List a,b;
	char f[50], *d[50];
	int i=0,n=0;
	FILE *x;
	x = fopen("text1.txt", "r");
	if (x == NULL) {
		printf("ERRORE APERTURA FILE");
		exit(1);
	}
	a = malloc(sizeof(List));
	*d= fgets(f,50,x);
	while (f[i] != '\n') {
		if (f[i] >= '0' && f[i] <= '9')
			a->val = atoi(d[i]);
		if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 'a' && f[i] <= 'z')) {
			a->str[n] = f[i];
			n++;
		}
		i++;
	}
	a->str[n] = '\0';
	a->next = NULL;
	b = a;
	i = 0;
	n = 0;
	while (!feof(x)) {
		b->next =malloc(sizeof(List));
		b = b->next;
		*d = fgets(f, 50, x);
		while (f[i] != '\n') {
			if (f[i] >= '0' && f[i] <= '9')
				b->val = atoi(d[i]);
			if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 'a' && f[i] <= 'z')) {
				b->str[n] = f[i];
				n++;
			}
			i++;
		}
		b->str[n] = '\0';
		b->next = NULL;
		n = 0;
		i = 0;
	} b->next = NULL;
	fclose(x);
	return a;
}

void visualizza(List a) {
	while (a != NULL) {
		printf("%d", a->val);
		puts(a->str);
		a = a->next;
	}
}


void main(void) {
	List a;
	a = crea1();
	visualizza(a);
	//b = crea2();
}