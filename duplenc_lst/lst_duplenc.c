#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct lista{
    LISTANO *prim, *ult;
};

struct listano{
    int info;
    LISTANO *ant, *prox;
};

/* função cria a lista duplamente encadeada */
LISTA* lst_cria(){
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    l->prim = NULL;
    l->ult = NULL;

    return l;
}

/* função insere um elemento no inicio da lista */
void lst_insere_ini(LISTA* l, int v){
    LISTANO* novo = (LISTANO*) malloc(sizeof(LISTANO));
    novo->info = v;
    novo->prox = l->prim;
    novo->ant = NULL;

    if(l->prim != NULL) l->prim->ant = novo; /* testa se a lista é vazia, novo é anterior do antigo primeiro */
    else{ /* se a lista for vazia */
        l->prim = novo;
        l->ult = novo; /* novo é primeiro e ultimo */
    }
}

/* função insere elemento no final da lista */
void lst_insere_fin(LISTA* l, int v){
    LISTANO* novo = (LISTANO*) malloc(sizeof(LISTANO));
    novo->info = v;
    novo->prox = NULL;
    novo->ant = l->ult;

    if(l->ult != NULL) l->ult->prox = novo; /* testa se a lista é vazia, novo é proximo do antigo ultimo */
    else{ /* novo é primeiro e ultimo */
        l->prim = novo;
        l->ult = novo;
    }
}

/* função busca o elemento na lista, se nao existir retorna um ponterio NULL */
LISTANO* lst_busca(LISTA* l, int v){
    LISTANO *p;
    for(p = l->prim; p != NULL; p = p->prox){
        if(p->info == v) return p;
    }

    return NULL;
}