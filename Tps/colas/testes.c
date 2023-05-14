#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
#include "colas_punteros.c"
// #include "colas_arreglos_circular.c"
#include "../tad/listas.h"
#include "../tad/listas_de_areglos.c"
#include "../pilas/pilas.h"
#include "../pilas/pilas_arreglos.c"
// #include "../pilas/pilas_puntero.c"

#include <stdio.h>

#define MAX_STRING_SIZE 100



typedef struct Nodo
{
    int valor;
    int posiciones[100];
    int num_posiciones;
    struct Nodo siguiente;
} Nodo;

void agregar_elemento(Nodo **cabeza, int valor, int posicion)
{
    Nodonuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->num_posiciones = 0;
    nuevo_nodo->siguiente = NULL;

    if (cabeza == NULL)
    {
        cabeza = nuevo_nodo;
    }
    else
    {
        Nodoactual = cabeza;
        Nodoanterior = NULL;
        while (actual != NULL)
        {
            if (actual->valor == valor)
            {
                actual->posiciones[actual->num_posiciones++] = posicion;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        anterior->siguiente = nuevo_nodo;
    }
    nuevo_nodo->posiciones[nuevo_nodo->num_posiciones++] = posicion;
}

void imprimir_lista(Nodo cabeza)
{
    Nodoactual = cabeza;
    while (actual != NULL)
    {
        if (actual->num_posiciones > 1)
        {
            printf("%d:", actual->valor);
            int i;
            for (i = 0; i < actual->num_posiciones; i++)
            {
                printf("%d", actual->posiciones[i]);
                if (i != actual->num_posiciones - 1)
                {
                    printf(":");
                }
            }
            printf(", ");
        }
        actual = actual->siguiente;
    }
}

int main()
{
    int pila[] = {2, 5, 8, 19, 3, 4};
    int cola[] = {4, 18, 12, 5, 6};
    int pila_size = sizeof(pila) / sizeof(pila[0]);
    int cola_size = sizeof(cola) / sizeof(cola[0]);
    Nodo *lista = NULL;
    int i;

    for (i = 0; i < pila_size; i++)
    {
        agregar_elemento(&lista, pila[i], i);
    }

    for (i = 0; i < cola_size; i++)
    {
        agregar_elemento(&lista, cola[i], i + pila_size);
    }

    imprimir_lista(lista);

    return 0;
}