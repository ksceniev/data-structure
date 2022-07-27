#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* imprime todos os elementos de uma lista circular; caso a lista seja vazia o ponteiro para um elemento inicial dever ser NULL */
void lcirc_imprime(LISTA *l){
    LISTANO *p = l->prim; /* faz p apontar para o nó inicial */

    if(p != NULL) do{
        printf("%i \n", p->info);
        p = p->prox;
    } while(p != l->prim);
}