#include <stdio.h>
#include <stdlib.h>



typedef struct lista_no {
	int item;
	struct lista_no *direita, *esquerda;
}no;

typedef struct {
	no *cabeca, *calda;	
} Deque;

int main () {

	Deque D1;
	D1 = (Deque*) malloc (sizeof (Deque));


	return 0;
}