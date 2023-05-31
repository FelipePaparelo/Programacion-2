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
#include "listas_de_arreglos.c"

Lista hojas(ArbolBinario A);
Lista internos(ArbolBinario a);
Lista ocurrencias(ArbolBinario a, int clave);

void pre_orden(NodoArbol n);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);

bool verificar_entrada(int *valor);
void cargar_arbol(ArbolBinario a);
void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo);

void mostrar_valores(Lista lista);
bool verificar_entrada_int(int *valor);


int main()
{
    // Árbol para realizar el ejercicio
    ArbolBinario a = a_crear();
    // Lista que va a contener las hojas del árbol (Ejercicio 2A)
    Lista lista_hojas = l_crear();
    // Lista que va a contener los nodos internos del árbol (Ejercicio 2B)
    Lista lista_nodos_internos = l_crear();
    // Lista que va a contener los punteros de las ocurrencias (Ejercicio 2C)
    Lista lista_nodos_ocurrencias = l_crear();
    int clave_a_buscar;

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
    // Obtiene todos los nodos hojas del árbol (Ejercicio 2A)
    //-----------------------------------------------------------------
    printf("-----------------------------------------------------\n");
    lista_hojas = hojas(a);
    if(l_es_vacia(lista_hojas)){
        printf("No hay hojas en el árbol\n");
    }else{
        printf("Los nodos hojas son : ");
        l_mostrarLista(lista_hojas);
    }

    printf("La complejidad algorítmica es de Orden Lineal\n");
    

    //-----------------------------------------------------------------
    // Obtiene todos los nodos internos del árbol (Ejercicio 2B)
    //-----------------------------------------------------------------
    printf("-----------------------------------------------------\n");
    lista_nodos_internos = internos(a);
    if(l_es_vacia(lista_nodos_internos)){
        printf("No hay nodos internos en el árbol\n");
    }else{
        printf("Los nodos internos son : ");
        l_mostrarLista(lista_nodos_internos);
    }

    printf("La complejidad algorítmica es de Orden Lineal\n");
    

    //-----------------------------------------------------------------
    // Obtiene todos los nodos internos del árbol (Ejercicio 2C)
    //-----------------------------------------------------------------
    printf("-----------------------------------------------------\n");
    printf("Ingresar la clave para buscar las ocurrencias en el árbol : ");
    if(!verificar_entrada_int(&clave_a_buscar)){
        printf("La clave no es un Entero");
        return 0;
    }else if(clave_a_buscar < -9999999 || clave_a_buscar > 9999999){
        printf("El valor debe estar en el rango de -9999999 y 9999999\n");
        //return 0;
    }else{
        printf("Valor ingresado correcto.\n");
    }

    lista_nodos_ocurrencias = ocurrencias(a, clave_a_buscar);
    if(l_es_vacia(lista_nodos_ocurrencias)){
        printf("No hay ocurrencias de la clave dada\n");
    }else{
        printf("Las ocurrencias de la clave %d son : ");
        mostrar_valores(lista_nodos_ocurrencias);
    }

    printf("La complejidad algorítmica es de Orden Lineal\n");
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
bool validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    bool numero;
    fgets(m, 100, stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1){
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for (int j = 0; j < largo; j++){

            if ((isdigit(m[j]) != 0)){ aux++; }
            if ((j == 0) && (m[j] == '-')&& (isdigit(m[j+1]) != 0)){ aux++; }
        }

        if (aux == largo && aux<6){ bandera = 0; }
        else if(m[0] == '.' && m[1]== '\n'){ bandera = 0; }
        else{
            aux = 0;
            printf("El dato que Ingresa no es un numero o es mayor a 99.999 o menor a -9999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

    if (m[0] == '.'){ numero=false; }
    else{ numero=true; }
    return numero;
}

bool verificar_entrada_int(int *valor)
{
    if (scanf("%d", valor) != 1)
        return false;
    else
        return true;
}

//---------------------------------------------------------
// Cargar Arbol
//---------------------------------------------------------
void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo){
    TipoElemento x;
    NodoArbol n1;
    char cadena[100];
    bool numero;
    int numero_i;

    if(!a_es_lleno(a)){
        printf("Ingrese un numero o '.' para nulo: ");
        numero=validar_numeros(cadena);
        if (numero){

            numero_i=atoi(cadena);
            x = te_crear(numero_i);

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

void mostrar_valores(Lista lista)
{
    printf("{ ");
    for (int i = 0; i < lista->cantidad; i++) {
        printf("Clave : %d, ", lista->valores[i]->clave);
        printf("Puntero : %p \n", (NodoArbol)lista->valores[i]->valor);
    }
    printf("}");
    printf("\n");
}

//-----------------------------------------------------------------
// Funcion que retorna los nodos hojas en una lista (Ejercicio 2A)
//-----------------------------------------------------------------
void hojas_interno(NodoArbol Q, Lista l){
    TipoElemento x;

    if(Q != NULL) {
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


//-------------------------------------------------------------------
// Funcion para encontrar los nodos internos del arbol (Ejercicio 2B)
//-------------------------------------------------------------------
void nodos_interno(ArbolBinario a, NodoArbol q, Lista l){
    TipoElemento x;
    TipoElemento aux;

    if(q != NULL){
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


//---------------------------------------------------------------------
// Funcion para encontrar ocurrencias dentro de un arbol (Ejercicio 2C)
//---------------------------------------------------------------------
void ocurrencias_interno(NodoArbol q, int clave, Lista l){
    TipoElemento x;
    TipoElemento valor;

    if(q != NULL){
        x = n_recuperar(q);

        if(x->clave == clave){
            valor = te_crear_con_valor(clave, (NodoArbol)q);
            l_agregar(l, valor);
        }

        // Llamo para el recorrido
        ocurrencias_interno(n_hijoizquierdo(q), clave, l);
        ocurrencias_interno(n_hijoderecho(q), clave, l);
    }
}

Lista ocurrencias(ArbolBinario a, int clave){
    Lista lista_resultado = l_crear();
    ocurrencias_interno(a_raiz(a), clave, lista_resultado);
    return lista_resultado;
}
