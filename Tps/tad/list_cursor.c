#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "listas.h"

static const int TAMANIO_MAXIMO = 100;
static const int NULO = -1;
struct Nodo
{
    TipoElemento datos;
    int siguiente; // Cambia el apuntador por un “int”
};
struct ListaRep
{
    struct Nodo *cursor; // Apuntador al Arreglo de Nodos
    int inicio;
    int libre; // Contendrá los nodos libres o disponibles
    int cantidad;
};
struct IteradorRep
{
    Lista lista;
    int posicionActual;
};

Lista l_crear()
{
    Lista nueva_lista = (Lista)malloc(sizeof(struct ListaRep));
    if (nueva_lista == NULL)
    {
        // Si la asignación de memoria falla, devolvemos NULL
        return NULL;
    }

    nueva_lista->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct Nodo) * TAMANIO_MAXIMO);
    if (nueva_lista->cursor == NULL)
    {
        // Si la asignación de memoria falla, liberamos la memoria previamente asignada y devolvemos NULL
        free(nueva_lista);
        return NULL;
    }

    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO;

    // Encadeno todos los libres
    for (int i = 0; i < TAMANIO_MAXIMO - 2; i++)
    {
        nueva_lista->cursor[i].siguiente = i + 1;
    }
    nueva_lista->libre = 0; // Toma todos los nodos como libres
    nueva_lista->inicio = NULO;
    nueva_lista->cursor[TAMANIO_MAXIMO - 1].siguiente = NULO;

    // retorno la lista creada
    return nueva_lista;
}

bool l_es_vacia(Lista lista)
{
    return lista->cantidad == 0;
}

bool l_es_llena(Lista lista)
{
    return lista->libre == NULO;
}

int l_longitud(Lista lista)
{
    return lista->cantidad;
}

void l_agregar(Lista lista, TipoElemento elemento)
{
    if (l_es_llena(lista))
    {
        return;
    } // Controlo la lista llena
    int p;
    p = lista->libre; // Tomo el primer libre
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento; // Asigno el dato
    lista->cursor[p].siguiente = NULO;
    // Controlo que no sea el primero de la lista
    if (lista->inicio == NULO)
    {
        lista->inicio = p;
    }
    else
    {
        // lo ubico al final
        int q = lista->inicio;
        while (lista->cursor[q].siguiente != NULO)
        {
            q = lista->cursor[q].siguiente;
        }
        lista->cursor[q].siguiente = p; // Lo conecto con el ultimo
    }
    lista->cantidad++;
}

void l_borrar(Lista lista, int clave)
{
    if (l_es_vacia(lista))
    {
        return;
    }

    int q = NULO;
    int p = lista->inicio;
    while (p != NULO && lista->cursor[p].datos->clave == clave)
    {
        lista->inicio = lista->cursor[p].siguiente;
        lista->cursor[p].siguiente = lista->libre;
        lista->libre = p;
        lista->cantidad-=1;
        p = lista->inicio;
    }

    while (p != NULO)
    {
        if (lista->cursor[p].datos->clave == clave)
        {
            lista->cursor[q].siguiente = lista->cursor[p].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p;
            lista->cantidad--;
            p = lista->cursor[q].siguiente;
        }
        else
        {
            q = p;
            p = lista->cursor[p].siguiente;
        }
    }
}

TipoElemento l_buscar(Lista lista, int clave)
{
    if (l_es_vacia(lista))
    {
        return NULL;
    }
    int pos = lista->inicio;
    while (pos != NULO && lista->cursor[pos].datos->clave != clave)
    {
        pos = lista->cursor[pos].siguiente;
    }
    if (pos == NULO)
    {
        return NULL;
    }
    return lista->cursor[pos].datos;
}

void l_insertar(Lista lista, TipoElemento elemento, int pos)
{
    if (l_es_llena(lista) || pos < 1 || pos > lista->cantidad + 1)
    {
        return;
    }

    int p = lista->libre;
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;
    lista->cantidad++;

    if (pos == 1)
    {
        lista->cursor[p].siguiente = lista->inicio;
        lista->inicio = p;
    }
    else
    {
        int q = lista->inicio;
        for (int i = 0; i < pos - 2; i++)
        {
            q = lista->cursor[q].siguiente;
        }
        lista->cursor[p].siguiente = lista->cursor[q].siguiente;
        lista->cursor[q].siguiente = p;
    }
}

void l_eliminar(Lista lista, int pos)
{
    int p; // Falta controlar lista vacia
    int actual = lista->inicio;
    if (1 <= pos && pos <= l_longitud(lista))
    {
        if (pos == 1)
        { // borra la primer posicion hay que cambiar el Inicio
            p = actual;
            lista->inicio = lista->cursor[actual].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
        }
        else
        {
            for (int i = 0; i < pos - 2; i++)
            {
                actual = lista->cursor[actual].siguiente;
            }                                                             // actual apunta al nodo en posición (pos - 1)
            p = lista->cursor[actual].siguiente;                          // nodo en pos
            lista->cursor[actual].siguiente = lista->cursor[p].siguiente; // nodo en pos + 1
            lista->cursor[lista->libre].siguiente = p;
            lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
        }
        lista->cantidad--;
    }
}

TipoElemento l_recuperar(Lista lista, int pos)
{
    //pos+=1;
    if (pos < 0 || pos > lista->cantidad)
    {
        printf("Error: Posicion fuera de rango\n");
        return NULL;
    }

    int nodo_actual = lista->inicio;
    for (int i = 0; i < pos-1; i++)
    {
        nodo_actual = lista->cursor[nodo_actual].siguiente;
    }

    return lista->cursor[nodo_actual].datos;
}

void l_mostrarLista(Lista lista)
{
    int actual = lista->inicio;
    printf("Lista: ");
    while (actual != NULO)
    {
        printf("%d ", lista->cursor[actual].datos->clave);
        actual = lista->cursor[actual].siguiente;
    }
    printf("\n");
}

Iterador iterador(Lista lista)
{
    Iterador iter = malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = lista->inicio;
    return iter;
}

bool hay_siguiente(Iterador iterador)
{
    Lista lista = iterador->lista;
    int siguiente = lista->cursor[iterador->posicionActual].siguiente;
    return siguiente != NULO;
}

TipoElemento siguiente(Iterador iterador)
{
    Lista lista = iterador->lista;
    int siguiente = lista->cursor[iterador->posicionActual].siguiente;
    TipoElemento elemento = NULL;
    if (siguiente != NULO)
    {
        elemento = lista->cursor[iterador->posicionActual].datos;
        iterador->posicionActual=siguiente;
    }
    
    return elemento;
}
