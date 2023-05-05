/* Dada una cola de números enteros, no ordenada, construir un algoritmo que permita
pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el
contenido de la cola original y dejándola en su estado inicial. Determinar la
complejidad algorítmica de la solución.
Ejemplo: si "C" contiene (12,6, 8, 5, 8, 12, 12) la cola resultado del proceso sería (6,5).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

void no_repetidos(Cola c1)
{
    if (c_es_llena(c1))
    {
        return;
    }
    
}

int main()
{
    return 0;
}