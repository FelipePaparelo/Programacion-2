#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "list_point.c"
// #include "list_cursor.c"
#include "listas_de_areglos.c"
#include "T_Element.c"

void validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    int bandera_2,num_de_m;
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


        bandera_2=0;
        if (aux == largo && aux <= 9)
        {
            num_de_m = atoi(m);
            printf("x=%i\n", num_de_m);
            if (num_de_m > 100000000 || num_de_m < -10000000)
            {
                bandera_2 = 1;
                aux = -1;
                printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            }
            else{
                bandera_2 = 0;
            }

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

char validar_numeros_positivos(char *m)
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
        printf("n = %i\n", n);
        if (n > 100){
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
    return bandera;
}

void cargar_datos_L1_teclado(int dato_i, Lista L1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; i++)
    {
        printf("ingrese el valor para la clave del %i tipoelemento:\n", 1 + i);
        validar_numeros(cad);
        numero = atoi(cad);
        x = te_crear(numero);
        l_agregar(L1, x);
    }
}

void cargar_datos_L2_teclado(int dato_i, Lista L2)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; i++)
    {
        printf("ingrese el valor para la clave del %i tipoelemento:\n", 1 + i);
        validar_numeros(cad);
        numero = atoi(cad);
        x = te_crear(numero);
        l_agregar(L2, x);
    }
}

int compararListas(Lista L1, Lista L2)
{
    int i = 1;
    int cant_claves_L1 = 0, cant_claves_L2 = 0;
    TipoElemento elem_L1 = l_recuperar(L1, i);
    TipoElemento elem_L2 = l_recuperar(L2, i);

    // recorremos ambas listas hasta que una de ellas se termine
    while (elem_L1 != NULL && elem_L2 != NULL && i <= l_longitud(L1) && i <= l_longitud(L2))
    {
        if (elem_L1->clave > elem_L2->clave)
        {
            cant_claves_L1++;
            i++;
            elem_L1 = l_recuperar(L1, i);
        }
        else if (elem_L1->clave < elem_L2->clave)
        {
            cant_claves_L2++;
            i++;
            elem_L2 = l_recuperar(L2, i);
        }
        else
        {
            i++;
            elem_L1 = l_recuperar(L1, i);
            elem_L2 = l_recuperar(L2, i);
        }
    }

    // si quedaron elementos en L1, es porque L1 es mayor que L2
    while (elem_L1 != NULL && i <= l_longitud(L1))
    {
        cant_claves_L1++;
        i++;
        elem_L1 = l_recuperar(L1, i);
    }

    // si quedaron elementos en L2, es porque L2 es mayor que L1
    while (elem_L2 != NULL && i <= l_longitud(L2))
    {
        cant_claves_L2++;
        i++;
        elem_L2 = l_recuperar(L2, i);
    }

    if (cant_claves_L1 > cant_claves_L2)
    {
        return 1; // L1 > L2
    }
    else if (cant_claves_L1 < cant_claves_L2)
    {
        return -1; // L1 < L2
    }
    else
    {
        return 0; // L1 = L2
    }
}

int main()
{
    char cad_l1[100];
    int num_l1;
    Lista l1, l2;
    printf("\nBIENENIDO AL PUNTO 3 DEL TP DE LISTAS\n");
    printf("CUANTOS ELEMENTOS VA INGRESAR EN LA LISTA 1:\n");
    validar_numeros_positivos(cad_l1);
    num_l1 = atoi(cad_l1);
    printf("COMIENZO DE CARGA DE LA LISTA 1:\n");
    l1 = l_crear();
    cargar_datos_L1_teclado(num_l1, l1);
    printf("SE CARGO CORRECTAMENTE LA LISTA 1:\n");
    printf("COMIENZO DE CARGA DE LA LISTA 2:\n");
    l2 = l_crear();
    cargar_datos_L2_teclado(num_l1, l2);
    printf("SE CARGO CORRECTAMENTE LA LISTA 2:\n");
    int resultado = compararListas(l1, l2);
    if (resultado == 1)
    {
        printf("La lista 1 es mayor que la lista 2");
    }
    else if (resultado == -1)
    {
        printf("La lista 2 es mayor que la lista 1");
    }
    else
    {
        printf("Las listas 1 y 2 son iguales");
    }
}

/* Las funciones "validar_numeros" y "validar_numeros_positivos" tienen una complejidad O(n) debido a que realizan un ciclo que recorre
cada carácter de la cadena de entrada y se llama a "strlen" para obtener su longitud.
Las funciones "cargar_datos_L1_teclado" y "cargar_datos_L2_teclado" también tienen una complejidad O(n) debido a que hay un ciclo que se ejecuta "n" veces,
y se llaman a funciones como "validar_numeros" y "atoi" que convierten una cadena a un número entero. Finalmente,
la complejidad algorítmica de la función "compararListas" es O(n) debido a que hay un ciclo que recorre los elementos de ambas listas y las compara,
y las demás operaciones dentro del ciclo tienen una complejidad O(1).*/

/*
O(1): tiempo constante
O(log n): tiempo logarítmico
O(n): tiempo lineal
O(n log n): tiempo n logarítmico
O(n^2): tiempo cuadrático
O(n^3): tiempo cúbico
O(2^n): tiempo exponencial
*/