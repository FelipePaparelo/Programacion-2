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
#include "cola_punteros.c"

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
        if (*cant > 2000 || *cant <= 0)
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
        if (*count > 200 || *count <= 0)
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
// void destruirArbol(NodoArbol nodo, ArbolBinarioBusqueda abb_rand, ArbolAVL aavl_rand)
// {
//     if (nodo != NULL)
//     {
//         destruirArbol(nodo->hi, abb_rand, aavl_rand);
//         destruirArbol(nodo->hd, abb_rand, aavl_rand);
//         // abb_eliminar(abb_rand, nodo->datos->clave);
//         avl_eliminar(aavl_rand, nodo->datos->clave);
//         free(nodo);
//     }
// }

// void destruir(ArbolBinarioBusqueda abb_rand, ArbolAVL aavl_rand)
// {
//     destruirArbol(abb_rand->raiz, abb_rand, aavl_rand);
//     abb_rand->raiz = NULL;
//     aavl_rand->raiz = NULL;
// }

void destruirArbol(NodoArbol nodo)
{
    if (nodo != NULL)
    {
        destruirArbol(nodo->hi);
        destruirArbol(nodo->hd);
        free(nodo->datos); // Liberar la memoria de los datos
        free(nodo);        // Liberar la memoria del nodo
    }
}
void destruir(ArbolBinarioBusqueda abb_rand, ArbolAVL aavl_rand)
{
    destruirArbol(abb_rand->raiz);
    destruirArbol(aavl_rand->raiz);
}

void aleatorio(int cant, ArbolBinarioBusqueda abb_rand, ArbolAVL aavl_rand)
{
    int count = 0;
    TipoElemento n;
    int *claves = malloc(cant * sizeof(int));

    while (count < cant)
    {
        int clave = rand() % 2000 + 1;

        // Verificar si la clave ya existe en alguno de los árboles
        int clave_existente = 0;
        for (int i = 0; i < count; i++)
        {
            if (claves[i] == clave)
            {
                clave_existente = 1;
                break;
            }
        }

        if (clave_existente)
        {
            continue; // Generar una nueva clave
        }

        claves[count] = clave;
        n = te_crear(clave);
        abb_insertar(abb_rand, n);
        avl_insertar(aavl_rand, n);
        count++;
    }

    free(claves);
}

void calcular_altura_prom(int cant, int count, int alt_avl, int alt_abb)
{
    float promavl = 0, promabb = 0;
    int i = 0;
    int avl_max = 0, avl_min = 1000, abb_max = 0, abb_min = 1000;

    while (count >= i)
    {
        printf("Agregando elemento Nº %d\n", i + 1);
        ArbolBinarioBusqueda abb_rand = abb_crear();
        ArbolAVL aavl_rand = avl_crear();
        aleatorio(cant, abb_rand, aavl_rand);
        alt_abb = altura_abb(abb_rand);
        alt_avl = altura_avl(aavl_rand);

        if (alt_abb > abb_max)
        {
            abb_max = alt_abb;
        }
        if (alt_avl > avl_max)
        {
            avl_max = alt_avl;
        }
        if (alt_avl < avl_min)
        {
            avl_min = alt_avl;
        }
        if (alt_abb < abb_min)
        {
            abb_min = alt_abb;
        }
        promabb += alt_abb;
        promavl += alt_avl;
        destruir(abb_rand, aavl_rand);

        i++;
    }

    promabb /= count;
    promavl /= count;

    printf("Altura promedio AVL: %.2f\n", promavl);
    printf("Altura promedio ABB: %.2f\n", promabb);
    printf("Altura maxima AVL: %d\n", avl_max);
    printf("Altura minima AVL: %d\n", avl_min);
    printf("Altura maxima ABB: %d\n", abb_max);
    printf("Altura minima ABB: %d\n", abb_min);
}
int main()
{
    int alt_avl = 0, alt_abb = 0;
    int cant = 0;
    int count = 0;
    printf("Ingrese la cantidad de valores que quiera imgresar: \n");
    pedir_cantidad_valores(&cant);
    printf("Ingrese la cantidad de veces que quiera que se repite: \n");
    pedir_cantidad_veces(&count);

    calcular_altura_prom(cant, count, alt_avl, alt_abb);

    // resumen
    printf("En cuanto a la conclucion que obtuvimos fue que el arbol AVL tiene la capacidad de balancearse y eso hace que quede mucho mas chico que un ABB.\n");
    return 0;
}