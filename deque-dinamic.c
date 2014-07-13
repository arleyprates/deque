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

void imprime (Deque D1) {
	while (D1.direita != NULL) {
		printf(" %d", D1.direita->item);
		D1.direita = D1.direita->direita;
	}
	printf("\n");
}

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
	// INSERE UM SEGUNDO ELEMENTO
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
	//INSERE UM ELEMENTO
	D1->direita = (Deque*) malloc (sizeof (Deque));
	if (D1->direita == NULL)
		printf ("Erro malloc!\n");	
	D1->direita->item = item;
	//D1->direita->esquerda = D1;
	printf("RETORNO1 \n");
	return 0;
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
	printf("Remover Direita \n");
	//UM ELEMENTO
	if (D1->direita->direita == NULL && D1->direita->esquerda == NULL) {
		D1->direita = NULL;
		printf("RETORNO11 \n");
		return 0;
	}
	if (D1->direita != NULL) {
		while (D1->direita != NULL) {
			if (D1->direita->direita == NULL) {
			} else {
					if (D1->direita->direita->direita == NULL) {
						printf ("PENULTIMO ELEMENTO! \n");
						break;
					}
				//printf("BREAK2 \n\n");
				//break;
				}
			D1->direita = D1->direita->direita;
		}
		//ESTOU NO PENULTIMO E QUERO RETIRAR O ULTIMO
		if (D1->direita->esquerda == NULL) {
			D1->direita->direita->esquerda = NULL;
			D1->direita->direita = NULL;
			printf ("RETORNO10 \n");
			return 0;
		}
		//TRES ELEMENTOS
		D1->direita->direita->esquerda = NULL;
		D1->direita->direita = NULL;
		D1->direita = D1->direita->esquerda;
		D1->direita = &aux; //FUNCIONA SEM -> ENTENDI, QUNADO TEM MAIS DE DOIS ELEMENTOS
		//EH NECESSARIO POIS PERDE A REFERENCIA
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
	
	insereDireita (D1, 100); imprime (*D1);
	
	removerDireita (D1); imprime (*D1);
	
	insereDireita (D1, 200); imprime (*D1);
	
	insereDireita (D1, 300); imprime (*D1);

	insereDireita (D1, 400); imprime (*D1);

	removerDireita (D1); imprime (*D1);

	insereDireita (D1, 600); imprime (*D1);

	insereDireita (D1, 700); imprime (*D1);
	
	removerDireita (D1); imprime (*D1);		
	return 0;
}