#ifndef HETLISTA_H
#define HETLISTA_H

typedef struct retangulo RETANGULO;
typedef struct triangulo TRANGULO;
typedef struct circulo CIRCULO;

typedef enum tipo TIPO;
typedef struct hetlista HETLISTA;
typedef struct hetlistano HETLISTANO;

/* função cria a lista heterogenea */
HETLISTA* cria_hetlista();

/* cria um nó com um retangulo */
HETLISTANO* cria_ret(float b, float h);

/* cria um nó com um triangulo */
HETLISTANO* cria_tri(float b, float h);

/* cria um nó com um circulo */
HETLISTANO* cria_circ(float r);

/* função com objetivo de encadear os elementos da lista, inserindo elemento no inicio
    obs: inserir o elemento só sera possivel depois de ele ser com as funções de criação
*/
void hetlista_insere(HETLISTA* l, HETLISTANO* p);

/* retorna a área do objeto armazenado no nó */
float area(HETLISTANO* p);

#endif