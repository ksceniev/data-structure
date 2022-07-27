#ifndef HEADER_H
#define HEADER_H

typedef struct lista LISTA;
typedef struct listano LISTANO;

/* função cria a lista duplamente encadeada */
LISTA* lst_cria();

/* função insere um elemento no inicio da lista */
void lst_insere_ini(LISTA* l, int v);

/* função insere elemento no final da lista */
void lst_insere_fin(LISTA* l, int v);

/* função busca o elemento na lista, se nao existir retorna um ponterio NULL */
LISTANO* lst_busca(LISTA* l, int v);

#endif