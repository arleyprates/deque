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
	Deque *novo, *aux;
		
	if (!D1) {
		printf("EXISTE\n");
	}

	novo = createItem ();
	*D1 = *novo;
	printf("D1->item %d\n", D1->item);
	D1->item = item;
	printf("D1: %p\n", D1);
	printf("D1->direita %p\n", D1->direita);
	D1->direita = D1;
	printf("D1->direita %p\n", D1->direita);
	
	/*
	else {
		//printf ("D1->direita ELSE %p\n", D1->direita);
		//aux = createItem();
		//if (D1->direita == NULL)
		novo = createItem();
		*D1->direita = *novo->esquerda;
		D1->direita->item = item;

		printf("D1->item: %d e D1->direita->item: %d\n", D1->item, D1->direita->item);
		//novo = createItem();
		
		//D1->direita = novo; // Aponto para um endereco valido 
		//D1->direita->item = item;
		//D1->direita->esquerda = aux; // Endereco Aponta para um endereco valido
		
		//printf("novo ELSE: %p\n", novo);
		printf("D1->direita->esquerda ELSE: %p\n", D1->direita->esquerda);
	}*/
	printf("RETORNANDO 0\n");
	return 0;
}


/*void imprime (Deque D1) {
	//printf("D1.esquerda IMPRIME: %p\n", D1.esquerda);
	printf("D1.direita->esquerda IMPRIME: %p\n", D1.direita->esquerda);
	while (D1.direita->esquerda != NULL) {
		printf ("%d ", D1.direita->item);
		D1.direita = D1.direita->esquerda;	

	}
}
*/
int main () {

	Deque D1;
	insereDireita (&D1, 100);
	//printf("	Fora ITEM: %d\n", D1.item); 
	insereDireita (&D1, 200);
	//printf("	Fora ITEM: %d\n", D1.item);
	/*
	insereDireita (D1, 300);
	printf("	Fora  ITEM: %d\n", D1->direita->item);	
	//printf ("D1 %p\n", D1);
	imprime (*D1); */
	return 0;
}