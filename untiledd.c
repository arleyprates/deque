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
		printf("if \n");
		//D1->item = item;
		novo = createItem ();
		D1->direita = novo;
		D1->direita->item = item;
		//novo = createItem();
		printf("D1->direita IF: %p\n", D1->direita);
		//D1->direita = novo;
		//D1->direita->esquerda = D1->direita;

		//printf("kkkkk %p\n", novo->esquerda);
		//printf ("ELEEEE %p\n", D1->direita);
		//printf("haaaaaa %p\n", D1->direita->direita);
	} else {
		//if (D1->direita->direita != NULL){
		printf("D1->direita ELSE: %p\n", D1->direita);
		//printf ("D1->direita->item ELSE: %d", D1->direita->item);
		novo = createItem();
		D1->direita = novo; // Aponto para um endereco valido 
		D1->direita->esquerda = D1->direita; // Endereco Aponta para um endereco valido
		printf ("D1->direita->item ELSE: %d\n", D1->direita->item);
		D1->direita->item = item;
		printf ("D1->direita->item ELSE: %d\n", D1->direita->item);
		printf("D1->direita->direita ELSE:   %p\n", D1->direita->direita);
		//printf("D1->esquerda->item ELSE:   %d\n", D1->esquerda->item);
		//}
	}

/*	} else {
		printf ("else \n");
		novo = createItem ();
		printf("QUEM %p\n", D1->direita);
		if (D1->direita != NULL) {
			printf("if 2!\n");
			D1->direita->item = item;
			D1->direita = D1->direita->direita;
			printf("QUEM %p\n", D1->direita);
			//printf("simmmm %p\n", D1->direita->esquerda);
			
			//D1->direita->direita = novo;
			//novo->esquerda = D1->direita->direita;
			printf("if 2 item %d\n", D1->item);
			printf("RETORNANDO 1\n");
			return 1;
		}
	}
	//novo = createItem ();
	//D1->item = item;
	*/
	printf("RETORNANDO 0\n");
	return 0;
}


void imprime (Deque D1) {
	while (D1.direita != NULL) {
		D1.direita = D1.direita->direita;
		printf ("%d ", D1.item);
	}
}

int main () {

	Deque* D1;
	D1 = createItem();
	
	insereDireita (D1, 100);
	printf("	Foram ITEM: %d\n", D1->direita->item);
	insereDireita (D1, 200);
	printf("D1->direita: %p\n", D1->direita);
	printf("	Fora ITEM: %d\n", D1->direita->item);
	insereDireita (D1, 300);
	printf("	Fora  ITEM: %d\n", D1->direita->item);
	//		printf("Fora! %d\n", D1->item);
	//printf ("%d\n", D1->item);
	

	//imprime (*D1);
	return 0;
}