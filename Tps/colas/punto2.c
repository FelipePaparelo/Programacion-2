/*
Resolver los siguientes puntos:
a. Informar si un elemento dado se encuentra en la cola.
b. Agregar un nuevo elemento en una posición dada (colarse).
c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
d. Contar los elementos de la cola.
e. Realizar una función que realice una copia de una cola.
f. Invertir del contenido de una cola sin destruir la cola original.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

bool esta(Cola c1, int n)
{
    if (c_es_vacia(c1))
    {
        return false;
    }
    Cola c1_aux = c_crear();
    int longitud = c_longitud(c1);
    int contador = 0;
    for (int k = 0; k < longitud; k++)
    {
        TipoElemento x = c_desencolar(c1);
        if (x->clave == n)
        {
            contador++;
        }
        c_encolar(c1_aux, x->clave);
    }
    if (contador > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void agregado(Cola c1, int pos, TipoElemento j)
{
    if (c_es_vacia(c1))
    {
        return;
    }
    Cola c1_aux = c_crear();
    TipoElemento aux = te_crear(0);
    int longitud = c_longitud(c1);
    for (int k = 0; k < longitud + 1; k++)
    {
        if (k == pos)
        {
            TipoElemento x = c_desencolar(c1);
            c_encolar(c1_aux, j);
            aux = x;
            c_encolar(c1_aux, aux);
        }
        TipoElemento x = c_desencolar(c1);
        c_encolar(c1_aux, x);
    }
    c_mostrar(c1_aux);
}

int main()
{
    int n = 56;
    int pos = 3;
    Cola c1 = c_crear();
    TipoElemento j = te_crear(100);

    TipoElemento y1 = te_crear(1);
    c_encolar(c1, y1);
    TipoElemento y2 = te_crear(2);
    c_encolar(c1, y2);
    TipoElemento y3 = te_crear(3);
    c_encolar(c1, y3);
    TipoElemento y4 = te_crear(4);
    c_encolar(c1, y4);
    agregado(c1, pos, j);
    bool flag = esta(c1, n);
    if (flag == true)
    {
        printf("El elemento %d esta en la cola\n", n);
    }
    else
    {
        printf("El elemento %d no esta en la cola\n", n);
    }

    return 0;
}