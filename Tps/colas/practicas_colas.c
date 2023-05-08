#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>


// 2. Resolver los siguientes puntos:
// a. Informar si un elemento dado se encuentra en la cola.
// b. Agregar un nuevo elemento en una posición dada (colarse).
// c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
// d. Contar los elementos de la cola.
// e. Realizar una función que realice una copia de una cola.
// f. Invertir del contenido de una cola sin destruir la cola original. 
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
        p_apilar(c_azar, x);
    }
}


int main(){
    
}