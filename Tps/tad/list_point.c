#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "listas.h"

static const int TAMANIO_MAXIMO = 100;
// defino la estructura de la lista
struct ListaRep
{
    int cantidad;    // cantidad de la lista
    Iterador inicio; // posicion inicial
};

typedef struct ListaRep *Lista; // define lista como un tipo de dato puntero

struct IteradorRep
{
    TipoElemento dato;
    int clave;
    struct IteradorRep *siguiente;
};
typedef struct IteradorRep *Iterador;

Lista l_crear()
{
    Lista lista = (Lista)malloc(sizeof(struct ListaRep));
    lista->cantidad = 0;
    lista->inicio = NULL;
    return lista;
}

bool l_es_vacia(Lista lista)
{
    return (lista->cantidad == 0);
}

bool l_es_llena(Lista lista)
{
    return (lista->cantidad == TAMANIO_MAXIMO);
}

int l_longitud(Lista lista)
{
    return (lista->cantidad);
}

void l_agregar(Lista lista, TipoElemento elemento)
{
    if (l_es_llena(lista))
    {
        return;
    };

    if (l_es_vacia(lista))
    {
        lista->inicio = (Iterador)malloc(sizeof(Iterador));
        lista->inicio->dato = elemento;
        lista->inicio->siguiente = NULL;
        lista->cantidad++;
        return;
    };

    Iterador temporal = lista->inicio;

    while (temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = (Iterador)malloc(sizeof(struct IteradorRep));
    temporal->siguiente->dato = elemento;
    temporal->siguiente->siguiente = NULL;
    lista->cantidad++;
    return;
}

void l_borrar(Lista lista, int clave)
{
    if (l_es_vacia(lista))
    {
        return;
    }

    Iterador actual = lista->inicio;
    Iterador previo = NULL;

    while (actual != NULL && actual->dato->clave != clave)
    {
        previo = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        return; // no se encontró el elemento con la clave indicada
    }

    if (previo == NULL)
    { // si el elemento a borrar es el primero de la lista
        lista->inicio = actual->siguiente;
    }
    else
    { // si el elemento a borrar está en medio o al final de la lista
        previo->siguiente = actual->siguiente;
    }

    free(actual); // liberar la memoria del nodo a borrar
    lista->cantidad--;
}

TipoElemento l_buscar(Lista lista, int clave)
{
    if (l_es_vacia(lista))
    {
        return NULL;
    }

    Iterador actual = lista->inicio;

    while (actual != NULL && actual->clave != clave)
    {
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        return NULL;
    }

    return &(actual->dato);
}

void l_insertar(Lista lista, TipoElemento elemento, int pos)
{
    if (l_es_llena(lista))
    {
        return;
    }

    if (pos < 0 || pos > lista->cantidad)
    {
        return;
    }

    if (pos == 0)
    {
        Iterador nuevo_nodo = (Iterador)malloc(sizeof(struct IteradorRep));
        nuevo_nodo->dato = elemento;
        nuevo_nodo->clave = elemento->clave;
        nuevo_nodo->siguiente = lista->inicio;
        lista->inicio = nuevo_nodo;
        lista->cantidad++;
        return;
    }

    Iterador temporal = lista->inicio;
    int contador = 0;

    while (temporal != NULL && contador < pos - 1)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    if (temporal == NULL)
    {
        return;
    }

    Iterador nuevo_nodo = (Iterador)malloc(sizeof(struct IteradorRep));
    nuevo_nodo->dato = elemento;
    nuevo_nodo->clave = elemento->clave;
    nuevo_nodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevo_nodo;
    lista->cantidad++;
}

void l_eliminar(Lista lista, int pos)
{
    if (pos < 0 || pos >= lista->cantidad) // verificar que la posición sea válida
    {
        return;
    }

    if (pos == 0) // si la posición es la primera, actualizar el inicio de la lista
    {
        Iterador temp = lista->inicio;
        lista->inicio = lista->inicio->siguiente;
        free(temp); // liberar la memoria del elemento a eliminar
    }
    else // si la posición está en medio o al final de la lista
    {
        Iterador anterior = lista->inicio;
        Iterador actual = lista->inicio->siguiente;
        int i = 1;
        while (actual != NULL && i < pos)
        {
            anterior = actual;
            actual = actual->siguiente;
            i++;
        }
        anterior->siguiente = actual->siguiente;
        free(actual); // liberar la memoria del elemento a eliminar
    }

    lista->cantidad--;
}

TipoElemento l_recuperar(Lista lista, int pos)
{
    if (pos < 0 || pos >= lista->cantidad)
    {
        return NULL; // posición inválida, devolver puntero nulo
    }

    Iterador actual = lista->inicio;
    for (int i = 0; i < pos; i++)
    {
        actual = actual->siguiente;
    }

    return actual->dato;
}

void l_mostrarLista(Lista lista)
{
    Iterador actual = lista->inicio;
    printf("[ ");
    while (actual != NULL)
    {
        printf("%d ", actual->dato->clave);
        actual = actual->siguiente;
    }
    printf("]\n");
}

Iterador iterador(Lista lista)
{
    Iterador iter = (Iterador)malloc(sizeof(struct IteradorRep));
    iter->siguiente = lista->inicio;
    return iter;
}

bool hay_siguiente(Iterador iterador)
{
    return iterador->siguiente != NULL;
}

TipoElemento siguiente(Iterador iterador)
{
    TipoElemento elemento = NULL;
    if (iterador->siguiente != NULL)
    {
        iterador = iterador->siguiente;
        elemento = (TipoElemento)iterador->dato;
    }
    return elemento;
}
