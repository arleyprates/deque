//
//  chequesemfundo.c
//
//  Created by Raonyr Santos on 13/07/14.
//  Copyright (c) 2014 ___RAONYRSANTOS___. All rights reserved.
//  

#include <stdio.h>
#include <stdlib.h>

#define NUMB 3

typedef struct chequesfund {
  char nome[30];
  char endereco[50];
  char telefone[10];
  char data[11];
  char smercado[20];
  int vcheque;
  int id;
  int prioridade;
  struct chequesfund *ant,*prox;
}tchequesfund;

int empilha (); /*empilha o cheque conforme o valor do mesmo*/  
void mudarprior (); /*Mudar a prioridade de um processo cujo cÛdigo ˙nico foi especificado. A prioridade padr„o È 0.*/ 
void priormercado (); /*Localiza os processos do mercado especificado e os coloca no topo da pilha.*/  
int desempilha (); /*desempilhar processos.*/
void excluiprocesso (); /*Exclui um processo de onde ele estiver na pilha caso o chefe j· o tenha resolvido*/
void imprimepilha (); /*Imprime o id do processo, nome do cliente e valor do cheque de cada processo da pilha*/
void imprimetopo (); /*Imprime do processo no topo da pilha o id, o nome do cliente e o valor do cheque.*/

int contador; /*contador utilizado para a geraÁ„o sequencial de um identificador ˙nico para cada processo.*/
                 
int main (void) {
  tchequesfund *processos;
  int opcao = 0;
  processos = NULL;
  //system ("cls");
  printf("\n");
  do {
    //system ("cls");
    printf ("Qual a operacao desejada?\n1-Empihar processo;\n2-Priorizar um supermercado;\n");
    printf ("3-Mudar a prioridade de uma processo;\n4-Listar as caracteristica dos processos;\n");
    printf ("0-Sair\n\n");
    scanf ("%d", &opcao);
    if (opcao == 1)
      empilha (processos);
    printf("\n\n");
  } while (opcao != 0);

  return 0;
}

void priormercado (tchequesfund **cheque) {
  tchequesfund *pontaux;
  tchequesfund *pontaux2;
  tchequesfund *pontaux3;
  char nomeaux[20];
  int caracteratual=0, found=0, stop=0, achou=0, priormaster;
  pontaux = pontaux3 = *cheque;
  printf ("\nDigite o nome do supermercado que est· no sufoco.\n");
  gets (nomeaux);
  if (pontaux == NULL) {
    printf ("\nCÛdigo n„o encontrado.\n");
  } else {
      priormaster = pontaux->prioridade + 1;   
      while (stop == 0) {
        if (pontaux == NULL) {
          stop = 1;
        } else {
            found=1;
            caracteratual=0;
            while ((caracteratual < 20) && (pontaux->smercado[caracteratual] != '\0')) {
              if (pontaux->smercado[caracteratual] != nomeaux[caracteratual]) {
                found = 0;
              }
              caracteratual = caracteratual + 1;
            }
            if (found == 1) {
              found = 0;
              pontaux3 = pontaux->ant;
              pontaux2 = pontaux;
              pontaux->prioridade = priormaster;
              if (pontaux2->prox != NULL) {
                while (found == 0) {
                  if (pontaux2->prox == NULL) {
                    found = 1;
                    if (pontaux2->prioridade == pontaux->prioridade) {
                      if (pontaux2->vcheque < pontaux->vcheque) {
                        pontaux2->prox = pontaux;
                        if (pontaux->ant != NULL) {
                          pontaux->ant->prox=pontaux->prox;
                        }
                        pontaux->prox->ant = pontaux->ant;
                        pontaux->ant = pontaux2;
                        pontaux->prox = NULL;
                      } else {
                          if (pontaux->ant != NULL) {
                            pontaux->ant->prox=pontaux->prox;
                          }
                          pontaux->prox->ant = pontaux->ant;
                          pontaux->ant = pontaux2->ant;                                 
                          pontaux->prox = pontaux2;
                          pontaux2->ant = pontaux;
                          }
                    } else {
                      pontaux2->prox = pontaux;
                      if (pontaux->ant != NULL) {
                        pontaux->ant->prox = pontaux->prox;
                      }
                      pontaux->prox->ant=pontaux->ant;
                      pontaux->ant=pontaux2;
                      pontaux->prox=NULL;
                    }
                  } else {
                      pontaux2 = pontaux2->prox;
                      if (pontaux2->prioridade == pontaux->prioridade) {
                        if (pontaux->vcheque > pontaux2->vcheque) {
                          if (pontaux2->prox != NULL) {
                            pontaux2=pontaux2->prox;
                          }        
                        } else {
                            found = 1;
                            if (pontaux->ant != NULL) {
                              pontaux->ant->prox = pontaux->prox;
                            }
                            pontaux->prox->ant = pontaux->ant;
                            pontaux->prox = pontaux2;
                            pontaux2->ant = pontaux;
                        }
                      }
                  }
                }
              }
            }
            pontaux = pontaux3;
        }
      }    
  }                        
}

