Deque

https://www.dropbox.com/s/y1k0lbw22qdm7ds/bandicam%202014-07-25%2002-45-41-863.avi

Portanto, no nosso código, na função main, onde inicia todo o processo, de inicialização do Deque, ou seja, criando um ponteiro do tipo struct Deque.

Então, centralizamos em uma função, a alocação de um espaço de memória do tipo Deque, em initDeque.

D1 vai apontar para o espaço de memória retornado pela função initDeque.

InitDeque, n recebe nenhum parâmetro e retorna um ponteiro do tipo Deque.
Simplesmente faz a alocação de memória do tipo e tamanho Deque.

A partir daí, o programa pode se comportar como o usuário desejar.
Inserindo pela direita ou esquerda.
E removendo pela direita ou esquerda.

Vamos começar um teste, pela direita.

A função insereDireita recebe como parâmetros, o ponteiro principal, D1, e um inteiro chamado item, a função retorna um inteiro.

Primeiro, criamos ponteiro do tipo dique chamado de aux.
Fazemos aux apontar para o inicio do deque.

Nossa primeira condição é feita caso seja inserção pela segunda vez.
Então vamos, pro caso um. Linha 68.
D1->direita que era nulo, vai apontar para um novo espaço de memória, do tipo e tamanho Deque.
E inserir o item no novo espaço alocado. inserimos o 100.
Retornamos 0.
Voltamos pro main.
Chamamos novamente uma nova inserção agora o 200.

Primeiro, criamos ponteiro do tipo deque chamado de aux.
Fazemos aux apontar para o inicio do deque.

Agora, nossa primeira condição é verdadeira,
D1->direita é diferente de NULL.
Então, entramos no while, e percorremos nosso Deque,
até o ponteiro, D1->direita for diferente de NULL.
Sendo que temos mais duas condições
na linha 55 antes de D1->direita apontar para o D1->direita->direita.
E outra depois.
O primeiro if dentro do While, na primeira execução vai ser falso
verifica se o D1->direita->direita é igual a NULL, Pq ja temos um elemento no Deque e ainda não estamos apontando para o próximo.
Então a linha 55 é executada.
e D1->direita apontar para o D1->direita->direita
E testamos mais uma vez antes de retomar pro inicio do while.
D1->direita->direita é igual a nulo. Nesse caso so temos um elemento, o 100, então o nosso D1->direita->direita é verdadeiro, é igual a NULL, ou seja, podemos alocar um novo espaço de memória. saímos do while.

E D1->direita->direita que era nulo, agora vai receber uma nova posição de memória com tamanho e tipo Deque.
Inserimos o nosso novo item, no caso 200. Linha 62
Fazemos nosso D1->direita->direita->esquerda, que é o esquerda do novo item, 200, apontar para o anterior dele, D1->direita

E por fim saímos da função insereDireita, item inserido com sucesso.
E assim pros demais casos.


Nossa função removeEsquerda.
A função remove esquerda recebe o ponteiro principal D1.

Primeiramente, testamos se temos um único elemento no deque.
D1->direita é diferente de NULL e D1->direita->direita é igual a NULL,
e D1->direita->esquerda é igual a NULL,
Ou seja, se essa condição é verdadeira, quer dizer que temos um único elemento no deque, e podemos então atualizar os ponteiros.
Fazendo D1->direita apontar para NULL.

Segunda condição, se temos mais de um elemento.
Então, nosso D1->direita é diferente de NULL
então percorremos pro próximo.
E atualizamos os ponteiros apontando para NULL

E por fim, retornarmos 0
saindo da função e elemento removido com sucesso.

Para os outros casos, segue de forma similar para o lado o posto.

=====
