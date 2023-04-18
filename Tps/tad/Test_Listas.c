#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "list_point.c"
#include "list_cursor.c"
// Cabecera para sacar los pares
Lista pares(Lista L);

//----------------------------------------------------------------------
// MAIN PRINCIPAL
//----------------------------------------------------------------------
int main()
{
    int i = 0;
    TipoElemento X;
    Lista L;

    L = l_crear();
    printf("Lista Creada Correctamente !!! \n");

    if (l_es_vacia(L))
    {
        printf("lista vacia !!! \n");
    }

    X = l_crear(1000);
    l_agregar(L, X);
    l_mostrarLista(L);

    // LLeno la lista
    i = 1;
    while (i <= 10)
    {
        X = l_crear(i);
        l_agregar(L, X);
        i = i + 1;
    }

    printf("-----------------------------------------------------------------\n");
    l_mostrarLista(L);

    // Ahora mando a insetar uno para ver si funciona al principio
    X = l_crear(11);
    l_insertar(L, X, 1);

    printf("-----------------------------------------------------------------\n");
    l_mostrarLista(L);

    // Ahora mando a insetar uno para ver si funciona en la quinta posicion
    X = l_crear(12);
    l_insertar(L, X, 5);

    printf("-----------------------------------------------------------------\n");
    l_mostrarLista(L);

    printf("-----------------------------------------------------------------\n");
    X = l_buscar(L, 1000);
    if (X != NULL)
    {
        printf("Clave Encontrada: %d \n", X->clave);
    }
    else
    {
        printf("La CLAVE NO FUE ENCONTRADA !!! \n");
    }
    // ahora una que no existe
    X = l_buscar(L, 5000);
    if (X != NULL)
    {
        printf("Clave Encontrada: %d \n", X->clave);
    }
    else
    {
        printf("La CLAVE NO FUE ENCONTRADA !!! \n");
    }

    printf("-----------------------------------------------------------------\n");
    // probamos a eliminar el primero
    l_eliminar(L, 1);
    l_mostrarLista(L);
    // probamos a eliminar el ultimo
    l_eliminar(L, l_longitud(L));
    l_mostrarLista(L);
    // probamos a eliminar en el medio
    l_eliminar(L, 5);
    l_mostrarLista(L);

    printf("-----------------------------------------------------------------\n");
    // probamos a borrar la primer clave
    X = l_recuperar(L, 1);
    l_borrar(L, X->clave);
    l_mostrarLista(L);
    // probamos a borrar la tercera clave
    X = l_recuperar(L, 3);
    l_borrar(L, X->clave);
    l_mostrarLista(L);
    // probamos a borrar la ultima clave
    X = l_recuperar(L, l_longitud(L));
    printf("Ultima Clave: %d \n", X->clave);
    l_borrar(L, X->clave);
    l_mostrarLista(L);

    printf("-----------------------------------------------------------------\n");

    // Agegamos 2 clave repetidas...
    X = l_crear(15);
    l_agregar(L, X);
    X = l_crear(15);
    l_agregar(L, X);
    l_mostrarLista(L);
    l_insertar(L, X, 1);
    l_mostrarLista(L);

    // Mando a borrar la 15 (3 claves)
    l_borrar(L, 15);
    l_mostrarLista(L);

    // Lista de pares
    printf("---- LISTA DE CLAVES PARES ---- \n");
    Lista lp = pares(L);
    l_mostrarLista(lp);

    return 0;
}

// retorno la lista con solo las claves pares
Lista pares(Lista L)
{
    TipoElemento X;
    Iterador ite;
    Lista lp = l_crear();

    // Inicializo el iterador
    ite = iterador(L);

    // Recorro la lista
    while (hay_siguiente(ite))
    {
        X = siguiente(ite);
        if ((X->clave % 2) == 0)
        {
            l_agregar(lp, X);
        }
    }

    return lp;
}