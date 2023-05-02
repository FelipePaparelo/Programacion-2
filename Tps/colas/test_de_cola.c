#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"

Cola RetornarClavesPares(Cola c);

<<<<<<< HEAD
=======

>>>>>>> b2298eca502039db631d30413d8275612c70b511
int main()
{
    int i = 0;
    Cola C;
    TipoElemento X = te_crear(0);

    printf("Leno la Cola de <1 a n> !\n");
    C = c_crear();

    // lleno la cola de <1 a n>
<<<<<<< HEAD
    while (c_es_llena(C) != true)
    {
=======
    while (c_es_llena(C) != true) {
>>>>>>> b2298eca502039db631d30413d8275612c70b511
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

<<<<<<< HEAD
//------------------------------------------------------------------
// retornar la cola de claves pares
//------------------------------------------------------------------
Cola RetornarClavesPares(Cola c)
{
=======

//------------------------------------------------------------------
// retornar la cola de claves pares
//------------------------------------------------------------------
Cola RetornarClavesPares(Cola c) {
>>>>>>> b2298eca502039db631d30413d8275612c70b511
    Cola cp = c_crear();
    Cola caux = c_crear();
    TipoElemento X = te_crear(0);

    // Recorro la cola para sacar las claves pares
<<<<<<< HEAD
    while (c_es_vacia(c) != true)
    {
        X = c_desencolar(c);
        if ((X->clave % 2) == 0)
        {
=======
    while (c_es_vacia(c) != true) {
        X = c_desencolar(c);
        if ((X->clave % 2) == 0) {
>>>>>>> b2298eca502039db631d30413d8275612c70b511
            c_encolar(cp, X);
        }
        c_encolar(caux, X);
    }

    // recupero la cola original
<<<<<<< HEAD
    while (c_es_vacia(caux) != true)
    {
=======
    while (c_es_vacia(caux) != true){
>>>>>>> b2298eca502039db631d30413d8275612c70b511
        X = c_desencolar(caux);
        c_encolar(c, X);
    }

    return cp;
};
<<<<<<< HEAD
=======

>>>>>>> b2298eca502039db631d30413d8275612c70b511
