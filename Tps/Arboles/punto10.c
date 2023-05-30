#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbol-binario-busqueda.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "Nodo_funciones.c"
#include "arbol-binario-busqueda.c"
#include "arbol-avl.h"
#include "arbol-avl.c"
#include <time.h>

// Dada una serie de números generados al azar, cargar la misma serie en un árbol
// binario de búsqueda y en un árbol binario balanceado “AVL”. Comparar la altura de
// ambos árboles. Repetir el proceso “n” veces. ¿Qué puede concluir al respecto?

void altint(NodoArbol Q, int *h, int c)
{
    if (Q == NULL)
    {
        if (c > *h)
        {
            *h = c;
        }
    }
    else
    {
        altint(n_hijoizquierdo(Q), h, c + 1);
        altint(n_hijoderecho(Q), h, c + 1);
    }
}

int altura_abb(ArbolBinarioBusqueda A)
{
    int alt = 0;
    altint(abb_raiz(A), &alt, -1);
    return alt;
}

int altura_avl(ArbolAVL A)
{
    int alt = 0;
    altint(avl_raiz(A), &alt, -1);
    return alt;
}

void validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
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
            if (j == 0 && m[j] == '-')
            {
                aux++;
            }

            if (isdigit(m[j]))
            {
                aux++;
            }
        }

        if (aux == largo && aux <= 9)
        {
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("Intente otra vez (o ingrese 'q' para salir): ");
            fgets(m, 100, stdin);
            largo = strlen(m) - 1;

            if (strcmp(m, "q\n") == 0)
            {
                exit(0);
            }
        }
    }
}

void pedir_cantidad_valores(int *cant)
{
    char cad[100];
    bool flag = false;
    fgets(cad, 100, stdin);
    validar_numeros(cad);
    *cant = atoi(cad);
    while (flag != true)
    {
        if (*cant > 2000 || *cant < 0)
        {
            printf("Dato invalido, pruebe con otro:\n");
            printf("Ingrese la cantidad de valores que quiera ingresar: \n");
            pedir_cantidad_valores(cant);
        }
        else
        {
            flag = true;
        }
    }
}
void pedir_cantidad_veces(int *count)
{
    char cad[100];
    bool flag = false;
    fgets(cad, 100, stdin);
    validar_numeros(cad);
    *count = atoi(cad);
    while (flag != true)
    {
        if (*count > 200 || *count < 0)
        {
            printf("Dato invalido, pruebe con otro:\n");
            printf("Ingrese la cantidad de veces que quiera que se repite: \n");
            pedir_cantidad_veces(count);
        }
        else
        {
            flag = true;
        }
    }
}

void aleatorio(int cant, ArbolBinarioBusqueda abb_rand, ArbolAVL aavl_rand)
{
    int count = 0;
    TipoElemento n;
    n = te_crear(rand() % 2000);
    abb_insertar(abb_rand, n);
    avl_insertar(aavl_rand, n);

    while ((count < cant))
    {
        n = te_crear(rand() % 2000);
        while ((avl_buscar(aavl_rand, n->clave)) != NULL)
        {
            n = te_crear(rand() % 2000);
        }
        abb_insertar(abb_rand, n);
        avl_insertar(aavl_rand, n);
        srand(time(NULL));
        count++;
    }
}
void destruir(NodoArbol nodo)
{
    if (nodo != NULL)
    {
        destruir(n_hijoderecho(nodo));
        destruir(n_hijoizquierdo(nodo));
        free(nodo);
    }
}

void calcular_altura_prom(int cant, int count)
{
    int promavl = 0, promabb = 0, alt_avl = 0, alt_abb = 0;
    int i = 0;

    while (count >= i)
    {
        ArbolBinarioBusqueda abb_rand = abb_crear();
        ArbolAVL aavl_rand = avl_crear();
        aleatorio(cant, abb_rand, aavl_rand);

        alt_abb = altura_abb(abb_rand);
        alt_avl = altura_avl(aavl_rand);
        printf("La altura del ABB es: %i.\n", alt_abb);
        printf("La altura del AVL es: %i.\n", alt_avl);

        promabb += alt_abb;
        promavl += alt_avl;
        i++;
        destruir(abb_raiz(abb_rand));
        // destruir(avl_raiz(aavl_rand));
        free(abb_rand);
        // free(aavl_rand);
    }

    promabb /= count;
    promavl /= count;
    printf("La altura promedio del ABB es: %i.\n", promabb);
    printf("La altura promedio del AVL es: %i.\n", promavl);
}
int main()
{
    int cant = 0;
    int count = 0;
    printf("Ingrese la cantidad de valores que quiera imgresar: \n");
    pedir_cantidad_valores(&cant);
    printf("Ingrese la cantidad de veces que quiera que se repite: \n");
    pedir_cantidad_veces(&count);

    printf("%i,%i", cant, count);
    calcular_altura_prom(cant, count);

    // resumen
    printf("En cuanto a la conclucion que obtuvimos fue que el arbol AVL tiene la capacidad de balancearse y eso hace que quede mucho mas chico que un ABB.\n");
    return 0;
}