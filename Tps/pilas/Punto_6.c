#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
//#include "pilas_puntero.c"

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
            //num_de_m = atoi(m);
            // if (num_de_m > 999.999.999 || num_de_m < -99999999)
            // {
            //     bandera_2 = 1;
            //     aux = -1;
            //     printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            // }
            // else{
            //     bandera_2 = 0;
            // }

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

void cargar_datos_teclado(int dato_i, Pila pila_1)
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
        p_apilar(pila_1, x);
    }
}

void cargar_datos_alazar(int dato_i, Pila pila_1)
{
    int i, r;
    TipoElemento x;
    srand(time(NULL)); // Se inicializa la semilla de la función rand() con el tiempo actual

    for (i = 0; i < dato_i; ++i)
    {
        r = rand(); // Se genera un número aleatorio entre 0 y RAND_MAX
        r = r % 11; // Se obtiene un número entre 0 y 100 utilizando el operador módulo
        x = te_crear(r);
        p_apilar(pila_1, x);
    }
}

// Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado
// ítem sin perder la pila original. Deberá retornar una nueva pila sin el ítem en
// consideración. Resolver iterativamente y recursivamente. Determinar la complejidad
// algorítmica de ambas soluciones

Pila sacar_elemento(Pila pila_1, int num)
{
    Pila pila_n, p_aux, pila_n_aux;
    TipoElemento x;
    pila_n_aux = p_crear();
    pila_n = p_crear();
    p_aux = p_crear();
    x = te_crear(0);
    while (p_es_vacia(pila_1) != true)
    {
        x = p_desapilar(pila_1);
        if (x->clave == num)
        {
            p_apilar(p_aux, x);
        }
        else
        {
            p_apilar(pila_n_aux, x);
            p_apilar(p_aux, x);
        }
    }

    while (p_es_vacia(pila_n_aux) != true)
    {
        x = p_desapilar(pila_n_aux);
        p_apilar(pila_n, x);
    }

    while (p_es_vacia(p_aux) != true)
    {
        x = p_desapilar(p_aux);
        p_apilar(pila_1, x);
    }
    return pila_n;
}

Pila sacar_elemento_r(Pila pila_1, int num, Pila p_aux, Pila pila_n_aux, Pila pila_n)
{
    TipoElemento x;
    x = te_crear(0);
    if (p_es_vacia(pila_1))
    {
        printf(".");
    }
    else
    {
        x = p_desapilar(pila_1);
        if (x->clave == num)
        {
            p_apilar(p_aux, x);
        }
        else
        {
            p_apilar(pila_n_aux, x);
            p_apilar(p_aux, x);
        }
        sacar_elemento_r(pila_1, num, p_aux, pila_n_aux, pila_n);
    }

    while (p_es_vacia(pila_n_aux) != true)
    {
        x = p_desapilar(pila_n_aux);
        p_apilar(pila_n, x);
    }

    while (p_es_vacia(p_aux) != true)
    {
        x = p_desapilar(p_aux);
        p_apilar(pila_1, x);
    }

    return pila_n;
}

int main()
{
    Pila p, p2, pila_n_aux, pila_n, p_aux;
    int i, num_cad, valor_a_llenar, valor_resol;
    char cad[100];
    printf("BIENVENIDO AL PUNTO 6 DEL TP DE PILAS\n");
    printf("1. si los datos se ingresan de forma alazar del 0 al 10\n");
    printf("2. si los datos se ingresan de forma manual\n");
    printf("ingrese la opcion que desea: \n");
    validar_numeros_positivos(cad);
    num_cad = atoi(cad);
    if (num_cad == 1)
    {
        printf("cuantos datos va ingresar a la pila, solo se puede hasta el valor 100\n");
        validar_numeros_positivos(cad);
        valor_a_llenar = atoi(cad);
        if (valor_a_llenar < 101)
        {
            printf("¿de que manera lo desea resolver?\n");
            printf("1.Resolver iterativamente.\n");
            printf("2.Resolver recursivamente.\n");
            validar_numeros_positivos(cad);
            valor_resol = atoi(cad);
            if (valor_resol == 1)
            {
                p = p_crear();
                cargar_datos_alazar(valor_a_llenar, p);
                printf("pila original \n");
                p_mostrar(p);
                printf("que elemento desea eliminar: \n");
                validar_numeros(cad);
                i = atoi(cad);
                p2 = sacar_elemento(p, i);
                printf("pila sacando los valores de %i \n", i);
                p_mostrar(p2);
                printf("pila original \n");
                p_mostrar(p);
            }
            else if (valor_resol == 2)
            {
                p = p_crear();
                cargar_datos_alazar(valor_a_llenar, p);
                printf("pila original \n");
                p_mostrar(p);
                printf("que elemento desea eliminar: \n");
                validar_numeros(cad);
                i = atoi(cad);
                pila_n_aux = p_crear();
                pila_n = p_crear();
                p_aux = p_crear();
                p2 = sacar_elemento_r(p, i, p_aux, pila_n_aux, pila_n);
                printf("pila sacando los valores de %i \n", i);
                p_mostrar(p2);
                printf("pila original \n");
                p_mostrar(p);
            }
            else
            {
                printf("no ingreso una opcion correcta, ingrese 1 o 2.\n");
            }
        }
        else
        {
            printf("no ingreso una opcion correcta, ingrese un valor entre 0 a 100.\n");
        }
    }
    else if (num_cad == 2)
    {
        printf("cuantos datos va ingresar a la pila, solo se puede hasta el valor 100\n");
        validar_numeros_positivos(cad);
        valor_a_llenar = atoi(cad);
        if (valor_a_llenar < 101)
        {
            printf("¿de que manera lo desea resolver?\n");
            printf("1.Resolver iterativamente.\n");
            printf("2.Resolver recursivamente.\n");
            validar_numeros_positivos(cad);
            valor_resol = atoi(cad);
            if (valor_resol == 1)
            {
                p = p_crear();
                cargar_datos_teclado(valor_a_llenar, p);
                printf("pila original \n");
                p_mostrar(p);
                printf("que elemento desea eliminar: \n");
                validar_numeros(cad);
                i = atoi(cad);
                p2 = sacar_elemento(p, i);
                printf("pila sacando los valores de %i \n", i);
                p_mostrar(p2);
                printf("pila original \n");
                p_mostrar(p);
            }
            else if (valor_resol == 2)
            {
                p = p_crear();
                cargar_datos_teclado(valor_a_llenar, p);
                printf("pila original \n");
                p_mostrar(p);
                printf("que elemento desea eliminar: \n");
                validar_numeros(cad);
                i = atoi(cad);
                pila_n_aux = p_crear();
                pila_n = p_crear();
                p_aux = p_crear();
                p2 = sacar_elemento_r(p, i, p_aux, pila_n_aux, pila_n);
                printf("pila sacando los valores de %i \n", i);
                p_mostrar(p2);
                printf("pila original \n");
                p_mostrar(p);
            }
            else
            {
                printf("no ingreso una opcion correcta, ingrese 1 o 2.\n");
            }
        }
        else
        {
            printf("no ingreso una opcion correcta, ingrese un valor entre 0 a 100.\n");
        }
    }
    else
    {
        printf("no ingreso una opcion correcta, ingrese 1 o 2.\n");
    }
}