#include "pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//#include "T_Element.c"

static const int TAM_MAX = 100;

struct Nodo
{
	TipoElemento datos; // Concepto del Nodo
	struct Nodo *siguiente;
};

struct PilaRep
{
	struct Nodo *tope;
};

Pila p_crear()
{
	Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));
	nueva_pila->tope = NULL;
	return nueva_pila;
}

void p_apilar(Pila pila, TipoElemento elemento)
{
	struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
	nuevo_nodo->datos = elemento;
	nuevo_nodo->siguiente = pila->tope;
	pila->tope = nuevo_nodo;
}

TipoElemento p_desapilar(Pila pila)
{
	struct Nodo *tope_actual = pila->tope;
	TipoElemento elemento = tope_actual->datos;
	pila->tope = tope_actual->siguiente;
	free(tope_actual);
	return elemento;
}

TipoElemento p_tope(Pila pila)
{
	struct Nodo *tope_actual = pila->tope;
	return tope_actual->datos;
}

bool p_es_vacia(Pila pila)
{
	return pila->tope == NULL;
}

void p_mostrar(Pila pila)
{

	while (p_es_vacia(pila))
	{
		printf("\n-----es vacia-----\n");
		return;
	}

	Pila Paux = p_crear();
	TipoElemento X = te_crear(0);
	printf("\n--ELEMENTOS DE LA PILA--\n");
	printf("\n {");
	// Recorro la pila desopilándola y pasándola al auxiliar
	while (p_es_vacia(pila) != true)
	{
		X = p_desapilar(pila);
		printf("%i,", X->clave);
		p_apilar(Paux, X);
	}
	printf("}\n");
	// Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
	while (p_es_vacia(Paux) != true)
	{
		X = p_desapilar(Paux);
		p_apilar(pila, X);
	}
}

int p_longitud(Pila p)
{
	int i = 0;
	struct Nodo *n = p->tope;
	while (n != NULL)
	{
		i++;
		n = n->siguiente;
	}
	return i;
}

bool p_es_llena(Pila pila)
{
	return (TAM_MAX == p_longitud(pila));
}