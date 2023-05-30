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
#include "arbol-avl.h"
#include "arbol-avl.c"
#include "../colas/colas.h"
#include "../colas/colas_punteros.c"
// #include "../colas/colas_arreglos_circular.c"


// Para Árboles “N-arios”:
// Un árbol n-ario puede ser representado como binario utilizando la transformación de
// Knuth. Esto puede ser útil para manejar árboles n-arios en estructuras de
// almacenamiento fijo, sin necesidad de conocer el "n" del árbol. Se propone un árbol
// binario derivado del n-ario, tal que para cada nodo del árbol n-ario, su primer hijo es el
// hijo izquierdo en el árbol binario, y los hermanos de cada nodo son sus hijos derechos.

// a. Dado un árbol n-ario, devolver en forma de lista el resultado del recorrido en
// anchura del árbol (solo las claves).
// b. Escribir una función que, dado un árbol n-ario, devuelva el número (cantidad)
// de hojas de dicho árbol.
// c. Escribir una función booleana que dados dos árboles generales determine si
// tienen la misma estructura, sin importar los datos del mismo (árbol similar).
// d. Retornar el padre de un nodo del árbol (tipo_elemento).
// e. Retornar los hermanos de un nodo del árbol (lista de hermanos). 





bool validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    bool numero;
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

            if ((j == 0) && (m[j] == '-'))
            {
                aux++;
            }

        }

        if (aux == largo && aux<6)
        {
            bandera = 0;
        }
        else if(m[0] == '.' && m[1]== '\n'){
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero positivo o es mayor a 99.999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    if (m[0] == '.'){
        numero=false;
    }
    else{
        numero=true;
    }
    return numero;
}

int cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo){
    TipoElemento x;
    NodoArbol n1;
    char cadena[100];
    bool numero;
    int numero_i;

    if(!a_es_lleno(a)){
        printf("Ingrese un numero o '.' para nulo: ");
        numero=validar_numeros(cadena);
        if (numero){
            //printf("numero a cargar %i \n ",numero);
            numero_i=atoi(cadena);
            x = te_crear(numero_i);

            if(hijo == -1){ 
                n1 = a_conectar_hi(a, n, x); 
            }
            else if(hijo == 1){ 
                n1 = a_conectar_hd(a, n, x); 
            }
            else{
                n1 = a_establecer_raiz(a, x);
            }
            cargar_subArbol(a, n1, -1);
            cargar_subArbol(a, n1, 1);
        }
    }
}

void cargar_arbol(ArbolBinario a){
    cargar_subArbol(a, NULL, 0);
}

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

// d. Retornar el padre de un nodo del árbol (tipo_elemento).
void nodoPadreInt(ArbolBinario A, NodoArbol actual, NodoArbol padre, int c, NodoArbol* R){
    if (!a_es_rama_nula(actual)){
        if(n_recuperar(actual)->clave == c){
            *R = padre;
        }
        else{
            nodoPadreInt(A, n_hijoizquierdo(actual), actual, c, R);
            nodoPadreInt(A, n_hijoderecho(actual), padre, c, R);
        }
    }
}

NodoArbol nodopadre(ArbolBinario a, int clave){
    NodoArbol N, R;
    TipoElemento x = te_crear(0);
    TipoElemento y = te_crear(0);
    
    N = NULL;
    R = a_raiz(a);
    x = n_recuperar(a_raiz(a));
    if(n_recuperar(R)->clave == clave){
        return R; 
    }
    else{
       nodoPadreInt(a, R, NULL, clave, &N);
    }
    
    // return N;
    y = n_recuperar(N);
    printf("padre: %i", y->clave);
};


void hojasint(NodoArbol Q){
    TipoElemento x;
    if(Q == NULL){

    }
    else{
        if((n_hijoizquierdo(Q) == NULL && n_hijoderecho(Q) == NULL) || (n_hijoizquierdo(Q) == NULL && n_hijoderecho(Q) != NULL) ){
            x = n_recuperar(Q);
            printf("\nHoja: %i \n", x->clave);
        }
        hojasint(n_hijoizquierdo(Q));
        hojasint(n_hijoderecho(Q));
    }
}

void hojas(ArbolBinario A){
    hojasint(a_raiz(A));
}

void anchura(ArbolBinario A){
    Cola c;
    NodoArbol N;
    TipoElemento x;
    if(!a_es_vacio(A)){
        c = c_crear();
        N = a_raiz(A);
        x = te_crear_con_valor(0, N);
        c_encolar(c, x);
        while(!c_es_vacia(c)){
            x = c_desencolar(c);
            N = (NodoArbol) x->valor;
            printf(" %d ", n_recuperar(N)->clave);
            if(!a_es_rama_nula(n_hijoizquierdo(N))){
                x = te_crear_con_valor(0, n_hijoizquierdo(N));
                c_encolar(c,x);
            }
            if(!a_es_rama_nula(n_hijoderecho(N))){
                x = te_crear_con_valor(0, n_hijoizquierdo(N));
                c_encolar(c,x);
            }
        }
    }
}

// c. Escribir una función booleana que dados dos árboles generales determine si
// tienen la misma estructura, sin importar los datos del mismo (árbol similar).
void pre_orden_similares(NodoArbol N,NodoArbol P, bool *bandera){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        if((n_hijoizquierdo(N) != NULL && n_hijoizquierdo(P) != NULL) && (*bandera == true)){
            pre_orden_similares(n_hijoizquierdo(N),n_hijoizquierdo(P),  bandera);
        }
        else if((n_hijoizquierdo(N) != NULL && n_hijoizquierdo(P) == NULL) || (n_hijoizquierdo(N) == NULL && n_hijoizquierdo(P) != NULL) && (*bandera == true)){
            
            *bandera = false;
        }
        if((n_hijoderecho(N) != NULL && n_hijoderecho(P) != NULL) && (*bandera == true)){
            pre_orden_similares(n_hijoderecho(N),n_hijoderecho(P), bandera);
        }
        else if((n_hijoderecho(N) != NULL && n_hijoderecho(P) == NULL) || (n_hijoderecho(N) == NULL && n_hijoderecho(P) != NULL) && (*bandera == true)){
           
            *bandera = false;
        }
    }
}

bool arboles_similares(ArbolBinario A, ArbolBinario B){
    bool bandera = true;
    NodoArbol a = a_raiz(A);
    NodoArbol b = a_raiz(B);
    pre_orden_similares(a, b, &bandera);
    if (bandera == true){
        printf("\nLos arboles son similares.");
    }
    else if(bandera == false){
        printf("Los arboles no son similares.");
    }

}


int main(){
    ArbolBinario ab=a_crear();
    ArbolBinario ab2=a_crear();

    printf("Carga del arbol binario 1\n");
    cargar_arbol(ab);
    printf("Carga del arbol binario 2\n");
    cargar_arbol(ab2);
    pre_orden(a_raiz(ab));
    pre_orden(a_raiz(ab2));
    printf("\n-----------------------------------------------------------------------\n");
    printf("\nRecorrido en anchura:\n");
    // anchura(ab);
    printf("\n-----------------------------------------------------------------------\n");
    printf("\nHojas del arbol:\n");
    hojas(ab);
    printf("\n-----------------------------------------------------------------------\n");
    printf("\nPadre de un nodo a eleccion\n");
    // nodopadre(ab, 4);
    printf("\n-----------------------------------------------------------------------\n");
    printf("\nArboles similares\n");
    arboles_similares(ab,ab2);
    return 0;
}
