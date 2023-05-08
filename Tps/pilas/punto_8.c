
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
#include "T_Element.c"
// #include "pilas_puntero.c"

void validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    int bandera_2, num_de_m;
    fgets(m, 100, stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0)
        {
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for (int j = 0; j < largo; j++)
        {

            if ((j == 0) && (m[j] == '-'))
            {
                aux++;
            }

            if ((isdigit(m[j]) != 0))
            {
                aux++;
            }
        }

        bandera_2 = 0;
        if (aux == largo && aux <= 9)
        {
            num_de_m = atoi(m);

            if (bandera_2 == 1)
            {
                bandera = 1;
            }
            else if (bandera_2 == 0)
            {
                bandera = 0;
            }
        }
        else
        {
            aux = 0;
            printf("intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
}

void validar_numeros_positivos(char *m)
{
    int aux = 0;
    int bandera = 1;
    fgets(m, 100, stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0)
        {
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for (int j = 0; j < largo; j++)
        {

            if ((isdigit(m[j]) != 0))
            {
                aux++;
            }
        }

        if (aux == largo)
        {
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero positivo, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
}
int cargar_largo()
{
    char cad[100];
    validar_numeros_positivos(cad);
    int dato_i = atoi(cad);
    return dato_i;
}

void cargar_datos_teclado(int dato_i, Pila p1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; ++i)
    {
        printf("ingrese el valor para la clave del %i tipoelemento:\n", 1 + i);
        validar_numeros(cad);
        numero = atoi(cad);
        x = te_crear(numero);
        p_apilar(p1, x);
    }
}
void cargar_datos_teclado2(int dato_i, Pila p2)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; ++i)
    {
        printf("ingrese el valor para la clave del %i tipoelemento:\n", 1 + i);
        validar_numeros(cad);
        numero = atoi(cad);
        x = te_crear(numero);
        p_apilar(p2, x);
    }
}

void p_intercambiar(Pila pAux, Pila p)
{
    TipoElemento te;

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }
}
void p_mostrar_con_valor(Pila pila)
{
    while (p_es_vacia(pila))
    {
        printf("\n-----es vacia-----\n");
        return;
    }

    Pila p_aux = p_crear();
    TipoElemento x = te_crear(0);

    printf("\n--ELEMENTOS DE LA PILA--\n");
    printf("\n{ ");
    while (p_es_vacia(pila) != true)
    {
        x = p_desapilar(pila);
        printf("clave: %i\t\t", x->clave);
        printf("valor: %i\n", x->valor);
        p_apilar(p_aux, x);
    }
    printf(" }\n");

    while (p_es_vacia(p_aux) != true)
    {
        x = p_desapilar(p_aux);
        p_apilar(pila, x);
    }
}

Pila repeticiones_punto8(Pila pila1, int vec[], int tamanio, Pila pila_original)
{
    Pila pila_aux = p_crear();
    Pila pila_origen = p_crear();
    TipoElemento x;
    int contador = 0;
    int longitud = p_longitud(pila1);

    for (int i = 0; i < longitud; i++)
    {

        x = p_desapilar(pila1);

        for (int j = 0; j < tamanio; j++)
        {

            if (x->clave == vec[j])
            {
                contador += 1;
            }
        }

        x->valor = contador;
        p_apilar(pila_aux, x);
        contador = 0;
    }
    p_mostrar_con_valor(pila_aux);
    return (pila_aux);
}

Pila punto_8(Pila pila)
{
    int contador = p_longitud(pila);
    int *vec_claves = (int *)malloc(contador * sizeof(int));
    Pila pila_aux = p_crear();
    TipoElemento x;
    TipoElemento y;

    for (int i = 0; i < contador; i++)
    {
        x = p_desapilar(pila);
        vec_claves[i] = x->clave;
        p_apilar(pila_aux, x);
    }

    p_intercambiar(pila_aux, pila);
    Pila pila_resultado = p_crear();

    Pila p_aux = p_crear();
    Pila p_unicos = p_crear();
    int count = 0;

    while (!p_es_vacia(pila))
    {
        TipoElemento x = p_desapilar(pila);
        bool es_unica = true;
        Pila p_aux_copia = p_crear();
        while (!p_es_vacia(p_aux))
        {
            TipoElemento y = p_desapilar(p_aux);
            if (x->clave == y->clave)
            {
                es_unica = false;
            }
            p_apilar(p_aux_copia, y);
        }
        while (!p_es_vacia(p_aux_copia))
        {
            TipoElemento y = p_desapilar(p_aux_copia);
            p_apilar(p_aux, y);
        }
        if (es_unica)
        {
            p_apilar(p_unicos, x);
        }
        else
        {
            count++;
        }
        p_apilar(p_aux, x);
    }
    repeticiones_punto8(p_unicos, vec_claves, p_longitud(p_aux), p_aux);
}

int main()
{
    int dato_i = 10;
    Pila p1 = p_crear();
    printf("Punto 8 de pilas\n");
    printf("Cuantos elementos quiere que tengan las pilas?\n");
    int largo = cargar_largo();
    printf("Ingrese los datos de la pila 1:\n");
    cargar_datos_teclado(largo, p1);
    printf("\n---------Las repeticiones de cada elemento estarán almacenadas en x->valor---------\n");
    printf("Lista cargada:\n");
    p_mostrar(p1);
    punto_8(p1);
}