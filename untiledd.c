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
	novo->item = -1;
	novo->direita = NULL;
	novo->esquerda = NULL;
	return novo;
}

int insereDireita (Deque *D1, int item) {
	Deque *novo;
	if (D1->direita == NULL && D1->item == -1) {
		novo = createItem ();
		D1->direita = novo;
		D1->direita->item = item;
		D1->direita->esquerda = D1->direita;
	} else {
		novo = createItem();
		D1->direita = novo; // Aponto para um endereco valido 
		D1->direita->esquerda = D1->direita; // Endereco Aponta para um endereco valido
		D1->direita->item = item;
	}
	printf("RETORNANDO 0\n");
	return 0;
}


void imprime (Deque D1) {
	while (D1.direita != NULL) {
		printf ("%d ", (D1.direita)->item);
		D1.direita = D1.direita->direita;
		
	}
}

int main () {

	Deque *D1, *aux;
	D1 = createItem();
	aux = D1;
	insereDireita (D1, 100);
	printf("	Foram ITEM: %d\n", D1->direita->item);
	insereDireita (D1, 200);
	printf("	Fora ITEM: %d\n", D1->direita->item);
	insereDireita (D1, 300);
	printf("	Fora  ITEM: %d\n", D1->direita->item);	

	imprime (*aux);
	return 0;
}