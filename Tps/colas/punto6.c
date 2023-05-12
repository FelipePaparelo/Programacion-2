#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
#include "colas_punteros.c"
#include <stdbool.h>
#include "../tad/listas.h"
#include "../tad/listas_de_areglos.c"
#include "../pilas/pilas.h"
#include "../pilas/pilas_arreglos.c"
// #include "colas_arreglos_circular.c"



// 6. Dada una pila y una cola generada con valores al azar retornar en una lista todos los
// valores comunes a ambas y en qué posición ordinal se encontró cada uno en su
// estructura. No se deben destruir las estructuras originales. No se deben perderse las
// estructuras originales. Determinar la complejidad algorítmica de la solución empleada.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5). 

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

        int n = atoi(m);
        if (n > 100)
        {
            printf("Ingrese una cantidad de elementos menor o igual a 100: ");
            validar_numeros_positivos(m);
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

char validar_numeros(char *m)
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
            if (num_de_m > 100000000 || num_de_m < -10000000)
            {
                bandera_2 = 1;
                aux = -1;
                printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            }
            else
            {
                bandera_2 = 0;
            }

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
    return bandera;
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


void validar_numeros_no_rep_pila(char *m, Pila pila)
{
    int aux = 0;
    Pila p_aux = p_crear();
    int bandera = 1, p, num_de_m, bandera_2;
    TipoElemento x;
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
        num_de_m = atoi(m);
        if (aux == largo && aux <= 9)
        {

            if (num_de_m > 100000000 || num_de_m < -10000000)
            {
                bandera_2 = 1;
                aux = -1;
                printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            }
            else{
                bandera_2 = 0;
            }

            while(!p_es_vacia(pila)){
                x = p_desapilar(pila);
                if (x->clave == num_de_m && bandera_2 == 0)
                {
                    bandera_2 = 1;
                    aux = -1;
                    printf("el numero ya existe en la pila, Ingrese un elemento distinto a los ingresados anteriormente.\n");
                }
                p_apilar(p_aux, x);
            }
            p_intercambiar(p_aux, pila);

            

            if (bandera_2 == 1){
                bandera = 1;
            }
            else if (bandera_2 == 0){
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

void cargar_datos_teclado_lista(int dato_i, Lista list_1)
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
        l_agregar(list_1, x);
    }
}

void cargar_datos_teclado_pila(int dato_i, Pila p1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; ++i)
    {
        printf("ingrese el valor para la clave del %i tipoelemento de la pila: ", 1 + i);
        validar_numeros_no_rep_pila(cad, p1);
        numero = atoi(cad);
        x = te_crear(numero);
        p_apilar(p1, x);
    }
    printf("Finalizo la Carga\n");
    printf("\n\n");
}

void cargar_cola(Cola c,int cant){
    int elemento = 0;
    char cadena[100];
    TipoElemento x;
    while (cant>0){
        printf("ingrese el valor para la clave del %i tipoelemento de la cola: ", elemento+1);
        validar_numeros(cadena);
        elemento = atoi(cadena);
        x = te_crear(elemento);
        c_encolar(c,x);
        elemento++;
        cant--;
    }
    printf("Finalizo la Carga\n");
    printf("\n\n");
}

// 6. Dada una pila y una cola generada con valores al azar retornar en una lista todos los
// valores comunes a ambas y en qué posición ordinal se encontró cada uno en su
// estructura. No se deben destruir las estructuras originales. No se deben perderse las
// estructuras originales. Determinar la complejidad algorítmica de la solución empleada.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5). 

Lista punto_6(Pila p1, Cola c1, Lista l1){
    TipoElemento x;
    TipoElemento y;
    TipoElemento z;
}


int main(){
    int cant_elementos = 5;
    Cola c1 = c_crear();
    Lista l1 = l_crear();
    Pila p1 = p_crear();
    cargar_datos_teclado_pila(cant_elementos, p1);
    cargar_cola(c1, cant_elementos);
    p_mostrar(p1);
    c_mostrar(c1);
    
}