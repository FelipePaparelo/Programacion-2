#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO_C = 2000;

struct NodoCola
{
    TipoElemento datos; // Concepto del NodoCola
    struct NodoCola *siguiente;
};

struct ColaRep
{
    struct NodoCola *frente;
    struct NodoCola *final;
};
//+++
Cola c_crear()
{
    Cola nueva_cola = (Cola)malloc(sizeof(struct ColaRep));
    nueva_cola->final = NULL;
    nueva_cola->frente = NULL;
    return nueva_cola;
}
//+++
void c_encolar(Cola cola, TipoElemento elemento)
{
    if (c_es_llena(cola))
    {
        printf("cola llena\n");
        return;
    }

    struct NodoCola *nuevo = malloc(sizeof(struct NodoCola)); // crea un nodoCola nuevo
    nuevo->datos = elemento;
    nuevo->siguiente = NULL;

    if (c_es_vacia(cola))
    {
        cola->final = nuevo;
        cola->frente = nuevo;
    }
    else
    {
        cola->final->siguiente = nuevo; // asigna el nuevo nodoCola como nuevo tope
        cola->final = cola->final->siguiente;
    }
}

TipoElemento c_desencolar(Cola cola)
{
    if (!c_es_vacia(cola))
    {
        struct NodoCola *frente_actual = cola->frente;
        TipoElemento elemento = cola->frente->datos;
        cola->frente = cola->frente->siguiente;
        free(frente_actual);
        return elemento;
    }
    else
    {
        printf("cola vacia\n");
        return NULL; // O devolver un valor predeterminado según tus necesidades
    }
}
int longitud(Cola cola)
{
    Cola Caux = c_crear();
    int cantidad = 0;

    while (!c_es_vacia(cola))
    {
        c_encolar(Caux, c_desencolar(cola));
        cantidad++;
    }

    while (!c_es_vacia(Caux))
    {
        c_encolar(cola, c_desencolar(Caux));
    }

    return cantidad;
}
//+++
bool c_es_vacia(Cola cola) { return cola->frente == NULL; }
//+++
bool c_es_llena(Cola cola) { return longitud(cola) == TAMANIO_MAXIMO_C; }
//+++
void c_mostrar(Cola cola)
{
    Cola Caux = c_crear();
    TipoElemento elemento = te_crear(0);

    printf("Mostrando cola: ");

    while (!c_es_vacia(cola))
    {
        elemento = c_desencolar(cola);
        printf(" %d", elemento->clave);
        c_encolar(Caux, elemento);
        if (!c_es_vacia(cola))
        {
            printf(";");
        }
    }
    printf("\n");
    while (!c_es_vacia(Caux))
    {
        c_encolar(cola, c_desencolar(Caux));
    }
}
//+++
TipoElemento c_recuperar(Cola cola)
{
    if (!c_es_vacia(cola))
    {
        return cola->frente->datos;
    }
    else
    {
        return te_crear(0);
    }
}