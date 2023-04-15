#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "listas.h"

// Tamaño máximo de la lista
static const int TAMANIO_MAXIMO = 100;

// Valor que representa la ausencia de un nodo siguiente
static const int NULO = -1;

// Definición de la estructura Nodo, que almacena los datos y un apuntador al siguiente nodo
struct Nodo
{
    TipoElemento datos;
    int siguiente; // Cambia el apuntador por un "int"
};

// Definición de la estructura ListaRep, que almacena un apuntador al arreglo de nodos,
// el índice del primer nodo en la lista, el índice del primer nodo libre, y la cantidad
// de elementos en la lista
struct ListaRep
{
    struct Nodo *cursor; // Apuntador al arreglo de nodos
    int inicio;          // Índice del primer nodo en la lista
    int libre;           // Índice del primer nodo libre
    int cantidad;        // Cantidad de elementos en la lista
};

// Definición de la estructura IteradorRep, que almacena la lista sobre la que se itera y la
// posición actual del iterador
struct IteradorRep
{
    Lista lista;
    int posicionActual;
};

Lista l_crear()
{
    // Se reserva memoria para la estructura ListaRep
    Lista nuevaLista = malloc(sizeof(struct ListaRep));

    // Se reserva memoria para el arreglo de nodos
    nuevaLista->cursor = malloc(TAMANIO_MAXIMO * sizeof(struct Nodo));

    // Se inicializan los valores de inicio y libre en NULO (-1)
    nuevaLista->inicio = NULO;
    nuevaLista->libre = 0;

    // Se crea una lista de nodos vacía
    for (int i = 0; i < TAMANIO_MAXIMO - 1; i++)
    {
        nuevaLista->cursor[i].siguiente = i + 1;
    }
    nuevaLista->cursor[TAMANIO_MAXIMO - 1].siguiente = NULO;

    // Se inicializa la cantidad de nodos en 0
    nuevaLista->cantidad = 0;

    return nuevaLista;
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
    // Verificar si la lista está llena
    if (l_es_llena(lista))
    {
        printf("La lista está llena. No se puede agregar más elementos.\n");
        return;
    }

    // Crear un nuevo nodo con los datos del elemento
    int nuevoNodo = lista->libre;
    lista->cursor[nuevoNodo].datos = elemento;
    lista->cursor[nuevoNodo].siguiente = NULO;

    // Actualizar la lista
    if (l_es_vacia(lista))
    {
        lista->inicio = nuevoNodo;
        lista->cursor = &(lista->cursor[nuevoNodo]);
    }
    else
    {
        int nodoActual = lista->inicio;
        while (lista->cursor[nodoActual].siguiente != NULO)
        {
            nodoActual = lista->cursor[nodoActual].siguiente;
        }
        lista->cursor[nodoActual].siguiente = nuevoNodo;
        lista->cursor = &(lista->cursor[nuevoNodo]);
    }
    lista->cantidad++;
}

void l_borrar(Lista lista, int clave)
{
    // Buscar el nodo anterior al nodo a eliminar
    int posAnterior = NULO;
    int posActual = lista->inicio;
    while (posActual != NULO && lista->cursor[posActual].datos->clave != clave)
    {
        posAnterior = posActual;
        posActual = lista->cursor[posActual].siguiente;
    }

    // Si se encontró el nodo a eliminar
    if (posActual != NULO)
    {
        // Modificar el siguiente del nodo anterior
        if (posAnterior == NULO)
        {
            // El nodo a eliminar es el primero de la lista
            lista->inicio = lista->cursor[posActual].siguiente;
        }
        else
        {
            lista->cursor[posAnterior].siguiente = lista->cursor[posActual].siguiente;
        }

        // Agregar el nodo eliminado a la lista de nodos libres
        lista->cursor[posActual].siguiente = lista->libre;
        lista->libre = posActual;
        lista->cantidad--;
    }
}

TipoElemento l_buscar(Lista lista, int clave)
{
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
    // Verificar que la lista no esté llena
    if (l_es_llena(lista))
    {
        printf("Error: la lista está llena\n");
        return;
    }

    // Verificar que la posición sea válida
    if (pos < 0 || pos > lista->cantidad)
    {
        printf("Error: posición inválida\n");
        return;
    }

    // Obtener un nodo libre
    int nodo_libre = lista->libre;
    if (nodo_libre == NULO)
    {
        printf("Error: no hay nodos libres\n");
        return;
    }

    // Actualizar el cursor del nuevo nodo
    lista->cursor[nodo_libre].siguiente = NULO;

    // Asignar el elemento al nuevo nodo
    lista->cursor[nodo_libre].datos = elemento;

    // Insertar el nuevo nodo en la lista
    if (pos == 0)
    { // Insertar al principio
        lista->cursor[nodo_libre].siguiente = lista->inicio;
        lista->inicio = nodo_libre;
    }
    else
    { // Insertar en otra posición
        int anterior = lista->inicio;
        for (int i = 0; i < pos - 1; i++)
        {
            anterior = lista->cursor[anterior].siguiente;
        }
        lista->cursor[nodo_libre].siguiente = lista->cursor[anterior].siguiente;
        lista->cursor[anterior].siguiente = nodo_libre;
    }

    // Actualizar la cantidad de elementos de la lista
    lista->cantidad++;

    // Actualizar la lista de nodos libres
    lista->libre = lista->cursor[nodo_libre].siguiente;
}

void l_eliminar(Lista lista, int pos)
{
    if (l_es_vacia(lista))
    {
        printf("La lista está vacía\n");
        return;
    }
    if (pos < 0 || pos >= lista->cantidad)
    {
        printf("Posición inválida\n");
        return;
    }
    int actual = lista->inicio;
    int anterior = NULO;
    int i = 0;
    while (i < pos)
    {
        anterior = actual;
        actual = lista->cursor[actual].siguiente;
        i++;
    }
    if (actual == lista->inicio)
    {
        lista->inicio = lista->cursor[actual].siguiente;
    }
    else
    {
        lista->cursor[anterior].siguiente = lista->cursor[actual].siguiente;
    }
    lista->cursor[actual].siguiente = lista->libre;
    lista->libre = actual;
    lista->cantidad--;
}

TipoElemento l_recuperar(Lista lista, int pos)
{
    if (pos < 0 || pos >= lista->cantidad)
    {
        printf("Error: Posición fuera de rango\n");
        return NULL;
    }

    int nodo_actual = lista->inicio;
    for (int i = 0; i < pos; i++)
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
        elemento = lista->cursor[siguiente].datos;
    }
    return elemento;
}
