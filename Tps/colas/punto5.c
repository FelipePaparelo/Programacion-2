/*
Dada una cola de números enteros, no ordenada, construir un algoritmo que permita
pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el
contenido de la cola original y dejándola en su estado inicial. Determinar la
complejidad algorítmica de la solución
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
#include "funciones_utiles.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

void cargar_cola(Cola cola);
bool verificar_entrada_int(int *valor);
bool verificar_repetido(Cola cola, int clave);

Cola divisor_total(Cola c, Cola cola_parcial);
Cola copia(Cola c);
void c_intercambiar(Cola c_aux, Cola c);
bool verificar_duplicado(Cola c, int clave);

//------------------------------------------------------
// MAIN
//------------------------------------------------------
int main()
{
    Cola cola_principal = c_crear();
    Cola cola_total = c_crear();
    Cola cola_parcial = c_crear();

    cargar_cola(cola_principal);
    printf("Cola cargada : ");
    c_mostrar(cola_principal);

    cola_total = divisor_total(cola_principal, cola_parcial);

    printf("Cola original : ");
    c_mostrar(cola_principal);
    printf("Cola con divisores parciales : ");
    c_mostrar(cola_parcial);
    printf("Cola con divisores totales : ");
    c_mostrar(cola_total);

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
        }
        else if (valor < 2 || valor > 9999999)
        {
            printf("El valor tiene que ser MAYOR o igual a 2 y MENOR a 9999999\n");
        }
        else
        {
            if (verificar_duplicado(cola, valor) == true)
            {
                printf("El valor está repetido");
                return;
            }
            else
            {
                TipoElemento te = te_crear(valor);
                c_encolar(cola, te);
            }
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

bool verificar_duplicado(Cola cola, int clave)
{
    TipoElemento x = te_crear(0);
    Cola cola_aux = c_crear();
    bool resultado = false;

    while (c_es_vacia(cola) != true)
    {
        x = c_desencolar(cola);
        c_encolar(cola_aux, x);
        if (x->clave == clave)
        {
            resultado = true;
        }
    }

    c_intercambiar(cola_aux, cola);
    return resultado;
}

//---------------------------------------------------------------------
// Función para intercambiar 2 colas
//---------------------------------------------------------------------
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

//---------------------------------------------------------------------
// Función para realizar el ejercicio
//---------------------------------------------------------------------
Cola divisor_total(Cola c, Cola cola_parcial)
{
    TipoElemento te = te_crear(0);
    TipoElemento te_duplicada = te_crear(0);
    Cola cola_duplicada = copia(c);
    Cola cola_aux = c_crear();
    Cola cola_duplicada_aux = c_crear();
    Cola cola_resultado = c_crear();
    int contador;
    float valor;
    float longitud = c_longitud_fu(c);

    while (c_es_vacia(c) != true)
    {
        te = c_desencolar(c);
        contador = 1;
        while (c_es_vacia(cola_duplicada) != true)
        {
            te_duplicada = c_desencolar(cola_duplicada);

            if (te->clave != te_duplicada->clave)
            {
                valor = te_duplicada->clave % te->clave;
                if (valor == 0)
                {
                    contador++;
                }
            }
            c_encolar(cola_duplicada_aux, te_duplicada);
        }
        c_intercambiar(cola_duplicada_aux, cola_duplicada);

        if (contador == longitud)
        {
            c_encolar(cola_resultado, te);
        }
        else if (contador >= ceil(longitud / 2))
        {
            c_encolar(cola_parcial, te);
        }

        c_encolar(cola_aux, te);
    }

    c_intercambiar(cola_aux, c);

    return cola_resultado;
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