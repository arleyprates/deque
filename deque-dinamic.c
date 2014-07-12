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

int removerDireita (Deque *D1, int item) {
	Deque aux, *auxiliar;
	aux = *D1;
	auxiliar = D1;
	printf("removerDireita \n");

	if (auxiliar->direita != NULL) {
		while (auxiliar->direita != NULL) {
			//printf("aux->direita->item %d\n", aux.direita->item);
			//printf("D1->direita->item %d\n", D1->direita->item);
			//printf("auxiliar->direita->item %d\n\n", auxiliar->direita->item);
			if (auxiliar->direita->direita == NULL) {
				printf ("BREAK1 \n\n");
				break;
			}
			imprime (*D1);
			auxiliar->direita = auxiliar->direita->direita;
			//imprime (*D1);
		}

		imprime (*D1);

		D1->direita = auxiliar->direita;

		imprime (*D1);
		
		//D1->direita = auxiliar->direita->esquerda;
		//free (D1->direita->direita->esquerda);
		
		//printf("D1->direita->esquerda->item %d \n", D1->direita->esquerda->item);
		
		D1->direita = D1->direita->esquerda->esquerda;

		imprime (*D1);		

		//printf("D1->direita->item %d \n", D1->direita->item);
		//printf("D1->direita->direita->item %d\n", D1->direita->direita->direita->item);
		
		D1->direita->direita->direita = NULL;
		imprime (*D1);

		D1->direita = &aux;
		imprime (*D1);

		D1->direita = D1->direita->direita;

		printf("D1->direita->item %d\n", D1->direita->item);
		imprime (*D1);


		printf("RETORNO6 \n");
		return 0;




















		free (D1->direita->esquerda);
		D1->direita->esquerda = NULL;

		return 0;
		D1->direita->direita->esquerda = NULL;
		printf("D1->direita->item %d \n", D1->direita->item);
		//free (D1->direita->direita->direita);
		D1->direita->direita = NULL;
		imprime (*D1);
		printf("D1->direita->item %d \n", D1->direita->item);
		printf("aux.direita->item %d \n", aux.direita->item);
		printf("D1->direita %p\n", D1->direita->esquerda);
		printf("RETORNO6 \n");
		return 0;
	}
	printf("RETORNO7 \n");
	printf("D1->direita->item %d\n", D1->direita->item);
	printf("D1->direita->direita %p\n", D1->direita->esquerda);
	return 0;
}

int main (int argc, const char *argv[]) {
	Deque *D1;	
	D1 = initDeque ();
	insereEsquerda (D1,	10);
	insereEsquerda (D1,	20);
	insereEsquerda (D1,	30);
	insereEsquerda (D1,	40);
	insereEsquerda (D1,	50);
	insereEsquerda (D1,	60);
	//insereDireita (D1, 5);
	insereEsquerda (D1,	70);
	imprime (*D1);
	removerDireita (D1, 10);
	imprime (*D1);
	
	return 0;
}