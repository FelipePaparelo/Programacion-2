#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "listas_de_areglos.c"
#include "list_point.c"
// #include "list_cursor.c"
#include "T_Element.c"

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

void validar_numeros_no_rep(char *m, Lista l1)
{
    int aux = 0;
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
        if (aux == largo && aux <= 9)
        {
            num_de_m = atoi(m);
            for (p = 0; p < l_longitud(l1); p++)
            {
                x = l_recuperar(l1, p + 1);
                if (x->clave == num_de_m && bandera_2 == 0)
                {
                    printf("el numero ya fue ingresado\n");
                    bandera_2 = 1;
                    aux = -1;
                }
            }

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

void cargar_datos_teclado(int dato_i, Lista list_1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; i++)
    {
        printf("ingrese el valor para la clave del %i tipoelemento:\n", 1 + i);
        validar_numeros_no_rep(cad, list_1);
        numero = atoi(cad);
        x = te_crear(numero);
        l_agregar(list_1, x);
    }
}

void resolver_punto_6(Lista l_prin, Lista l_sub)
{
    TipoElemento x1, x2;
    int i, p, cont_i = 0;
    for (i = 0; i < l_longitud(l_prin); i++)
    {
        x1 = l_recuperar(l_prin, i + 1);
        for (p = 0; p < l_longitud(l_sub); p++)
        {
            x2 = l_recuperar(l_sub, p + 1);
            if (x1->clave == x2->clave)
            {
                cont_i++;
            }
        }
    }
    if (cont_i == l_longitud(l_sub))
    {
        printf("UNA LISTA ES SUBLISTAS DE LA OTRA");
    }
    else
    {
        printf("LA LISTA NO ES SUBLISTAS DE LA OTRA");
    }
}

int main()
{
    char cad_l1[100], cad_l2[100];
    int num_l1, largo_2, largo_1;
    Lista l1, l2;
    printf("\nBIENENIDO AL PUNTO 6 DEL TP DE LISTAS\n");
    printf("CUANTOS ELEMENTOS VA INGRESAR EN LA LISTA 1:\n");
    validar_numeros_positivos(cad_l1);
    num_l1 = atoi(cad_l1);
    printf("COMIENZO DE CARGA DE LA LISTA 1\n");
    l1 = l_crear();
    cargar_datos_teclado(num_l1, l1);
    printf("SE CARGO CORRECTAMENTE LA LISTA 1\n");
    printf("COMIENZO DE CARGA DE LA LISTA 2\n");
    printf("CUANTOS ELEMENTOS VA INGRESAR EN LA LISTA 2:\n");
    validar_numeros_positivos(cad_l2);
    l2 = l_crear();
    num_l1 = atoi(cad_l2);
    cargar_datos_teclado(num_l1, l2);
    printf("SE CARGO CORRECTAMENTE LA LISTA 2\n");
    largo_1 = l_longitud(l1);
    largo_2 = l_longitud(l2);
    if (largo_1 > largo_2)
    {
        resolver_punto_6(l1, l2);
    }
    else if (largo_2 > largo_1)
    {
        resolver_punto_6(l2, l1);
    }
    else
    {
        resolver_punto_6(l1, l2);
    }
}