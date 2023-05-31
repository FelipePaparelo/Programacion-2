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
#include "colas.h"
#include "cola_punteros.c"
#include "../tad/listas.h"
#include "../tad/listas_de_areglos.c"
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

///////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////

// d. Retornar el padre de un nodo del árbol (tipo_elemento).
void nodoPadreInt(ArbolBinario A, NodoArbol actual, NodoArbol padre, int c, NodoArbol* R, int* flag){
    if (!a_es_rama_nula(actual)){
        if(n_recuperar(actual)->clave == c){
            *R = padre;
            *flag = 1;
        }
        else{
            nodoPadreInt(A, n_hijoizquierdo(actual), actual, c, R, flag);
            nodoPadreInt(A, n_hijoderecho(actual), padre, c, R, flag);
        }
    }
}

NodoArbol nodopadre(ArbolBinario a, int clave){
    NodoArbol N, R;
    TipoElemento x = te_crear(0);
    TipoElemento y = te_crear(0);
    int flag = 0;
    N = NULL;
    R = a_raiz(a);
    x = n_recuperar(a_raiz(a));
    if(n_recuperar(R)->clave == clave){
        return a_raiz(a); 
    }
    else{
       nodoPadreInt(a, R, NULL, clave, &N, &flag);
    }
    
    if(flag == 0){
        printf("\nLa clave ingresada no se encuentra en el arbol\n");
    }
    else if(flag == 1){
        y = n_recuperar(N);
        printf("padre: %i\n", y->clave);
        return N;  
    }
    
};


///////////////////////////////////////////////////////////////
void hojasint(NodoArbol Q, int *contador){
    TipoElemento x;
    if(Q == NULL){

    }
    else{
        if((n_hijoizquierdo(Q) == NULL && n_hijoderecho(Q) == NULL) || (n_hijoizquierdo(Q) == NULL && n_hijoderecho(Q) != NULL) ){
            x = n_recuperar(Q);
            printf("\nHoja: %i \n", x->clave);
            *contador += 1;
        }
        hojasint(n_hijoizquierdo(Q), contador);
        hojasint(n_hijoderecho(Q), contador);
    }
}

int hojas(ArbolBinario A){
    int contador = 0;
    NodoArbol a = a_raiz(A);
    if(n_hijoizquierdo(a) == NULL && n_hijoderecho(a) == NULL ){
        printf("El arbol no tiene hojas ya que el unico elemento que posee es la raiz\n");
        return 0;
    }
    hojasint(a_raiz(A), &contador);
    printf("El arbol tiene un total de %i hojas", contador);
    return contador;
}

///////////////////////////////////////////////////////////////

Lista anchura(ArbolBinario A){
    Cola c;
    Lista l = l_crear();
    NodoArbol N;
    TipoElemento x;
    if(!a_es_vacio(A)){
        c = c_crear();
        N = a_raiz(A);
        x = n_recuperar(N);
        l_agregar(l, x);
        x = n_recuperar(n_hijoizquierdo(N));
        l_agregar(l, x);
        x = te_crear_con_valor(0, n_hijoizquierdo(N));
        N = (NodoArbol) x->valor;

        
        while (!c_es_vacia(c) || n_hijoderecho(N) != NULL || n_hijoizquierdo(N) != NULL){
            if(n_hijoizquierdo(N) != NULL){
                x = te_crear_con_valor(0, n_hijoizquierdo(N));
                x->clave = n_recuperar(n_hijoizquierdo(N))->clave;
                c_encolar(c, x);
            }
            if(n_hijoderecho(N) != NULL){
                x = te_crear_con_valor(0, n_hijoderecho(N));
                x->clave = n_recuperar(n_hijoderecho(N))->clave;
                N = n_hijoderecho(N);
                l_agregar(l, x);
            }
            else if(n_hijoderecho(N) == NULL){
                x = c_desencolar(c);
                l_agregar(l,x);
                N = (NodoArbol) x->valor;
            }
        }
        
    }
    l_mostrarLista(l);
    return l;
}


///////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////


