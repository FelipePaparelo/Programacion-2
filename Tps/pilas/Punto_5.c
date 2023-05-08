#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
#include "T_Element.c"

// #include "pilas_puntero.c"

void cargar_pila(Pila pila);
bool verificarEntradaInt(int *valor);
void p_intercambiar(Pila pAux, Pila p);
Pila pila_invertida(Pila pila);

//------------------------------------------------------
// MAIN
//------------------------------------------------------
int main()
{
    Pila pila_inicial = p_crear();
    Pila pila_resultado = p_crear();

    cargar_pila(pila_inicial);
    p_mostrar(pila_inicial);

    printf("----------------------Ejercicio--------------------------\n");
    pila_resultado = pila_invertida(pila_inicial);
    printf("Pila original, ");
    p_mostrar(pila_inicial);
    printf("Pila invertida, ");
    p_mostrar(pila_resultado);

    printf("----------------------Complejidad--------------------------\n");
    printf("La complejidad algorítmica de la resolución es de Orden Lineal");
    return 0;
}

//---------------------------------------------------------------------
// Procedimiento para cargar pila de forma manual por el usuario
//---------------------------------------------------------------------
void cargar_pila(Pila pila)
{
    int valor = 0;
    bool agregar = true;

    while (agregar)
    {
        printf("Ingrese el valor del dato para guardar en la Pila o cualquier letra para finalizar la carga : ");
        if (!verificarEntradaInt(&valor))
        {
            agregar = false;
        }
        else
        {
            TipoElemento te = te_crear(valor);
            p_apilar(pila, te);
        }
    }

    // Limpiamos el buffer de entrada
    while (getchar() != '\n')
        ;
}

//---------------------------------------------------------------------
// Función para verificar que la entrada sea Entero
//---------------------------------------------------------------------
bool verificarEntradaInt(int *valor)
{
    if (scanf("%d", valor) != 1)
        return false;
    else
        return true;
}

//------------------------------------------------------
// Procedimiento para intercambiar los elementos
// de una pila
//------------------------------------------------------
void p_intercambiar(Pila pAux, Pila p)
{
    TipoElemento te = te_crear(0);

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }
}

//------------------------------------------------------------------
// Invertir el contenido de una pila sin destruir la pila original.
// Se debe retornar la nueva pila invertida y la original no
// se debe perder. Determinar la complejidad algorítmicade la solución
//------------------------------------------------------------------
Pila pila_invertida(Pila pila)
{
    TipoElemento te = te_crear(0);
    Pila pila_aux = p_crear(0);
    Pila pila_resultado = p_crear(0);

    while (p_es_vacia(pila) != true)
    {
        te = p_desapilar(pila);
        p_apilar(pila_aux, te);
        p_apilar(pila_resultado, te);
    }

    p_intercambiar(pila_aux, pila);
    return pila_resultado;
}