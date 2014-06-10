//
//  main.c
//  deque
//
//  Created by Arley Prates on 10/06/14.
//  Copyright (c) 2014 ___ARLEYPRATES___. All rights reserved.
//

#include <stdio.h>
#define MAXDEQUE 6


typedef struct deque Deque;

struct deque {
    int itens[MAXDEQUE];
    int init_r;
    int init_l;
};

void imprime (Deque de)
{
    for (int i = 0; i < MAXDEQUE; i++)
        printf ("%d\n", de.itens[i]);
}

int insere (Deque *de)
{
    for (int i = 0; i < MAXDEQUE; i++)
    {
        de->itens[i] = 0;
    }
    return 1;
}

int remover_f (Deque *de)
{
    for (int i = 0; i < MAXDEQUE; i++)
        de->itens[i] = -1;
    return 0;
}

int insere_f (Deque *de, int x)
{
    int y; //contador de decrementar para inserir um novo inteiro no final
    //Insere no inicio na primeira vez e nas proximas sempre no final empurrando o ultimo
    //Se a posicao tiver valor 0 esta vazia
    for (int i = 0; i < MAXDEQUE; i++)
    {
        if (de->itens[i] == 0)
        {
            if (de->init_r == 0)
            {
                //Na primeira entrada
                de->itens[i] = x;
                de->init_r = i + 1;
                return 1;
                //de->itens[de->init_l] = 0;
            }
            if (de->init_r != 0)
            {
                for (y = i; y > 0; y--)
                {
                    de->itens[y] = de->itens[y - 1]; //Posicao atual do indice recebe valor anterior
                    de->init_r = i + 1; // Icrementa o inicio direita
                    de->itens[y - 1] = x; //Posicao anterior (inicio) recebe novo valor
                }
                return 1;
            }
        }
    }
    return 0;
}
int main (int argc, const char * argv[])
{
    //inicializa deque
    Deque d; //variavel d do tipo struct deque
    Deque *de; //ponteiro de para um tipo struct deque
    de = &d; //de aponta par ao endereco d
    
    //rotinas deque
    insere (de);
    de->init_r = 0;
    de->init_l = 0;
    insere_f (de, 100);
    insere_f (de, 110);
    insere_f (de, 120);
    insere_f (de, 130);
    insere_f (de, 140);
    insere_f (de, 150);
    imprime (*de);
    //remover_f (de, );
    //imprime (*de);
    // insert code here...
    //printf("Hello, World!\n");
    return 0;
}

