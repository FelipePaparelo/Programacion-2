#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
#include <math.h>
// #include "list_point.c"
#include "list_cursor.c"
// #include "listas_de_areglos.c"
#include "T_Element.c"

int cargar_coeficientes(Lista coeficientes)
{
    int n;
    do
    {
        printf("Ingrese el número de coeficientes (hasta 100): ");
        if (scanf("%d", &n) != 1)
        {
            printf("Error: debe ingresar un número entero.\n");
            fflush(stdin);
            n = 0;
        }
        fflush(stdin);
    } while (n < 1 || n > 100);

    printf("Ingrese los coeficientes: ");
    for (int i = 0; i < n; i++)
    {
        TipoElemento coef;
        int k;
        do
        {
            printf("Coeficiente %d: ", i + 1);
            if (scanf("%d", &k) != 1)
            {
                printf("Error: debe ingresar un número entero.\n");
                fflush(stdin);
                // coef = NULL;
            }
            fflush(stdin);
        } while (coef == 0);
        coef = te_crear(k);
        l_agregar(coeficientes, coef);
    }

    return n;
}

TipoElemento valor_de_x(float x, Lista coeficientes)
{
    int g = coeficientes->cantidad;
    float resul = 0;
    TipoElemento y = te_crear(0);
    for (int i = 0; i < g; i++)
    {
        TipoElemento aux = l_recuperar(coeficientes, i);
        resul = (resul + (aux->clave * pow(x, g - 1)));
    }
    char *s = malloc(30 * sizeof(char));
    sprintf(s, "F(%f) = %f", x, resul);
    y->valor = (void *)s;
    return y;
}
int cant_inter(float inic, float fina, float inter)
{
    int interacciones = 0;
    if (inic <= fina)
    {
        while (inic <= fina)
        {
            interacciones++;
            inic += inter;
        }
    }
    else
    {
        while (inic >= fina)
        {
            interacciones++;
            inic -= inter;
        }
    }
    return interacciones;
}

Lista valores_de_x_intervalo(float inic, float fina, float inter, Lista coeficientes)
{
    Lista valores = l_crear();
    int i = cant_inter(inic, fina, inter);
    if (i <= 50)
    {
        if (inic < fina)
        {
            while (inic <= fina)
            {
                l_agregar(valores, valor_de_x(inic, coeficientes));
                inic = inic + inter;
            }
        }
        else
        {
            while (inic >= fina)
            {
                l_agregar(valores, valor_de_x(inic, coeficientes));
                inic = inic + inter;
            }
        }
    }
    return valores;
}

int main()
{
    Lista coeficientes = l_crear();
    int n = cargar_coeficientes(coeficientes);

    printf("Los coeficientes ingresados son: ");
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", coeficientes[i]);
    }
    printf("\n");

    float x;
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);

    // calcular el valor de la función para x
    TipoElemento fx = valor_de_x(x, coeficientes);
    printf("%s\n", (char *)fx->valor);

    // calcular los valores de la función en un intervalo
    float inic, fina, inter;
    printf("Ingrese el inicio del intervalo: ");
    scanf("%f", &inic);
    printf("Ingrese el fin del intervalo: ");
    scanf("%f", &fina);
    printf("Ingrese el intervalo: ");
    scanf("%f", &inter);
    // printf(" %f ", );
    Lista valores = valores_de_x_intervalo(inic, fina, inter, coeficientes);
    int len = l_longitud(valores);
    for (int i = 0; i < len; i++)
    {
        TipoElemento elem = l_recuperar(valores, i);
        printf("%s\n", (char *)elem->valor);
    }

    return 0;
}
