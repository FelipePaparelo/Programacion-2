#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "list_point.c"
// #include "list_cursor.c"
#include "listas_de_areglos.c"
#include "T_Element.c"

/*int compararListas(Lista* L1, Lista* L2) {
    int i = 0;
    int cant_claves_L1 = 0, cant_claves_L2 = 0;
    Elemento* elem_L1 = L1->inicio;
    Elemento* elem_L2 = L2->inicio;

    // recorremos ambas listas hasta que una de ellas se termine
    while (elem_L1 != NULL && elem_L2 != NULL) {
        if (elem_L1->clave > elem_L2->clave) {
            cant_claves_L1++;
            elem_L1 = elem_L1->siguiente;
        } else if (elem_L1->clave < elem_L2->clave) {
            cant_claves_L2++;
            elem_L2 = elem_L2->siguiente;
        } else { // si las claves son iguales avanzamos en ambas listas
            elem_L1 = elem_L1->siguiente;
            elem_L2 = elem_L2->siguiente;
        }
        i++;
    }

    // si quedaron elementos en L1, es porque L1 es mayor que L2
    while (elem_L1 != NULL) {
        cant_claves_L1++;
        elem_L1 = elem_L1->siguiente;
        i++;
    }

    // si quedaron elementos en L2, es porque L2 es mayor que L1
    while (elem_L2 != NULL) {
        cant_claves_L2++;
        elem_L2 = elem_L2->siguiente;
        i++;
    }

    if (cant_claves_L1 > cant_claves_L2) {
        return 1; // L1 > L2
    } else if (cant_claves_L1 < cant_claves_L2) {
        return -1; // L1 < L2
    } else {
        return 0; // L1 = L2
    }
}*/
