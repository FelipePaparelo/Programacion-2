#include "listas.h"
#include "tipo_elemento.h"
#include <stdlib.h>
#include <stdio.h>
static const int TAMANIO_MAXIMO = 100;
struct ListaRep
{
    TipoElemento *valores; // este es el arreglo de “TipoElemento”
    int cantidad;
};
struct IteradorRep
{
    Lista lista;
    int posicionActual; // Mantiene la posición de cada iteración
};


