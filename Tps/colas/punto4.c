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
//#include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

void cargar_cola(Cola cola);
bool verificar_entrada_int(int *valor);

Cola sin_repetir(Cola c);
Cola copia(Cola c);
void c_intercambiar(Cola c_aux, Cola c);
bool verificar_duplicado(Cola c, int clave);

//------------------------------------------------------
// MAIN
//------------------------------------------------------
int main()
{
    Cola cola_original = c_crear();
    Cola cola_resultado = c_crear();

    cargar_cola(cola_original);
    c_mostrar(cola_original);

    cola_resultado = sin_repetir(cola_original);

    printf("Cola original : ");
    c_mostrar(cola_original);
    printf("Cola Sin repetitos : ");
    c_mostrar(cola_resultado);

    printf("La complejidad algorítmica de la solución es de Orden Cuadrática");
    return 0;
}

//---------------------------------------------------------------------
// Procedimiento para cargar cola de forma manual por el usuario
//---------------------------------------------------------------------
void cargar_cola(Cola cola)
{
    int valor = 0;
    bool agregar = true;

    while (agregar)
    {
        printf("Ingrese el valor del dato para guardar en la Cola o cualquier letra para finalizar la carga : ");
        if (!verificar_entrada_int(&valor))
        {
            agregar = false;
        }else if(valor < -9999999 || valor > 9999999){
            printf("El valor ingresado no esta en el rango permitido, debe ser menor a 9999999 o mayor a -9999999...\n");
        }
        else
        {
            TipoElemento te = te_crear(valor);
            c_encolar(cola, te);
        }
    }

    // Limpiamos el buffer de entrada
    while (getchar() != '\n')
        ;
}

//---------------------------------------------------------------------
// Función para verificar que la entrada sea Entero
//---------------------------------------------------------------------
bool verificar_entrada_int(int *valor)
{
    if (scanf("%d", valor) != 1)
        return false;
    else
        return true;
}

void c_intercambiar(Cola c_aux, Cola c)
{
    TipoElemento x = te_crear(0);

    if (c_es_vacia(c_aux))
    {
        return;
    }

    while (c_es_vacia(c_aux) != true)
    {
        x = c_desencolar(c_aux);
        c_encolar(c, x);
    }
}

//------------------------------------------------------
// Función para duplicar una pila
//------------------------------------------------------
Cola copia(Cola c)
{
    Cola c_copia = c_crear();
    Cola c_original = c_crear();
    TipoElemento x = te_crear(0);
    int longitud = c_longitud(c);

    if (c_es_vacia(c))
    {
        return c_copia;
    }

    while (c_es_vacia(c) != true)
    {
        x = c_desencolar(c);
        c_encolar(c_copia, x);
        c_encolar(c_original, x);
    }

    while (c_es_vacia(c_original) != true)
    {
        x = c_desencolar(c_original);
        c_encolar(c, x);
    }

    return c_copia;
}

//--------------------------------------------------------
// Función para obtener una pila sin las claves repetidas
//--------------------------------------------------------
Cola sin_repetir(Cola c)
{
    TipoElemento te = te_crear(0);
    TipoElemento x = te_crear(0);
    Cola cola_duplicada = c_crear();
    Cola datos_duplicados = c_crear();
    Cola cola_auxiliar = c_crear();
    Cola cola_resultado = c_crear();
    bool encontrado;

    while (c_es_vacia(c) != true)
    {
        encontrado = false;
        te = c_desencolar(c);
        c_encolar(cola_auxiliar, te);
        cola_duplicada = copia(c);
        while (c_es_vacia(cola_duplicada) != true)
        {
            x = c_desencolar(cola_duplicada);
            if (te->clave == x->clave)
            {
                encontrado = true;
            }
        }

        if (encontrado == true)
        {
            c_encolar(datos_duplicados, te);
        }
        else
        {
            if (verificar_duplicado(datos_duplicados, te->clave) == false)
            {
                c_encolar(cola_resultado, te);
            }
        }
        c_mostrar(datos_duplicados);
    }

    c_intercambiar(cola_auxiliar, c);

    return cola_resultado;
}

bool verificar_duplicado(Cola c, int clave)
{
    TipoElemento x = te_crear(0);
    Cola c_aux = c_crear();
    bool resultado = false;

    while (c_es_vacia(c) != true)
    {
        x = c_desencolar(c);
        if (x->clave == clave)
        {
            resultado = true;
        }
        c_encolar(c_aux, x);
    }

    c_intercambiar(c_aux, c);

    return resultado;
}