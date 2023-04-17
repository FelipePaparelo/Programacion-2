#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
#include "list_point.c"
// #include "listas_de_areglos.c"
#include "T_Element.c"

char validar_numeros(char *m)
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

            if ((j == 0) && (m[j] == '-'))
            {
                aux++;
            }

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
            printf("El dato que Ingresa no es un numero entero, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    return bandera;
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

void cargar_datos_alazar(int dato_i, Lista list_1)
{
    int i, r;
    TipoElemento x;
    srand(time(NULL)); // Se inicializa la semilla de la función rand() con el tiempo actual

    for (i = 0; i < dato_i; ++i)
    {
        r = rand();  // Se genera un número aleatorio entre 0 y RAND_MAX
        r = r % 101; // Se obtiene un número entre 0 y 100 utilizando el operador módulo
        x = te_crear(r);
        l_agregar(list_1, x);
    }
}

Lista resolver_p2(Lista list_1, int num)
{
    TipoElemento x;
    Lista list_return;
    int i, min, pos_min, max, cant_max;
    min = 101;
    max = -1;
    cant_max = 1;
    list_return = l_crear();
    for (i = 0; i < l_longitud(list_1); ++i)
    {
        x = l_recuperar(list_1, i + 1);
        if (x->clave < min)
        {
            min = x->clave;
            pos_min = i + 1;
        }
        if (x->clave > max)
        {
            max = x->clave;
            cant_max = 1;
        }
        else if (x->clave == max)
        {
            cant_max++;
        }
        if (x->clave % num == 0)
        {
            l_agregar(list_return, x);
        }
    }
    printf("la menor clave es %i,esta en la posicion %i.\n", min, pos_min);
    printf("la mayor clave es %i,y la cantidad que aparece es %i.\n", max, cant_max);
    return list_return;
}

void resolver_punto2_c(Lista list_1, int largo, float *result)
{
    TipoElemento x;
    if (largo == 0)
    {
    }
    else
    {
        x = l_recuperar(list_1, largo);
        *result += x->clave;
        resolver_punto2_c(list_1, largo - 1, result);
    }
}

void cargar_datos_teclado(int dato_i, Lista list_1)
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

int main()
{

    char cad[100], cad_2[100];
    int numero, numero_2;
    Lista lista_prin;
    printf("BIENVENIDO AL PUNTO 2 DEL TP DE LISTA\n");
    printf("QUE OPCION DESEA ELEGIR: \n");
    printf("1) INGRESAR DATOS A LA AZAR\n");
    printf("2) IMGRESAR DATOS POR TECLADO\n");
    validar_numeros(cad);
    numero = atoi(cad);
    if (numero > 2 || numero < 1)
    {
        printf("INGRESE UNA OPCION QUE SEA 1,2\n");
    }
    else if (numero == 1)
    {
        printf("CUANTOS ELEMENTO DESEA QUE SE INGRESE DE FORMA AL AZAR  EN LA LISTA: \n");
        float resultado, promedio;
        validar_numeros_positivos(cad_2);
        numero_2 = atoi(cad_2);
        lista_prin = l_crear();
        cargar_datos_alazar(numero_2, lista_prin);
        l_mostrarLista(lista_prin);
        printf("\nINGRESE UN NUMERO PARA BUSCAR SUS MULTIPLO EN LA LISTA: \n");
        strcpy(cad_2, "");
        validar_numeros(cad_2);
        numero_2 = atoi(cad_2);
        l_mostrarLista(resolver_p2(lista_prin, numero_2));
        resultado = 0;
        resolver_punto2_c(lista_prin, l_longitud(lista_prin), &resultado);
        promedio = resultado / l_longitud(lista_prin);
        printf("el promedio es %f ", promedio);
    }
    else if (numero == 2)
    {
        float resultado, promedio;
        printf("CUANTOS ELEMENTOS VAS INGRESAR EN LA LISTA POR TECLADO: \n");
        validar_numeros_positivos(cad_2);
        numero_2 = atoi(cad_2);
        lista_prin = l_crear();
        cargar_datos_teclado(numero_2, lista_prin);
        l_mostrarLista(lista_prin);
        printf("\nINGRESE UN NUMERO PARA BUSCAR SUS MULTIPLO EN LA LISTA: \n");
        strcpy(cad_2, "");
        validar_numeros(cad_2);
        numero_2 = atoi(cad_2);
        l_mostrarLista(resolver_p2(lista_prin, numero_2));
        resultado = 0;
        resolver_punto2_c(lista_prin, l_longitud(lista_prin), &resultado);
        promedio = resultado / l_longitud(lista_prin);
        printf("el promedio es %f ", promedio);
    }
}