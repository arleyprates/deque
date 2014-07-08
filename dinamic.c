#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int item;
	struct deque *prox;
	struct deque *ante;
}Deque;

void initDeque (Deque *D1, int Max) {

	D1 = (Deque*) malloc (sizeof (Deque));
	if (!D1) {
		printf ("\nErro de Alocacao!\n");
		exit (EXIT_FAILURE);
	}
	D1->item = 0;
	D1->prox = NULL;
	D1->ante = NULL;
}

int main () {

	Deque D1;
	
	initDeque (&D1, 100);

	return 0;
}