void mudarprior (int codigo, int novaprior, tchequesfund **cheque) {
   tchequesfund *checkaux;
   tchequesfund *checkaux2;
   int achou = 0, paraloop = 0;
   checkaux = *cheque;
  while (paraloop == 0) {
    if (checkaux == NULL){
      printf ("\nCodigo nao encontrado.\n");
      paraloop = 1;
    } else {
      if (checkaux->id == codigo) {
        checkaux->prioridade = novaprior;
        paraloop = 1;
        achou = 1;
      } else {
          checkaux = checkaux->ant;
      }
    }
  }
  paraloop = 0;
  if (achou == 1) {
    achou = 0;
    checkaux2 = checkaux;
    while (paraloop == 0) {
      if (checkaux2->prox == NULL) {
        paraloop = 1;
      } else {
          checkaux2 = checkaux2->prox;
          if (checkaux->prioridade > checkaux2->prioridade) {
            achou = 1;
          } else {
              if (checkaux->prioridade == checkaux2->prioridade) {
                if(checkaux->vcheque > checkaux2->vcheque) {
                  achou = 1;
                } else {
                    paraloop = 1;
                    checkaux2 = checkaux2->ant;
                }
              } else {
                  checkaux2 = checkaux2->ant;
                  paraloop = 1;
              } 
          }
      }
    }
    if (achou == 1) {
      if (checkaux->ant != NULL) {
        checkaux->ant->prox = checkaux->prox;
      }
      checkaux->prox->ant = checkaux->ant;
      checkaux->prox = checkaux2->prox;
      if (checkaux2->prox != NULL) {
            checkaux2->prox->ant = checkaux;
      }
      checkaux->ant = checkaux2;
      checkaux2->prox = checkaux;}
      if (achou == 0) {
        checkaux2 = checkaux;
        paraloop = 0;
        while (paraloop == 0) {
          if (checkaux2->ant == NULL) {
            paraloop = 1;
          } else {
            checkaux2 = checkaux2->ant;
            if (checkaux->prioridade < checkaux2->prioridade) {               
              achou = 1;
            } else {
                if (checkaux->prioridade == checkaux2->prioridade) {
                  if (checkaux->vcheque < checkaux2->vcheque) {
                    achou = 1;
                  } else {
                    paraloop = 1;
                    checkaux2 = checkaux2->prox;
                  }
                } else {
                    checkaux2 = checkaux2->prox;
                    paraloop = 1;
                }  
            }
          }
        }
        if (achou == 1) {
          if (checkaux->prox != NULL) {
            checkaux->prox->ant = checkaux->ant;
          }
          checkaux->ant->prox=checkaux->prox;
          checkaux->ant=checkaux2->ant;
          if (checkaux2->ant != NULL) {
            checkaux2->ant->prox = checkaux;
          }
          checkaux->prox = checkaux2;
          checkaux2->ant = checkaux;                
        }
        while ((*cheque)->prox != NULL) {
          *cheque = (*cheque)->prox;
        }
      }
  }
}              
    
