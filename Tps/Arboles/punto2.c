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
#include "C:\Users\nahul\OneDrive\Documentos\GitHub\Programacion-2\Tps\tad\listas_de_areglos.c"

Lista hojas(ArbolBinario A);
Lista internos(ArbolBinario a);

void pre_orden(NodoArbol n);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);

bool verificar_entrada(int *valor);
void cargar_arbol(ArbolBinario a);
void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo);


int main()
{
    // Árbol para realizar el ejercicio
    ArbolBinario a = a_crear();
    // Lista que va a contener las hojas del árbol (Ejercicio 2A)
    Lista lista_hojas = l_crear();
    // Lista que va a contener los nodos internos del árbol (Ejercicio 2B)
    Lista lista_nodos_internos = l_crear();

    if (a_es_vacio(a)) {
        printf("El arbol se creo y esta vacio!\n");
    }

    cargar_arbol(a);

    if(a_es_vacio(a)){ 
        printf("El árbol está vacío, fin del programa."); 
        return 0;
    }

    // Se muestra el árbol en las diferentes formas de recorrido
    printf("-----------------------------------------------------\n");
    printf("Pre-Orden Desde la raiz\n");
    pre_orden(a_raiz(a));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("In-Orden Desde la raiz\n");
    in_orden(a_raiz(a));
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("Post-Orden Desde la raiz\n");
    post_orden(a_raiz(a));
    printf("\n");


    //-----------------------------------------------------------------
    // Obtiene todos los nodos hojas del árbol
    //-----------------------------------------------------------------
    printf("-----------------------------------------------------\n");
    lista_hojas = hojas(a);
    printf("Los nodos hojas son : ");
    l_mostrarLista(lista_hojas);


    //-----------------------------------------------------------------
    // Obtiene todos los nodos internos del árbol
    //-----------------------------------------------------------------
    printf("-----------------------------------------------------\n");
    lista_nodos_internos = internos(a);
    printf("Los nodos internos son : ");
    l_mostrarLista(lista_nodos_internos);
}

//-------------------------------------
// Muestra el arbol en forma pre-orden
//-------------------------------------
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

//-------------------------------------
//Muestra el arbol en forma in-orden
//-------------------------------------
void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

//-------------------------------------
//Muestra el arbol en forma post-orden
//-------------------------------------
void post_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}

//---------------------------------------------------------
// Verificar entrada de datos
//---------------------------------------------------------
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

//---------------------------------------------------------
// Cargar Arbol
//---------------------------------------------------------
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

//---------------------------------------------------------
// Funcion que retorna los nodos hojas en una lista
//---------------------------------------------------------
void hojas_interno(NodoArbol Q, Lista l){
    TipoElemento x;

    if(Q == NULL) { }
    else {
        // averigua si es un hoja
        if ((n_hijoizquierdo(Q) == NULL) && (n_hijoderecho(Q) == NULL)) {
            x = n_recuperar(Q);
            l_agregar(l, x);
        }
        // Llamo para el recorrido
        hojas_interno(n_hijoizquierdo(Q), l);
        hojas_interno(n_hijoderecho(Q), l);
    }
}

Lista hojas(ArbolBinario A){
    Lista lista_hojas = l_crear();
    hojas_interno(a_raiz(A), lista_hojas);
    return lista_hojas;
};


//---------------------------------------------------------
// Funcion para encontrar los nodos internos del arbol
//---------------------------------------------------------
void nodos_interno(ArbolBinario a, NodoArbol q, Lista l){
    TipoElemento x;
    TipoElemento aux;

    if(q == NULL){}
    else{
        bool condicion_1 = n_hijoizquierdo(q) == NULL;
        bool condicion_2 = n_hijoderecho(q) != NULL;
        bool condicion_3 = n_hijoizquierdo(q) != NULL;
        bool condicion_4 = n_hijoderecho(q) == NULL;

        if ((condicion_1 && condicion_2) || (condicion_3 && condicion_4) || (condicion_3 && condicion_2)) {
            x = n_recuperar(q);
            aux = n_recuperar(a_raiz(a));
            if(aux->clave != x->clave){ l_agregar(l, x); }
        }
        // Llamo para el recorrido
        nodos_interno(a, n_hijoizquierdo(q), l);
        nodos_interno(a, n_hijoderecho(q), l);
    }
}

Lista internos(ArbolBinario a){
    Lista lista_resultado = l_crear();
    nodos_interno(a, a_raiz(a), lista_resultado);
    return lista_resultado;
}