#include <stdio.h>
#include <stdlib.h>

typedef struct deque {
	int item;
	struct deque *direita, *esquerda;
}Deque;

Deque* createItem () {
	Deque *novo;
	novo = (Deque*) malloc (sizeof (Deque));
	if (novo == NULL)
		printf ("erro!!!\n");
	novo->direita = NULL;
	novo->esquerda = NULL;
	return novo;
}

int insereDireita (Deque **D1, int item) {
	Deque *aux, *novo;
	novo = createItem ();
	
	/*if (D1 != NULL) {
		novo->item = item;
		D1 = novo;
		printf ("%d\n", novo->item);
		return 1;
	}*/

}
/*
void imprime (Deque D1) {
	while (D1.direita != NULL) {
		D1.direita = D1.direita->direita;
		printf ("%d ", D1.item);
	}
	printf ("%d\n", D1.item);
} */

int main () {

	Deque** D1;
	D1 = createItem();
	
	insereDireita (&D1, 100);
	

	//imprime (*D1);
	return 0;
}