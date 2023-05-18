#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "arbol-binario.h"


static const int MAX= 100;

struct ArbolBinarioRep{
    NodoArbol raiz;
    int cantidad_elementos;
};


ArbolBinario a_crear(){
    ArbolBinario n_a=(ArbolBinario)malloc(sizeof(struct ArbolBinarioRep));
    n_a->raiz=NULL;
    n_a->cantidad_elementos=0;
    return n_a;
}

bool a_es_vacio(ArbolBinario a){
    return a->raiz==NULL;
}

bool a_es_lleno(ArbolBinario a){
    return a->cantidad_elementos==MAX;
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te){
    if (pa==NULL){
    }
    else{
        if (pa->hi!=NULL){
            return pa->hi;
        }
        NodoArbol n_a=n_crear(te);
        a->cantidad_elementos++;
        pa->hi=n_a;
        return n_a;
    }
    
}

int a_cantidad_elementos(ArbolBinario a){
    return a->cantidad_elementos;
}

bool a_es_rama_nula(NodoArbol pa){
    return pa == NULL;
}

NodoArbol a_raiz(ArbolBinario a){
    return a->raiz;
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te){
    if(a->raiz != NULL){
        printf("Error! Este arbol ya tiene raiz");
        return a->raiz;
    }
    NodoArbol na = n_crear(te);
    a->raiz = na;
    a->cantidad_elementos++;
    return na;
}

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te){
    if (pa == NULL){

    }
    else{ 
       if (pa->hd != NULL){
        printf("Error! el arbol ya tiene la rama solicitada");
        return pa->hd;
       }
       NodoArbol na = n_crear(te);
        a->cantidad_elementos++;
        pa->hd = na;
        return na;
    }
}