#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
//#include "colas_arreglos_circular.c"
#include "colas_punteros.c"

Cola RetornarClavesPares(Cola c);


int main()
{
    int i = 0;
    Cola C;
    TipoElemento X = te_crear(0);

    printf("Leno la Cola de <1 a n> !\n");
    C = c_crear();

    // lleno la cola de <1 a n>
    while (c_es_llena(C) != true) {
        i++;
        X = te_crear(i);
        c_encolar(C, X);
    }

    c_mostrar(C);

    printf("Mostramos de Nuevo la Cola para demostrar que NO la perdimos \n");

    c_mostrar(C);

    printf("\n");
    printf("Retornamos las Claves Pares de la Cola .... \n");
    Cola cp = RetornarClavesPares(C);
    c_mostrar(cp);

    printf("Mostramos de Nuevo la Cola para demostrar que NO la perdimos \n");
    printf("\n");
    c_mostrar(C);

    return 0;
}


//------------------------------------------------------------------
// retornar la cola de claves pares
//------------------------------------------------------------------
Cola RetornarClavesPares(Cola c) {
    Cola cp = c_crear();
    Cola caux = c_crear();
    TipoElemento X = te_crear(0);

    // Recorro la cola para sacar las claves pares
    while (c_es_vacia(c) != true) {
        X = c_desencolar(c);
        if ((X->clave % 2) == 0) {
            c_encolar(cp, X);
        }
        c_encolar(caux, X);
    }

    // recupero la cola original
    while (c_es_vacia(caux) != true){
        X = c_desencolar(caux);
        c_encolar(c, X);
    }

    return cp;
};

