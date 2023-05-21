#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbol-binario.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "Nodo_funciones.c"
#include "I_arboles_binarios.c"

// 7. Determinar si dos árboles binarios son equivalentes

bool verificar_entrada(int *valor){
    char entrada[10];
    bool resultado = true;
    bool negativo = false;
    int i = 0;
    *valor=0;
    printf("Ingrese un numero o '.' para nulo: ");
    scanf("%s", entrada);
    if (entrada[0] == '.'){
        resultado = false;
    }else{
        if(entrada[0] == '-'){
            negativo = true;
            i++;
        }
        for (i; entrada[i] != '\0'; i++) {
            if (!isdigit(entrada[i])){
                printf("El valor ingresado no es un entero, intente de nuevo\n");
                verificar_entrada(valor);    
                break;
            }else if((entrada[i]>='0')&&(entrada[i]<='9')){
                *valor = *valor * 10 + (entrada[i] - 48);
            }
        }
        if(negativo){ *valor = *valor * (-1); }
    }

    return resultado;
}

void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo){
    TipoElemento x;
    NodoArbol n1;
    int valor_a_ingresar;
    bool entero;
    if(!a_es_lleno(a)){
        entero = verificar_entrada(&valor_a_ingresar);
        if(entero){
            x = te_crear(valor_a_ingresar);

            if(hijo == -1){ n1 = a_conectar_hi(a, n, x); }
            else if(hijo == 1){ n1 = a_conectar_hd(a, n, x); }
            else n1 = a_establecer_raiz(a, x);

            cargar_subArbol(a, n1, -1);
            cargar_subArbol(a, n1, 1);
        }
    }
}

void cargar_arbol(ArbolBinario a){
    cargar_subArbol(a, NULL, 0);
}

bool son_equivalentes(ArbolBinario arbolA, ArbolBinario arbolB, bool equivalentes, NodoArbol nodoActualA, NodoArbol nodoActualB) {
    if (equivalentes && !a_es_rama_nula(nodoActualA) && !a_es_rama_nula(nodoActualB)) {
        TipoElemento elementoA = n_recuperar(nodoActualA);
        TipoElemento elementoB = n_recuperar(nodoActualB);
        if (elementoA->clave != elementoB->clave) {
            equivalentes = false;
        }
        son_equivalentes(arbolA, arbolB, equivalentes, n_hijoizquierdo(nodoActualA), n_hijoizquierdo(nodoActualB));
        son_equivalentes(arbolA, arbolB, equivalentes, n_hijoderecho(nodoActualA), n_hijoderecho(nodoActualB));
    } else {
        return equivalentes;
    }
}

int main() {
    ArbolBinario arbolA = a_crear();
    printf("[ARBOL A - INGRESO]\n");
    cargar_arbol(arbolA);
    ArbolBinario arbolB = a_crear();
    printf("[ARBOL B - INGRESO]\n");
    cargar_arbol(arbolB);
    bool equivalentes = true;
    NodoArbol raizA = a_raiz(arbolA);
    NodoArbol raizB = a_raiz(arbolB);
    bool sonEquivalentes = son_equivalentes(arbolA, arbolB, equivalentes, raizA, raizB);
    if (sonEquivalentes) {
        printf("Los arboles ingresados son equivalentes\n");
    } else {
        printf("Los arboles ingresados NO son equivalentes\n");
    }
    return 0;
}