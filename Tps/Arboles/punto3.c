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

TipoElemento padre(ArbolBinario A, int clave);
Lista hijos(ArbolBinario a, int clave);
TipoElemento hermano(ArbolBinario a, int clave, TipoElemento padre);
int altura(ArbolBinario a, int clave);
int altura_subarbol(ArbolBinario a, int clave);

void pre_orden(NodoArbol n);
void in_orden(NodoArbol N);
void post_orden(NodoArbol N);

bool verificar_entrada(int *valor);
bool verificar_entrada_int(int *valor);
void cargar_arbol(ArbolBinario a);
void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo);


int main()
{
    ArbolBinario a = a_crear();
    int nodo_clave;
    TipoElemento nodo_padre = te_crear(0);
    TipoElemento nodo_hermano = te_crear(0);
    Lista lista_hijos = l_crear();
    int altura_nodo;
    int altura_rama;

    if (a_es_vacio(a)) {
        printf("El arbol se creo y esta vacio!\n");
    }

    cargar_arbol(a);

    // LLamo al mostrar arbol
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

    printf("Ingresar la clave del nodo con el que se va a realizar el ejercicio : ");
    if(!verificar_entrada_int(&nodo_clave)){
        printf("El dato de la clave no es un Entero");
        return 0;
    }else if(nodo_clave < -9999999 || nodo_clave > 9999999){
        printf("El valor debe estar en el rango de -9999999 y 9999999");
        return 0;
    }

    //-----------------------------------------------------------------
    // Obtener cual es la clave del nodo padre
    //-----------------------------------------------------------------
    nodo_padre = padre(a, nodo_clave);
    if(nodo_padre == NULL){ printf("El nodo %d NO tiene padre\n", nodo_clave); }
    else{ printf("El nodo padre de %d es : %d\n", nodo_clave, nodo_padre->clave); }


    //-----------------------------------------------------------------
    // Obtener una lista con los hijos
    //-----------------------------------------------------------------
    lista_hijos = hijos(a, nodo_clave);
    printf("Los hijos del nodo %d es :");
    l_mostrarLista(lista_hijos);


    //-----------------------------------------------------------------
    // Obtener el Hermano del nodo elegido
    //-----------------------------------------------------------------
    nodo_hermano = hermano(a, nodo_clave, nodo_padre);
    printf("El nodo hermano de %d es : %d\n", nodo_clave, nodo_hermano->clave);
    

    //-----------------------------------------------------------------
    // Obtener la altura en la que se encuentra la clave elegida
    //-----------------------------------------------------------------
    altura_nodo = altura(a, nodo_clave);
    if(altura_nodo < 0){ printf("La clave a buscar no existe en el arbol\n"); }
    else{ printf("El nivel del nodo %d es : %d\n", nodo_clave, altura_nodo); }


    //-----------------------------------------------------------------
    // Obtener la altura del subarbol
    //-----------------------------------------------------------------
    altura_rama = altura_subarbol(a, nodo_clave);
    if(altura_rama < 0){ printf("La clave a buscar no existe en el arbol\n"); }
    else{ printf("La altura del SubArbol %d es : %d\n", nodo_clave, altura_rama); }
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
// Nombre del padre de un nodo. PUNTO 3A
//---------------------------------------------------------
void padre_interno(NodoArbol q, int clave, TipoElemento* padre){
    TipoElemento x;
    TipoElemento y;

    if(q == NULL) { }
    else {
        if(n_hijoizquierdo(q) != NULL){ 
            x = n_recuperar(n_hijoizquierdo(q)); 
            if (x->clave == clave) {
                *padre = n_recuperar(q);
            }
        }
        
        if(n_hijoderecho(q) != NULL){ 
            y = n_recuperar(n_hijoderecho(q)); 
            if(y->clave == clave){
                *padre = n_recuperar(q);
            }
        }

        // Se hace el recorrido del arbol
        padre_interno(n_hijoizquierdo(q), clave, padre);
        padre_interno(n_hijoderecho(q), clave, padre);
    }
}

TipoElemento padre(ArbolBinario a, int clave){
    TipoElemento resultado = te_crear(0);
    TipoElemento x = te_crear(0);

    // Verificamos si la clave a buscar es la Raíz,
    // si lo es entonces devolvemos un nulo
    // sino hacemos la busqueda por todo el árbol
    x = n_recuperar(a_raiz(a));
    if(x->clave == clave){ resultado = NULL; }
    else{ padre_interno(a_raiz(a), clave, &resultado); }
    
    return resultado;
};


//---------------------------------------------------------
// Hijos de un nodo en específico. PUNTO 3B
//---------------------------------------------------------
void hijos_interno(NodoArbol q, int clave, Lista l){
    TipoElemento x;
    TipoElemento y;

    if(q == NULL) { }
    else {
        x = n_recuperar(q);
        if(x->clave == clave){
            if(n_hijoizquierdo(q) != NULL){ l_agregar(l, n_recuperar(n_hijoizquierdo(q))); }
            if(n_hijoderecho(q) != NULL){ l_agregar(l, n_recuperar(n_hijoderecho(q))); }
        }

        // Se hace las llamadas a los nodos hijos
        hijos_interno(n_hijoizquierdo(q), clave, l);
        hijos_interno(n_hijoderecho(q), clave, l);
    }
}

Lista hijos(ArbolBinario a, int clave){
    Lista lista_hijos = l_crear();
    hijos_interno(a_raiz(a), clave, lista_hijos);
    return lista_hijos;
}


//---------------------------------------------------------
// Hermano de un nodo en específico. Punto 3C
//---------------------------------------------------------
void hermano_interno(NodoArbol q, int clave, TipoElemento padre, TipoElemento* resultado){
    TipoElemento x;
    TipoElemento y;

    if(q == NULL){}
    else{
        x = n_recuperar(q);
        if(x->clave == padre->clave){
            if(n_hijoizquierdo(q) != NULL){
                y = n_recuperar(n_hijoizquierdo(q));
                if(y->clave != clave){ *resultado = y; }
            }

            if(n_hijoderecho(q) != NULL){
                y = n_recuperar(n_hijoderecho(q));
                if(y->clave != clave){ *resultado = y; }
            }
        }

        hermano_interno(n_hijoizquierdo(q), clave, padre, resultado);
        hermano_interno(n_hijoderecho(q), clave, padre, resultado);
    }
}

TipoElemento hermano(ArbolBinario a, int clave, TipoElemento padre){
    TipoElemento resultado = te_crear(0);
    hermano_interno(a_raiz(a), clave, padre, &resultado);
    return resultado;
}


//---------------------------------------------------------
// Altura de un nodo en específico. Punto 3D
//---------------------------------------------------------
void altura_nodo_interno(NodoArbol q, int clave, int *altura, int nivel){
    TipoElemento x;

    if(q == NULL) {}
    else {
        x = n_recuperar(q);
        if(x->clave == clave){
            *altura = nivel;
        }

        altura_nodo_interno(n_hijoizquierdo(q), clave, altura, nivel+1);
        altura_nodo_interno(n_hijoderecho(q), clave, altura, nivel+1);
    }
}

int altura(ArbolBinario a, int clave){
    int resultado = 0;
    altura_nodo_interno(a_raiz(a), clave, &resultado, 0);

    return resultado;
}


//---------------------------------------------------------
// Altura de SubArbol. Punto 3E (Incompleto)
//---------------------------------------------------------
void altura_total_interno(NodoArbol q, int *altura, int nivel){
    if (q == NULL) {
        if (nivel > *altura) {
            *altura = nivel;
        }
    }
    else {
        altura_total_interno(n_hijoizquierdo(q), altura, nivel+1);
        altura_total_interno(n_hijoderecho(q), altura, nivel+1);
    }
}

void nodo_a_buscar(NodoArbol q, int clave, NodoArbol* resultado){
    TipoElemento x;

    if(q == NULL) {}
    else {
        x = n_recuperar(q);
        if(x->clave == clave){
            *resultado = q;
        }

        nodo_a_buscar(n_hijoizquierdo(q), clave, resultado);
        nodo_a_buscar(n_hijoderecho(q), clave, resultado);
    }
}

int altura_subarbol(ArbolBinario a, int clave){
    int resultado = 0;
    NodoArbol nodo_actual;

    nodo_a_buscar(a_raiz(a), clave, &nodo_actual);
    altura_total_interno(nodo_actual, &resultado, 0);
    return resultado;
}
