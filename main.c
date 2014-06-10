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
        printf (" %d ", de.itens[i]);
    printf ("\n");
}

int init_d (Deque *de)
{
    for (int i = 0; i < MAXDEQUE; i++)
    {
        de->itens[i] = 0;
    }
    return 1;
}

int remover_e (Deque *de, int x)
{
    for (int i = 0; i < MAXDEQUE; i++)
    {
        if (de->itens[i] == x)
        {
            de->itens[i] = 0;
            de->init_l = i + 1; //Apos excluir o ultimo esquerdo icremento o marcador para a proxima casa a direita
            return 1;
        }
    }
    return 0;
}

int remover_d (Deque *de, int x)
{
    for (int i = MAXDEQUE; i > 0; i--)
    {
        if (de->itens[i] == x)
        {
            de->itens[i] = 0;
            de->init_r--; //Apox excluir o ulitmo direito decremento o marcador para casa anterior a esquerda
            return 1;
        }
    }
    return 0;
}

int insere_d (Deque *de, int x)
{
    printf ("%d \n", de->init_r);
    for (int i = de->init_r; i > 0; i--)
    {
        
        if (de->itens[i] == 0) //Verifcacao se a ultima posicao inserida esta livre
        {
            de->itens[i] = x;
            de->init_r++;
            return 1;
        }
    }
    return 0;
}

int insere_e (Deque *de, int x)
{
    int y; //contador de decrementar para inserir um novo inteiro no final
    //Supundo Final é igual a Inicio na primeira vez e nas proximas sempre no final empurrando o ultimo
    //Se a posicao tiver valor 0 esta vazia
    for (int i = 0; i < MAXDEQUE; i++)
    {
        if (de->itens[i] == 0)
        {
            if (de->init_r == 0)
            {
                //Na primeira entrada
                de->itens[i] = x;
                de->init_r++;
                return 1;
                //de->itens[de->init_l] = 0;
            }
            if (de->init_r != 0)
            {
                for (y = i; y > 0; y--)
                {
                    de->itens[y] = de->itens[y - 1]; //Posicao atual do indice recebe valor anterior
                    de->itens[y - 1] = x; //Posicao anterior (inicio) recebe novo valor
                }
                de->init_r++; // Icrementa o inicio direita (Necessario para Inerir D)
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
    init_d (de); //Seta todos iguais a 0
    de->init_r = 0;
    de->init_l = 0;
    insere_e (de, 100);
    insere_e (de, 110);
    insere_e (de, 120);
    insere_e (de, 130);
    insere_e (de, 140);
    insere_e (de, 150);
    imprime (*de);
    //remover_e (de, 150);
    //remover_e (de, 140);
    remover_d (de, 100);
    imprime (*de);
    insere_d (de, 500);
    imprime (*de);
    //imprime (*de);
    // insert code here...
    //printf("Hello, World!\n");
    return 0;
}

