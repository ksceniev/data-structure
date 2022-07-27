/* TAD para funções de uma lista de inteiros */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct lista{
    LISTANO* prim; 
};

struct listano{
    int info;
    LISTANO* prox;
};

/* funçao de criação: retorna uma lista inicialmente vazia */
LISTA* lst_cria(){
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    l->prim = NULL;
    return l;
}

/* inserção no inicio. ponteiro que representa a LISTA deve ser passado como parametro além da informação do novo elemento */
void lst_insere(LISTA* l, int v){
    LISTANO* novo = (LISTANO*) malloc(sizeof(LISTANO));
    novo->info = v;
    novo->prox = l->prim; /* faz o novo nó apontar para o nó que era o primeiro da lista, o nó inserido passa a ser o primeiro da lista */
    l->prim = novo;
}

/* função insere o elemento na ordem correta */
void lst_insere_ordenado(LISTA* l, int v){
    LISTANO* ant = NULL; /* pontiro para o elemento anterior */
    LISTANO* p = l->prim; /* ponteiro para percorrer a lista, seria como inicialição uam veriavel de iteração int i = 0; */ 

    /* localiza posição de inserção, no momento que (p->info == v) o loop é quebrado e p sai com o endereço do elemento seguinte (no caso o elemento que info == v) */
    while(p != NULL && p->info < v){ 
        ant = p; 
        p = p->prox; 
    }

    LISTANO* novo = (LISTANO*) malloc(sizeof(LISTANO));
    novo->info = v;

    /* encadeia elemento */
    if(ant == NULL){ /* insere elemento no inicio */ 
        novo->prox = l->prim;
        l->prim = novo;
    }else{ /* insere elemento no meio */
        novo->prox = ant->prox; /* recebe o endereço do que antes era o proximo elemento (ocupou o lugar deste agora)*/
        ant->prox = novo; 
    }
}

/* retira elemento da lista */
void lst_retira(LISTA* l, int v){
    LISTANO* ant = NULL;
    LISTANO* p = l->prim;

    while(p != NULL && p->info != v){
        ant = p; 
        p = p->prox; 
    }

    if(p != NULL){
vjoid        if(ant == NULL) l->prim = p->prox; /* retira elemento do inicio */
        else ant->prox = p->prox; /* retira elemento no meio */
            
        free(p);
    }
}

/* função pertence: verifica se o elemento está na lista */
int pertence(LISTA* l, int v){
    LISTANO* p;
    for(p = l->prim; p != NULL; p = p->prox){
        if(p->info == v){
            return 1;
        }
    }

    return 0;
}

int lst_vazia(LISTA* l){
    if(l->prim != NULL) return 1;
    else return 0;
}

/* função que percorre todos os elementos da lista */
void lst_imprime(LISTA* l){
    LISTANO* p; /* variavel auxiliar que armazena o endereço de memoria de cada elemento */
    for(p = l->prim; p != NULL; p = p->prox) printf("info: %i\naddr: %p\nprox: %p\n\n", p->info, &p->info, p->prox);
}

/* função destroi a lista, primeiro libera o encadeamento dos elementos percorrendo toda a lista */
void lst_libera(LISTA* l){
    LISTANO* t = NULL;
    LISTANO* p = l->prim;
    
    while(p != NULL){
        t = p->prox; /* guarda a referencia para o proximo elemento */
        free(p);
        p = t;
    }

    free(l);
}

/* função verifica se duas listas são iguais */
int lst_igual(LISTA* l1, LISTA* l2){
    LISTANO *p1, *p2;

    for(p1 = l1->prim, p2 = l2->prim; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if(p1->info != p2->info) return 0;
    }

    return p1 == p2;
}



