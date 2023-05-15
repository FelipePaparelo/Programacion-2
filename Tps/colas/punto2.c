/*
Resolver los siguientes puntos:
a. Informar si un elemento dado se encuentra en la cola.
b. Agregar un nuevo elemento en una posición dada (colarse).
c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
d. Contar los elementos de la cola.
e. Realizar una función que realice una copia de una cola.
f. Invertir del contenido de una cola sin destruir la cola original.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>
#include "../pilas/pilas.h"
#include "../pilas/pilas_arreglos.c"

void validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    int bandera_2;
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
void vaciar_cola(Cola c)
{
    int longitud = c_longitud(c);
    for (int i = 0; i < longitud; i++)
    {
        TipoElemento elem = c_desencolar(c);
        free(elem);
    }
}

int cargar_n()
{
    char cad[100];
    validar_numeros(cad);
    return atoi(cad);
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
        else if (aux > 6)
        {
            printf("El dato que Ingresa no esta permitido.");
            validar_numeros_positivos(*m);
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
void cargar_datos_teclado(int dato_i, Cola c1)
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
        c_encolar(c1, x);
    }
}

void cargar_datos_alazar(int dato_i, Cola c_azar)
{
    int i, r;
    TipoElemento x;
    srand(time(NULL)); // Se inicializa la semilla de la función rand() con el tiempo actual

    for (i = 0; i < dato_i; ++i)
    {
        r = rand(); // Se genera un número aleatorio entre 0 y RAND_MAX
        r = r % 11; // Se obtiene un número entre 0 y 100 utilizando el operador módulo
        x = te_crear(r);
        c_encolar(c_azar, x);
    }
}
int cargar_largo()
{
    char cad[100];
    validar_numeros_positivos(cad);
    int dato_i = atoi(cad);
    return dato_i;
}

bool esta(Cola c1, int dato_i)
{
    cargar_datos_teclado(dato_i, c1);
    if (c_es_vacia(c1))
    {
        return false;
    }
    printf("Ingrese el numero a buscar:");
    int n = cargar_n();
    Cola c1_aux = c_crear();
    int longitud = c_longitud(c1);
    int contador = 0;
    for (int k = 0; k < longitud; k++)
    {
        TipoElemento x = c_desencolar(c1);
        if (x->clave == n)
        {
            contador++;
        }
        c_encolar(c1_aux, x);
    }
    if (contador > 0)
    {
        printf("Esta\n");
        return true;
    }
    else
    {
        printf("No esta\n");
        return false;
    }
}

void agregado(Cola c1, int dato_i)
{
    cargar_datos_teclado(dato_i, c1);
    if (c_es_vacia(c1))
    {
        return;
    }
    printf("Ingrese el numero a agregar:\n");
    int n = cargar_n();
    TipoElemento j = te_crear(n);
    printf("Ingrese la posicion:\n");
    int pos = cargar_n();
    if (pos > dato_i)
    {
        printf("Valor invalido\n");
        vaciar_cola(c1);
        agregado(c1, dato_i);
    }
    Cola c1_aux = c_crear();
    //TipoElemento aux = te_crear(0);
    int longitud = c_longitud(c1);
    for (int k = 1; k <= longitud + 1; k++)
    {
        if (k == pos)
        {
            c_encolar(c1_aux, j);
        }
        if (!c_es_vacia(c1))
        {
            TipoElemento x = c_desencolar(c1);
            c_encolar(c1_aux, x);
        }
    }
    c_mostrar(c1_aux);
}

Cola borrar(Cola c1, int dato_i)
{
    cargar_datos_teclado(dato_i, c1);
    if (c_es_vacia(c1))
    {
        return;
    }
    Cola cola_borrados = c_crear();
    int largo = c_longitud(c1);
    printf("Ingrese el numero a borrar:\n");
    int n = cargar_n();
    TipoElemento x = te_crear(n);
    for (int k = 0; k < largo; k++)
    {
        x = c_desencolar(c1);
        if (x->clave != n)
        {
            c_encolar(cola_borrados, x);
        }
    }
    c_mostrar(cola_borrados);
    return cola_borrados;
}

// void repetido(Cola c1, int dato_i)
// {
//     cargar_datos_teclado(dato_i, c1);
//     if (c_es_vacia(c1))
//     {
//         return;
//     }
//     printf("Ingrese el numero a agregar:\n");
//     int n = cargar_n();
//     TipoElemento j = te_crear(n);
//     Cola c_aux = c_crear();
//     bool esta = false;
//     int longitud = c_longitud(c1);
//     for (int k = 0; k < longitud; k++)
//     {
//         TipoElemento x = c_desencolar(c1);
//         if (x->clave != n)
//         {
//             c_encolar(c_aux, x);
//         }
//         else
//         {
//             esta = true;
//         }
//     }
//     if (esta == false)
//     {
//         printf("No esta");
//     }
//     else
//     {
//         c_mostrar(c_aux);
//     }
// }

void cantidad(Cola c1, int dato_i)
{
    cargar_datos_teclado(dato_i, c1);
    if (c_es_vacia(c1))
    {
        return;
    }
    if (c_es_vacia(c1))
    {
        return;
    }
    int cantidad_elemt = c_longitud(c1);
    printf("Hay %i elementos en la cola\n", cantidad_elemt);
}

void copia(Cola c1, int dato_i)
{
    cargar_datos_teclado(dato_i, c1);
    if (c_es_vacia(c1))
    {
        return;
    }
    Cola c1_copia = c_crear();
    Cola c1_original = c_crear();
    int longitud = c_longitud(c1);
    TipoElemento x;

    for (int k = 0; k < longitud; k++)
    {
        x = c_desencolar(c1);
        c_encolar(c1_original, x);
        c_encolar(c1_copia, x);
    }
    printf("Cola original:\n");
    c_mostrar(c1_original);
    printf("Cola copiada:\n");
    c_mostrar(c1_copia);
}

void invertir(Cola c1, int dato_i)
{
    cargar_datos_teclado(dato_i, c1);
    if (c_es_vacia(c1))
    {
        return;
    }
    int longitud = c_longitud(c1);
    Pila pila_aux = p_crear();
    for (int k = 0; k < longitud; k++)
    {
        TipoElemento x = c_desencolar(c1);
        p_apilar(pila_aux, x);
    }
    for (int j = 0; j < longitud; j++)
    {
        TipoElemento y = p_desapilar(pila_aux);
        c_encolar(c1, y);
    }

    c_mostrar(c1);
}

int main()
{
    Cola c1 = c_crear();
    //int dato_i, n;
    //TipoElemento q;
    printf("Ingrese el largo de la cola:\n");
    int largo = cargar_largo();
    if (largo>100){
        printf("la cola es de 100 elementos, intente con un valor entre 0 o 100.\n");
    }
    else{
    
    printf("###########PUNTO 2-a###########\n");
    esta(c1, largo);
    vaciar_cola(c1);
    printf("###########PUNTO 2-b###########\n");
    agregado(c1, largo);
    vaciar_cola(c1);
    printf("###########PUNTO 2-c###########\n");
    borrar(c1, largo);
    vaciar_cola(c1);
    printf("###########PUNTO 2-d###########\n");
    cantidad(c1, largo);
    vaciar_cola(c1);
    printf("###########PUNTO 2-e###########\n");
    copia(c1, largo);
    vaciar_cola(c1);
    printf("###########PUNTO 2-f###########\n");
    invertir(c1, largo);
    }
    return 0;
}
