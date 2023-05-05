#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "colas.h"

static const int MAX = 10;

struct Nodo
{
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ColaRep
{
    struct Nodo *frente;
    struct Nodo *final;
};

Cola c_crear(void)
{
    Cola c_n = (Cola)malloc(sizeof(struct ColaRep));
    c_n->frente = NULL;
    c_n->final = NULL;
    return c_n;
}

void c_encolar(Cola c, TipoElemento x)
{
    if (c_es_llena(c))
    {
        return;
    }

    struct Nodo *n_d = malloc(sizeof(struct Nodo));
    n_d->datos = x;
    n_d->siguiente = NULL;

    if (c_es_vacia(c))
    {
        c->frente = n_d;
    }
    else
    {
        c->final->siguiente = n_d;
    }
    c->final = n_d;
}

TipoElemento c_desencolar(Cola c)
{
    if (c_es_vacia(c))
    {
        return NULL;
    }
    struct Nodo *inicio = c->frente;
    TipoElemento x = inicio->datos;
    c->frente = inicio->siguiente;
    free(inicio);
    return x;
}

bool c_es_vacia(Cola c)
{
    return (c->frente == NULL);
}

int c_longitud(Cola c)
{
    int i = 0;
    struct Nodo *n = c->frente;
    while (n != NULL)
    {
        i++;
        n = n->siguiente;
    }
    return i;
}

bool c_es_llena(Cola c)
{
    return (c_longitud(c) == MAX);
}

void c_mostrar(Cola c)
{
    if (c_es_vacia(c))
    {
        printf("la cola esta vacia\n");
        return;
    }

    Cola c_aux = c_crear();
    TipoElemento x = te_crear(0);
    int i = 1;

    printf("--------------\n");
    printf("los elementos de la cola\n");

    while (!c_es_vacia(c))
    {
        x = c_desencolar(c);
        printf("el elemento %i de la cola es: %i\n", i, x->clave);
        c_encolar(c_aux, x);
        i++;
    }

    while (!c_es_vacia(c_aux))
    {
        x = c_desencolar(c_aux);
        c_encolar(c, x);
    }
}

TipoElemento c_recuperar(Cola c)
{
    if (c_es_vacia(c))
    {
        return NULL;
    }
    struct Nodo *inicio = c->frente;
    TipoElemento x = te_crear(0);
    x = inicio->datos;
    free(inicio);
    return x;
}