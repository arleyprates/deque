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

    int opcao; //opcao para o menu
    opcao = 100;
    int x; //valor para inserir no DEQUE
    
    //rotinas deque
    
    init_d (de); //Seta todos iguais a 0
    
    de->init_r = 0; //Inicializa as cabeças direita/esquerda igual a 0
    de->init_l = 0;
    
    //Loop para o menu
    while (opcao > 0)
    {
        printf("\e[H\e[2J");
        printf ("===========================================================\n");
        printf ("======================DEQUE================================\n");
        printf ("1) insere elementos pela esquerda\n");
        printf ("2) insere elementos pela direita\n");
        printf ("3) remove elementos pela esquerda\n");
        printf ("4) remove elementos pela direita\n");
        printf ("5) imprime deque\n");
        printf ("0) encerra o programa\n");
        printf ("===========================================================\n");
        printf ("===========================================================\n");
        scanf ("%d", &opcao);
        printf("\e[H\e[2J");
        switch (opcao) {
            case 1:
                printf ("Digite um valor para inserir no DEQUE a esquerda\n");
                scanf ("%d", &x);
                insere_e (de, x);
                imprime (*de);
                scanf ("%d", &opcao);
                printf("\e[H\e[2J");
                break;
            case 2:
                printf ("Digite um valor para inserir no DEQUE a direita\n");
                scanf ("%d", &x);
                insere_d (de, x);
                imprime (*de);
                scanf ("%d", &opcao);
                printf("\e[H\e[2J");
                break;
            case 3:
                imprime (*de);
                printf ("Digite um valor para remover do DEQUE a esquerda\n");
                scanf ("%d", &x);
                remover_e (de, x);
                imprime (*de);
                scanf ("%d", &opcao);
                printf("\e[H\e[2J");
                break;
            case 4:
                imprime (*de);
                printf ("Digite um valor para remover do DEQUE a direita\n");
                scanf ("%d", &x);
                remover_d (de, x);
                imprime (*de);
                scanf ("%d", &opcao);
                printf("\e[H\e[2J");
                break;
            case 5:
                imprime (*de);
                scanf ("%d", &opcao);
                break;
            case 0:
                printf("\e[H\e[2J");
                return 0;
        }
        
    }
    return 0;
}

