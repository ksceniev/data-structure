#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    LISTA* l1 = lst_cria();
    LISTA* l2 = lst_cria();

    int x;

    lst_insere(l1, 116);
    lst_insere(l1, 3);
    lst_insere(l1, 50);

    lst_insere_ordenado(l1, 40);
    lst_imprime(l1);

    printf("============================================\n\n");
    lst_retira(l1, 3);
    lst_imprime(l1);

    lst_insere(l2, 116);
    lst_insere(l2, 3);
    lst_insere(l2, 50);

    lst_insere_ordenado(l2, 40);
    lst_retira(l2, 3);

    x = lst_igual(l1, l2);
    x==0?printf("LISTAS DIFERENTES!\n"):printf("LISTAS IGUAIS!\n");

    return 0;
} 