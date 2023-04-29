#ifndef PILAS_H
#define PILAS_H
#include <stdbool.h>
#include "T_Element.c"

struct PilaRep;
typedef struct PilaRep *Pila;
Pila p_crear();
void p_apilar(Pila pila, TipoElemento elemento);
TipoElemento p_desapilar(Pila pila);
TipoElemento p_tope(Pila pila);
bool p_es_vacia(Pila pila);
bool p_es_llena(Pila pila);
void p_mostrar(Pila pila);
#endif // PILAS_H