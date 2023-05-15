/*3. Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en
datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución del
problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

int validar_numeros_positivos(char *m)
{
    int aux = 0;
    int bandera = 1,numero;
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

        if (aux == largo && aux<6)
        {
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero positivo o es mayor a 99.999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    numero=atoi(m);
    return numero;
}

int validar_numeros(char *m)
{
    int aux = 0,numero;
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
    numero=atoi(m);
    return numero;
}

void cargar_cola(Cola c,int cant){
    int cliente=1,clave=0;
    char cadena[100];
    TipoElemento x;
    while (cant>0){
        printf("ingrese el valor para la clave del %i elemento:\n",cliente);
        clave=validar_numeros(cadena);
        x=te_crear(clave);
        c_encolar(c,x);
        cliente++;
        cant--;
    }
    printf("Finalizo la Carga\n");
}

void iguales(Cola c1, Cola c2)
{
    if (c_es_vacia(c1) || c_es_vacia(c2))
    {
        return;
    }
    bool flag;
    int largo1 = c_longitud(c1);
    //int largo2 = c_longitud(c2);
    Cola aux = c_crear();
    TipoElemento x = te_crear(0);
    TipoElemento y = te_crear(0);
    for (int k = 0; k < largo1; k++)
    {
        x = c_desencolar(c1);
        y = c_desencolar(c2);
        c_encolar(c2, x);
        c_encolar(aux, y);
        if (x->clave != y->clave)
        {
            flag = true;
        }
    }
    if (flag != true)
    {
        printf("La cola 1 y la cola 2 son iguales\n");
    }
    else
    {
        printf("La cola 1 y la cola 2 No son iguales\n");
    }
    c_mostrar(c2);
    c_mostrar(aux);
}

int main(){
    printf("\nBinvenido al punto 3 del TP de colas.\n");
    Cola cola_1=c_crear(),cola_2=c_crear();
    char cadena[100];
    int cant_elem_cola1,cant_elem_cola2;
    printf("¿cuantos elementos va a tener en la cola 1?\n ");
    cant_elem_cola1=validar_numeros_positivos(cadena);
    if (cant_elem_cola1>=101){
        printf("la cola es de 100 elementos, intente con un valor entre 0 o 100.\n");
    }
    else{
        printf("Cargar de la Cola 1\n");
        cargar_cola(cola_1,cant_elem_cola1);
    }
    printf("¿cuantos elementos va a tener en la cola 2?\n ");
    cant_elem_cola2=validar_numeros_positivos(cadena);
    if (cant_elem_cola2>=101){
        printf("la cola es de 100 elementos, intente con un valor entre 0 o 100.\n");
    }
    else{
        printf("Cargar de la Cola 2\n");
        cargar_cola(cola_2,cant_elem_cola2);
    }
    iguales(cola_1, cola_2);

    return 0;
}