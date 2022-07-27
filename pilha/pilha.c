#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
    int n; /* n de elementos armazenados */
    int dim; /* tamanho total do vetor */
    float *vet; /* vetor de elementos */
};

PILHA* pilha_cria(){
    PILHA *p = (PILHA*) malloc(sizeof(PILHA));
    p->dim = 2;
    p->vet = (float*) malloc(p->dim * sizeof(float));
    p->n = 0; 

    return p;
}

/* para inserri um elemento na pilha usamos a proxima posição livre do vetor verificando se há necessidade de realocação */
void pilha_push(PILHA* p, float v){
    if(p->n == p->dim){ /* capacidade esgotada */
        p->dim *= 2;
        p->vet = (float*) realloc(p->vet, p->dim * sizeof(float));
    }
    
    p->vet[p->n++] = v;
}

float pilha_pop(PILHA* p){
    float v = p->vet[--p->n]; /* retira o elemento do topo, acessamos o vetor com o valor n já decrementado (operador prefixado) */
    return v;
}

