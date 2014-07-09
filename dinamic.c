#include <stdio.h>
#include <stdlib.h>



typedef struct deque {
	int item;
	struct deque *direita, *esquerda;
}Deque;

void initDeque (Deque *D1) {
	D1 = (Deque*) malloc (sizeof (Deque));
	D1->item = 0;
	D1->direita = NULL;
	D1->esquerda = NULL;
}

Deque* createItem (Deque *D1) {
 	/*
 	//CONDICAO PARA SEGUNDA VEZ EM DIANTE
 	if (D1->esquerda == 0) {
 		D1 = (Deque*) malloc (sizeof (Deque));
		if (!D1) {
			printf ("\nErro de Alocacao!\n");
			exit (EXIT_FAILURE);
		}
		D1->item = 0;
		D1->direita = NULL;
		D1->esquerda = NULL;
		return D1;	
 	}
	*/
 	//INSTRUCOES PARA PRIMEIRA VEZ
	D1 = (Deque*) malloc (sizeof (Deque));
	if (!D1) {
		printf ("\nErro de Alocacao!\n");
		exit (EXIT_FAILURE);
	}
	D1->item = 0;
	D1->direita = NULL;
	D1->esquerda = NULL;
	return D1;
}

int insereDireita (Deque *D1, int x) {
	//INSTRUCOES PARA A PRIMEIRA INSERSCAO
	if (D1->direita == NULL) {
		Deque *novo, *teste;
		teste = createItem (novo);
//		printf ("\nItem criado com Sucesso!\n");
//		printf ("\n%d\n", D1->item);
		D1->item = x;
		D1->direita = teste->esquerda;
		printf ("\n%d\n", D1->item);
		return 1;
	}
	return 0;
}

void imprimeDeque (Deque D1) {
	while (D1.direita != NULL)
		printf ("%d ", D1.item);
}

int main () {

	Deque D1;
	initDeque (&D1);
	insereDireita (&D1, 100);
	insereDireita (&D1, 200);
	insereDireita (&D1, 300);
	insereDireita (&D1, 400);
	//imprimeDeque (D1);
	return 0;
}