int empilha (tchequesfund **cheque) {
  tchequesfund *checkaux;
  tchequesfund *checkaux2;
  int achou = 0;
  checkaux = (tchequesfund*) malloc (sizeof (tchequesfund));
  checkaux->id = 1000 + contador;
  contador = contador + 1;
  checkaux->prioridade = 0;
  printf ("Digite o nome do cidadao que passou o cheque sem fundo:");
  gets (checkaux->nome);
  printf ("\nDigite o endereco do cidadao:\n");
  gets (checkaux->endereco);
  printf ("\nDigite o telefone:\n");
  printf ("\nDigite a data do cheque:(formato dd/mm/aaaa)\n");
  gets (checkaux->data);
  printf ("Digite o valor do cheque:");
  scanf ("%d", &checkaux->vcheque);
  printf ("\nDigite o nome do supermercado:\n");
  gets (checkaux->smercado);
  if (*cheque == NULL) {
      checkaux->ant = NULL;
      checkaux->prox = NULL;
      *cheque = checkaux;
  } else {
      checkaux2 = *cheque;
      while (achou == 0) {
        if (checkaux2->ant == NULL) {
          achou = 1;
          if (checkaux2->prioridade == 0) {
              if (checkaux2->vcheque > checkaux->vcheque) {
                checkaux2->ant = checkaux;
                checkaux->prox = checkaux2;
                checkaux->ant = NULL;
              } else {
                  checkaux->prox = checkaux2->prox;
                  checkaux2->prox = checkaux;
                  checkaux->ant = checkaux2;
              }
          } else {
              if (checkaux2->prioridade > 0) {
                checkaux2->ant = checkaux;
                checkaux->prox = checkaux2;
                checkaux->ant = NULL;
              } else {
                  checkaux->prox=checkaux2->prox;
                  checkaux2->prox=checkaux;
                  checkaux->ant=checkaux2;
              }
          }                     
        } else {
            if (checkaux2->prioridade == 0) {
              if (checkaux->vcheque > checkaux2->vcheque) {
                checkaux->prox = checkaux2->prox;
                checkaux2->prox = checkaux;
                checkaux->ant = checkaux2;
                achou = 1;
              } else {
                  checkaux2 = checkaux2->ant;
              }
            } else {
                if (checkaux2->prioridade < 0) {
                  checkaux->prox = checkaux2->prox;
                  checkaux2->prox = checkaux;
                  checkaux->ant = checkaux2;
                  achou = 1;                              }
                else {
                  checkaux2=checkaux2->ant;
                }
            }
        }
      }
       
  while ((*cheque)->prox != NULL) {
    *cheque = (*cheque)->prox;
  }
  }
  return 1;    
}

int desempilha (tchequesfund **cheque) {
  tchequesfund *pontaux;
  pontaux = *cheque;
  if (pontaux != NULL) {
    *cheque = pontaux->ant;
    (*cheque)->prox = NULL;
    free (pontaux);
    pontaux = NULL;
    return 1;
  }
  else {
    printf ("N„o h· processos a serem desempihados.");
    return 0;
  }
}

void excluiprocesso (tchequesfund **cheque, int codigo) {
  tchequesfund *pontaux;     
  pontaux = *cheque;
  int achou = 0;
  int paraloop = 0;
  while (paraloop ==0) {
    if (pontaux == NULL){
      printf ("CÛdigo n„o encontrado.");
      paraloop = 1;
    } else {
      if (pontaux->id == codigo) {
        achou = 1;
        paraloop = 1;
      } else {
        pontaux = pontaux->ant;
      }
    }
  }
  if (achou == 1) {
    if (pontaux->ant != NULL) {
      pontaux->ant->prox = pontaux->prox;
    }
    if (pontaux->prox != NULL) {
      pontaux->prox->ant = pontaux->ant;
    } else {
      *cheque = (*cheque)->ant;
    }
    free(pontaux);
    pontaux=NULL;
    printf("Processo de codigo %d excluido.",codigo);
  }
}

void imprimepilha (tchequesfund *procheques) {
  tchequesfund *pontaux;
  int paraloop = 0;
  pontaux = procheques;
  while (paraloop == 0) {
    if (pontaux == NULL){
      paraloop = 1;
      printf ("\nFim da pilha.\n");
    } else {
      printf("\n-------------------------------------\n");
      printf("ID do processo: %d;\n",pontaux->id);
      printf("Nome do cliente: %s;\n",pontaux->nome);
      printf("Valor do cheque: %d;\n",pontaux->vcheque);
      printf("Endereco do cliente: %s;\n",pontaux->endereco);
      printf("Telefone: %s;\n",pontaux->telefone);
      printf("Data do cheque: %s;\n",pontaux->data);
      printf("Nome do supermercado: %s;\n",pontaux->smercado);
      printf("Prioridade: %d.\n",pontaux->prioridade);
      printf("---------------------------------------\n");
      pontaux = pontaux->ant;
    }
  }
}

void imprimetopo (tchequesfund *procheque) {
  if (procheque == NULL) {
    printf ("Pilha vazia.");
  } else {
    printf("\n-------------------------------------\n");
    printf("ID do processo: %d;\n",procheque->id);
    printf("Nome do cliente: %s;\n",procheque->nome);
    printf("Valor do cheque: %d.\n",procheque->vcheque);
    printf("Endereco do cliente: %s;\n",procheque->endereco);
    printf("Telefone: %s;\n",procheque->telefone);
    printf("Data do cheque: %s;\n",procheque->data);
    printf("Nome do supermercado: %s;\n",procheque->smercado);
    printf("Prioridade: %d.\n",procheque->prioridade);
    printf("---------------------------------------\n");                  
  }
} 

void imprimebase (tchequesfund *procheque) {
  tchequesfund *pontaux;
  int achou = 0;
  pontaux = procheque;
  if (pontaux == NULL) {
    printf ("Pilha vazia.");
  } else {
    //while (achou == 0) {
    //}
  }
}
  
   