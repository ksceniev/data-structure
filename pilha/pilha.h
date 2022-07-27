#ifndef PILHA_H
#define PILHA_H

typedef struct pilha PILHA;

/* cria uma pilha vazia */
PILHA* pilha_cria();

/* adiciona o elemento v no topo da pilha */
void pilha_push(PILHA* p, float v);

/* retira o elemento do topo da pilha, e retorna seu valor */
float pilha_pop(PILHA* p);

/* verifica se a pilha é vazia */
int pilha_vazia(PILHA* p);

/* deleta a pilha */
void libera_pilha(PILHA* p);

#endif 