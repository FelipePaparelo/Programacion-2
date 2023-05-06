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

Pila repetidas(Pila p1, Pila p2, Pila p3)
{
    if (p_es_vacia(p1) || p_es_vacia(p2))
    {
        printf("Alguna de las pilas está vacía\n");
    }

    Pila p_aux = p_crear();
    Pila p_aux2 = p_crear();
    int largo2 = p_longitud(p2);
    TipoElemento aux, aux3, aux2;

    while (!p_es_vacia(p1))
    {
        aux = p_desapilar(p1);
        p_apilar(p_aux, aux);
        for (int j = 0; j < largo2; j++)
        {
            aux2 = p_desapilar(p2);
            p_apilar(p_aux2, aux2);
            if (aux->clave == aux2->clave)
            {
                p_apilar(p3, aux);
            }
        }
        for (int i = 0; i < largo2; i++)
        {
            aux3 = p_desapilar(p_aux2);
            p_apilar(p2, aux3);
        }
    }

    while (!p_es_vacia(p_aux))
    {
        aux = p_desapilar(p_aux);
        p_apilar(p1, aux);
    }
    return p3;
}

int main()
{
    Pila p3 = p_crear();
    int largo;
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    printf("Punto 7 de pilas: Elementos en comun\n");
    printf("Cuantos elementos quiere que tengan las pilas?\n");
    largo = cargar_largo();
    printf("Ingrese los datos de la pila 1:\n");
    cargar_datos_teclado(largo, p1);
    printf("Ingrese los datos de la pila 2:\n");
    cargar_datos_teclado2(largo, p2);
    p3 = repetidas(p1, p2, p3);
    p_mostrar(p3);

    return 0;
}