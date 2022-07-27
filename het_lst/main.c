#include <stdio.h>
#include <stdlib.h>
#include "hetlista.h"



int main(){
    HETLISTA* l;
    HETLISTANO* r;
    float a;

    l = cria_hetlista(); /* lista criada */
    r = cria_ret(2.0, 3.0); /* cria objeto retangulo */

    hetlista_insere(l, r); /* insere o objeto r na lista l */
    a = area(r); 

    printf("Area Nó: %.3f \n", a);

    return 0; 
}