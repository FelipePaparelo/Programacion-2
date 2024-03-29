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

            if ((j == 0) && (m[j] == '-')&& (isdigit(m[j+1]) != 0))
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
            printf("El dato que Ingresa no es un numero o es mayor a 99.999 o menor a -9999, intente otra vez: ");
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

void recorrer_arbol(NodoArbol q, ArbolAVL avl){
    TipoElemento x;
    if (q==NULL){

    }
    else{
        x=n_recuperar(q);
        avl_insertar(avl,x);
        recorrer_arbol(n_hijoizquierdo(q),avl);
        recorrer_arbol(n_hijoderecho(q),avl);
    }
    
}

void cargar_arbol_avl(ArbolBinario a, ArbolAVL avl){
    recorrer_arbol(a_raiz(a),avl);
}


void altint(NodoArbol Q, int *h, int c){
    if (Q == NULL) {
        if (c > *h) {
            *h = c;
        }
    }
    else {
        altint(n_hijoizquierdo(Q), h, c+1);
        altint(n_hijoderecho(Q), h, c+1);
    }
}


int altura_ab(ArbolBinario A){
    int alt = 0;
    altint(a_raiz(A), &alt, 0);
    return alt;
}

int altura_avl(ArbolAVL A){
    int alt = 0;
    altint(avl_raiz(A), &alt, 0);
    return alt;
}
// Generar un algoritmo, recursivo o no, que permita construir un árbol binario de 
// búsqueda balanceado (AVL) a partir de un árbol binario sin un orden determinado. 
// Comparar las alturas de ambos árboles. Determinar la complejidad algorítmica. 



int main(){
    ArbolBinario ab=a_crear();
    ArbolAVL a_avl=avl_crear();
    int alt_ab=0,alt_avl=0;
    printf("Bienvenido al punto 9 del tp de arboles\n");
    printf("Carga del arbol binario\n");
    cargar_arbol(ab);
    printf("termino la carga del arbol binario\n");
    if (a_es_vacio(ab)){
        printf("el arbol es vacio, asi que no puede crearse el arbol avl apartir del arbol\n");

    }else{
        printf("Mostrar el arbol binario en pre-orden: \n");
        pre_orden(a_raiz(ab));
        printf("\nComienzo de la carga del arbol avl\n");
        cargar_arbol_avl(ab,a_avl);
        printf("Termino la carga del arbol avl\n");
        printf("Mostrar el arbol avl en pre-orden: \n");
        pre_orden(avl_raiz(a_avl));
        alt_ab=altura_ab(ab);
        printf("\n altura del arbol binario: %i\n",alt_ab);
        alt_avl=altura_avl(a_avl);
        printf(" altura del arbol avl: %i\n",alt_avl);
        if (alt_ab > alt_avl){
            printf("el arbol avl tiene menos altura que el arbol binario.\n");
            printf("la complejidad algoritmica de la funcion que resuelve el problema es de O(n).\n");
        } else if (alt_ab< alt_avl){
            printf("el arbol avl tiene mas altura que el arbol binario.\n");
            printf("la complejidad algoritmica de la funcion que resuelve el problema es de O(n).\n");
        }else{
            printf("el arbol avl tiene la misma altura que el arbol binario.\n");
            printf("la complejidad algoritmica de la funcion que resuelve el problema es de O(n).\n");
        }
    }
    return 0;
}
