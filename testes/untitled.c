#include <stdio.h>
#include <stdlib.h>

typedef struct deque {
	int item;
	struct deque *direita, *esquerda;
}Deque;

void initDeque (Deque* D1) {
	D1 = (Deque*) malloc (sizeof (Deque));
	D1 = NULL;
	printf ("%p", D1);
	int i;
	scanf ("%d", i);
}

int insereItem (Deque* D1, int item) {

	if (D1 == NULL) {
		Deque* D2;
		D2 = (Deque*) malloc (sizeof (Deque));
		D1->item = item;
		D1->esquerda = NULL;
		D1->direita = D2->esquerda;
		scanf ("%d", item);
	}
	return 0;
}

void imprimeDeque (Deque* D1) {
	printf("!!\n");
	while (D1->direita != NULL) {
		printf ("%d", D1->item);
		D1->direita = D1->esquerda;
	}
}

int main () {

	Deque* D1;
	initDeque (D1);

	printf ("%p", D1);
	int i;
	scanf ("%d", i);

	insereItem (&D1, 100);
	printf ("%d\n", D1.item);
	insereItem (&D1, 200);
	printf ("%d\n", D1.item);
	imprimeDeque (&D1);
	return 0;
}