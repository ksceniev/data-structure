/* implementar função de inserção do nó na lista independente do tipo */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hetlista.h"

#define PI 3.14159

typedef struct retangulo{
    float b, h;
} RETANGULO;

typedef struct triangulo{
    float b, h;
} TRIANGULO;

typedef struct circulo{
    float r;
} CIRCULO;


/* nó da lista heterogenea deve ser composto por tres campos:
 
 * um identificador de qual objeto está armazenado no nó 
 * um ponteiro para a esturutra que contem a informação
 * um ponteiro para o próximo nó da lista 
 
    O ponrteiro para a informação deve ser do tipo genérico (void*). O nó da lista heterogênea deve então guardar explicitamente
    um identificador do tipo de objeto de fato armazenado.
*/

typedef enum tipo{
    ret, tri, circ
} TIPO;

/* define o nó da estrutura */
typedef struct hetlistano{
    HETLISTANO* prox;
    TIPO tipo;
    void* info;

} HETLISTANO;

/* define o ponteiro para acessar a estrutura */
typedef struct hetlista{
    HETLISTANO* prim;
} HETLISTA;

/* função cria a lista heterogenea */
HETLISTA* cria_hetlista(){
    HETLISTA* l = (HETLISTA*) malloc(sizeof(HETLISTA));
    l->prim = NULL;

    return l;
}

/* função com objetivo de encadear os elementos da lista, inserindo elemento no inicio
    obs: inserir o elemento só sera possivel depois de ele ser com as funções de criação
*/
void hetlista_insere(HETLISTA* l, HETLISTANO* p){
    p->prox = l->prim;
    l->prim = p;
}

/* cria um nó com um retangulo */
HETLISTANO* cria_ret(float b, float h){
    /* aloca retangulo: essa alocação é necessaria ja que a struct HETLISTANO contem o ponteiro para a struct RETANGULO */
    RETANGULO* r = (RETANGULO*) malloc(sizeof(RETANGULO));
    r->b = b;
    r->h = h;

    /* aloca o nó */
    HETLISTANO* p = (HETLISTANO*) malloc(sizeof(HETLISTANO)); 
    p->tipo = ret;
    p->info = r;
    p->prox = NULL;

    return p;
}

/* cria um nó com um triangulo */
HETLISTANO* cria_tri(float b, float h){
    /* aloca triangulo */
    TRIANGULO* t = (TRIANGULO*) malloc(sizeof(TRIANGULO));
    t->b = b;
    t->h = h;

    /* aloca o nó */
    HETLISTANO* p = (HETLISTANO*) malloc(sizeof(HETLISTANO)); 
    p->tipo = tri;
    p->info = t;
    p->prox = NULL;

    return p;
}

/* cria um nó com um circulo */
HETLISTANO* cria_circ(float r){
    /* aloca retangulo: essa alocação é necessaria ja que a struct HETLISTANO contem o ponteiro para a struct RETANGULO */
    CIRCULO* c = (CIRCULO*) malloc(sizeof(CIRCULO));
    c->r = r;

    /* aloca o nó */
    HETLISTANO* p = (HETLISTANO*) malloc(sizeof(HETLISTANO)); 
    p->tipo = circ;
    p->info = c;
    p->prox = NULL;

    return p;
}

/* função retorna área da figura geometrica inserida no nó, static é necessário para retornar o mesmo valor independente do escopo. 
    * Funçao precisa testar o tipo do objeto armazenado no nó, convertendo o ponteiro genério info para um ponteiro do tipo específico do objeto 
    * A partir do ponteiro convertido pode-se acessar os campos da esturtura que define aquele tipo de objeto.
*/
float area(HETLISTANO* p){
    switch(p->tipo){
        case ret: {
            RETANGULO* r = (RETANGULO*) p->info; /* converte o ponteiro generico (void*) para ponteiro do tipo RETANGULO */
            return r->b * r->h;
        } break;

        case tri: {
            TRIANGULO* t = (TRIANGULO*) p->info; /* converte o ponteiro generico (void*) para ponteiro do tipo TRIANGULO */
            return (t->b * t->h) / 2;
        } break;

        case circ: {
            CIRCULO* c = (CIRCULO*) p->info; /* converte o ponteiro generico (void*) para ponteiro do tipo CIRCULO */
            return PI * pow(c->r, 2);
        } break;
    }
}