void hermanos_nodo(NodoArbol A, int clave){
    TipoElemento x;
    if(n_hijoderecho(A) != NULL && n_recuperar(n_hijoderecho(A))->clave != clave){
        x = n_recuperar(n_hijoderecho(A));
        printf("\nhermanos: %i", x->clave);
        hermanos_nodo(n_hijoderecho(A), clave);
    }
    if(n_hijoderecho(A) != NULL){
        if(n_recuperar(n_hijoderecho(A))->clave == clave){
            hermanos_nodo(n_hijoderecho(A), clave);
        }
    }
    
}

int hermanos(ArbolBinario A, int clave){
    NodoArbol N = a_raiz(A);
    NodoArbol Y = a_raiz(A);
    NodoArbol Z = a_raiz(A);
    TipoElemento x;
    Z = nodopadre(A, clave);
    if (clave == n_recuperar(a_raiz(A))->clave){
        printf("La clave deseada para buscar a sus hermanos es la raiz\n");
        return 1;
    }
    if(n_hijoizquierdo(a_raiz(A)) == NULL && n_hijoderecho(a_raiz(A)) == NULL){
        printf("\nAl ingresar un arbol que solo posee la raiz, este mismo no tiene hermanos.\n");
        return 1;
    }
    N = n_hijoizquierdo(Z);
    x = n_recuperar(N);
    printf("\nHermanos: %i", x->clave);
    hermanos_nodo(N, clave);
}



///////////////////////////////////////////////////////////////
int main(){
    ArbolBinario ab=a_crear();
    ArbolBinario ab2=a_crear();
    ArbolBinario ab3=a_crear();
    NodoArbol N;
    NodoArbol Z = a_raiz(ab);
    TipoElemento x;
    TipoElemento y;
    char m[100];
    int z;

    printf("Carga del arbol binario 1\n");
    cargar_arbol(ab);
    pre_orden(a_raiz(ab));
    N = a_raiz(ab);

    printf("\n-----------------------------------------------------------------------\n");
        if(!a_es_vacio(ab)){    
            if(n_hijoderecho(N) != NULL){
            printf("\nEl arbol ingresado no es un arbol binario transformado\n");
            return 0;
            }

            if(n_hijoizquierdo(N) == NULL && n_hijoderecho(N) == NULL){
            printf("\nEl arbol solo tiene un elemento, que es la raiz:\n");
            printf("\nRecorrido en anchura:\n");
            pre_orden(a_raiz(ab));
            }
        
            else if(n_hijoizquierdo(N) != NULL){
            printf("\nRecorrido en anchura:\n");
            anchura(ab);
            }
        }
        else{
            printf("El arbol no se puede recorrer en anchura ya que es vacio!");
        }   
   

    printf("\n-----------------------------------------------------------------------\n");

    printf("\nHojas del arbol:\n");
    hojas(ab);

    printf("\n-----------------------------------------------------------------------\n");

    if(!a_es_vacio(ab)){
        printf("\nIngrese una clave para buscar su padre en el arbol: \n");
        validar_numeros(m);
        z = atoi(m);
        nodopadre(ab, z);
        y = te_crear(z);
        x = n_recuperar(a_raiz(ab));
        if (z == x->clave){
            printf("La clave ingresada para averiguar a su padre es la raiz\n");
        }
    }
    else{
        printf("No se puede encontrar al padre de un elemento si el arbol es vacio!\n");
    }

    printf("\n-----------------------------------------------------------------------\n");

    printf("Comparacion de arboles");
    printf("\nIngrese un nuevo arbol\n");
    cargar_arbol(ab2);
    printf("\nArbol:\n");
    pre_orden(a_raiz(ab2));
    printf("\nIngrese otro nuevo arbol\n");
    cargar_arbol(ab3);
    printf("\nArbol:\n");
    pre_orden(a_raiz(ab3));
    printf("\n");
    arboles_similares(ab2, ab3);

    printf("\n-----------------------------------------------------------------------\n");
    printf("En esta consigna se utiliza el arbol ingresado al principio del programa\n");
    if(!a_es_vacio(ab)){
        printf("\nIngrese una clave para buscar sus hermanos en el arbol: \n");
        validar_numeros(m);
        z = atoi(m);
        hermanos(ab, z);
    }
    else{
        printf("\nNo se puede buscar los hermanos de un nodo si es arbol es vacio!\n");
    }
    

    return 0;
}
