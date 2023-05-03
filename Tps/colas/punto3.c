/*3. Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en
datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución del
problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

void iguales(Cola c1, Cola c2)
{
    if (c_es_vacia(c1) || c_es_vacia(c2))
    {
        return;
    }
    bool flag;
    int largo1 = c_longitud(c1);
    int largo2 = c_longitud(c2);
    Cola aux = c_crear();
    TipoElemento x = te_crear(0);
    TipoElemento y = te_crear(0);
    for (int k = 0; k < largo1; k++)
    {
        x = c_desencolar(c1);
        y = c_desencolar(c2);
        c_encolar(c2, x);
        c_encolar(aux, y);
        if (x->clave != y->clave)
        {
            flag = true;
        }
    }
    if (flag != true)
    {
        printf("son iguales\n");
    }
    else
    {
        printf("No son iguales\n");
    }
    c_mostrar(c2);
    c_mostrar(aux);
}

int main()
{
    Cola c1 = c_crear();

    TipoElemento y1 = te_crear(1);
    c_encolar(c1, y1);
    TipoElemento y2 = te_crear(2);
    c_encolar(c1, y2);
    TipoElemento y3 = te_crear(3);
    c_encolar(c1, y3);
    TipoElemento y4 = te_crear(7);
    c_encolar(c1, y4);

    Cola c2 = c_crear();

    TipoElemento x1 = te_crear(1);
    c_encolar(c2, x1);
    TipoElemento x2 = te_crear(9);
    c_encolar(c2, x2);
    TipoElemento x3 = te_crear(3);
    c_encolar(c2, x3);
    TipoElemento x4 = te_crear(4);
    c_encolar(c2, x4);
    iguales(c1, c2);
    return 0;
}