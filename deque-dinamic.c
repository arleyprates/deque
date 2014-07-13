//
//  deque-dinamic.c
//  Implementacao do tipo Abastrato Deque com apontador alocado dinamicamente
//
//  Created by Arley Prates on 11/07/14.
//  Copyright (c) 2014 ___ARLEYPRATES___. All rights reserved.
//	

#include <stdlib.h>
#include <stdio.h>

typedef struct deque {
	int item;
	struct deque *direita, *esquerda;
}Deque;

int insereEsquerda (Deque *D1, int item) {
	if (D1->direita != NULL) {
		D1->direita->esquerda = (Deque*) malloc (sizeof (Deque));
		if (D1->direita->esquerda == NULL)
			printf ("Erro malloc!\n");	
		D1->direita->esquerda->item = item;
		D1->direita->esquerda->direita = D1->direita;
		D1->direita = D1->direita->esquerda;
		printf("RETORNO4 \n");	
		return 0;
	} else {
		D1->direita = (Deque*) malloc (sizeof (Deque));
		if (D1->direita == NULL)
			printf ("Erro malloc!\n");
		D1->direita->item = item;
		printf("RETORNO5 \n");
		return 0;
	}
	printf("RETORNO3\n");
	return 0;
}

int insereDireita (Deque *D1, int item) {
	Deque *aux;
	aux = D1->direita;
	if (D1->direita != NULL) {
		while (D1->direita != NULL) {
			if (D1->direita->direita == NULL)
				break;
			D1->direita = D1->direita->direita;
			if (D1->direita->direita == NULL)
				break;
		}
		D1->direita->direita = (Deque*) malloc (sizeof (Deque));
		if (D1->direita->direita == NULL)
			printf ("Erro malloc!\n");
		D1->direita->direita->item = item;
		D1->direita->direita->esquerda = D1->direita;
		D1->direita = aux;
		printf("D1->direita->item %d\n", D1->direita->item);
		printf("aux->direita->item %d\n", aux->direita->item);
		printf("RETORNO2\n");
		return 0;
	}
	D1->direita = (Deque*) malloc (sizeof (Deque));
	if (D1->direita == NULL)
		printf ("Erro malloc!\n");	
	D1->direita->item = item;
	//D1->direita->esquerda = D1;
	printf("RETORNO1 \n");
	return 0;
}

void imprime (Deque D1) {
	while (D1.direita != NULL) {
		printf(" %d", D1.direita->item);
		D1.direita = D1.direita->direita;
	}
	printf("\n");
}

Deque* initDeque () {
	Deque *no;
	no = (Deque*) malloc (sizeof (Deque));
	if (no == NULL)
		printf ("Erro malloc !!!\n");
	return no;
}

int removerEsquerda (Deque *D1) {
	Deque aux;
	printf("removerEsquerda \n\n");
	if (D1->direita != NULL) {
		imprime (*D1);
		D1->direita = D1->direita->direita;
		imprime (*D1);
		free (D1->direita->esquerda);
		D1->direita->esquerda = NULL;
		printf ("RETORNO8 \n");
		return 0;
	}
	printf ("RETORNO9 \n");
	return 0;
}

int removerDireita (Deque *D1) {
	Deque aux;
	aux = *D1;
	printf("removerDireita \n\n");
	if (D1->direita != NULL) {
		while (D1->direita != NULL) {
			if (D1->direita->direita == NULL) {
				printf ("BREAK1 \n\n");
				break;
			}
			imprime (*D1);
			D1->direita = D1->direita->direita;
		}
		D1->direita = D1->direita->esquerda->esquerda;
		free (D1->direita->direita->direita);
		D1->direita->direita->direita = NULL;
		D1->direita = &aux;
		D1->direita = D1->direita->direita;
		printf("RETORNO6 \n");
		return 0;
	}
	printf("RETORNO7 \n");
	return 0;
}

int main (int argc, const char *argv[]) {
	Deque *D1;	
	D1 = initDeque ();
	insereDireita (D1, 100);
	printf ("imprime1\n");
	imprime (*D1);
	insereDireita (D1, 200);
	printf ("imprime2\n");
	imprime (*D1);


	removerDireita (D1);
	printf ("imprime3\n");
	imprime (*D1);
	insereDireita (D1, 600);
	printf ("imprime4\n");
	imprime (*D1);
	insereDireita (D1, 700);
	printf ("imprime5\n");
	imprime (*D1);
	removerDireita (D1);
	printf ("imprime6\n");
	imprime (*D1);		
	return 0;
}