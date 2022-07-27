#ifndef HEADER_H
#define HEADER_H

typedef struct lista LISTA;
typedef struct listano LISTANO;

/* funçao de criação: retorna uma lista inicialmente vazia */
LISTA* lst_cria();

/* inserção no inicio. ponteiro que representa a LISTA deve ser passado como parametro além da informação do novo elemento */
void lst_insere(LISTA* l, int v);

/* função insere o elemento na ordem correta */
void lst_insere_ordenado(LISTA* l, int v);

/* função que percorre todos os elementos da lista */
void lst_imprime(LISTA* l);

/* função pertence: verifica se o elemento está na lista */
int pertence(LISTA* l, int v);

/* retira elemento da lista */
void lst_retira(LISTA* l, int v);

/* função destroi a lista, primeiro libera o encadeamento dos elementos percorrendo toda a lista */
void lst_libera(LISTA* l);

/* função verifica se ambas as listas são iguais returnando 1 caso verdadeiro e 0 caso falso */
int lst_igual(LISTA* l1, LISTA* l2);

/* imprime todos os elementos de uma lista circular; caso a lista seja vazia o ponteiro para um elemento inicial dever ser NULL */
void lcirc_imprime(LISTA *l)

#endif