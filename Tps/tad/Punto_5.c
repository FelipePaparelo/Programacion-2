#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "list_point.c"
#include "list_cursor.c"
// #include "listas_de_areglos.c"
#include "T_Element.c"

int cant_inter(float inic, float fina, float inter)
{
    int i = 1;
    if (inic < fina)
    {
        while (inic <= fina)
        {
            i++;
            inic = inic + inter;
        }
    }
    else
    {
        while (inic >= fina)
        {
            i++;
            inic = inic + inter;
        }
    }
    return i;
}

TipoElemento valor_de_x(float x, Lista coeficientes)
{
    Iterador p = coeficientes->inicio;
    int g = coeficientes->cantidad;
    float resul = 0;
    TipoElemento y = te_crear(0);
    for (int i = 0; i < g; i++)
    {
        TipoElemento aux = l_recuperar(coeficientes, i);
        resul = (resul + (aux->clave * pow(x, g)));
        dec(g);
    }
    printf("F(%f) = %f", x, resul);
    int s;
    y->valor = s;
    return y;
}

Lista valores_de_x_intervalo(float inic, float fina, float inter, Lista coeficientes)
{
    Lista valores = l_crear();
    TipoElemento x;
    int i = cant_inter(inic, fina, inter);
    if (i <= 50)
    {
        if (inic < fina)
        {
            while (inic <= fina)
            {
                x = (valor_de_x(inic, coeficientes));
                l_agregar(valores, x);
                inic = inic + inter;
            }
        }
        else
        {
            while (inic >= fina)
            {
                x = (valor_de_x(inic, coeficientes));
                l_agregar(valores, x);
                inic = inic + inter;
            }
        }
    }
    return valores;
}