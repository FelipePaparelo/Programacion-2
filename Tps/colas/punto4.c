/*
Dada una cola de números enteros, no ordenada, construir un algoritmo que permita
pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el
contenido de la cola original y dejándola en su estado inicial. Determinar la
complejidad algorítmica de la solución
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"
#include <stdbool.h>

Cola sin_repetir(Cola c);
Cola copia(Cola c);

//------------------------------------------------------
// MAIN
//------------------------------------------------------
int main(){
    Cola cola_original = c_crear();
    Cola cola_resultado = c_crear();
    return 0;
}

//------------------------------------------------------
// Función para duplicar una pila
//------------------------------------------------------
Cola copia(Cola c){
    Cola c_copia = c_crear();
    Cola c_original = c_crear();
    TipoElemento x = te_crear(0);
    int longitud = c_longitud(c);
    
    if(c_es_vacia(c)){
        return;
    }
    
    while(c_es_vacia(c) != true){
        x = c_desencolar(c);
        c_encolar(c_copia, x);
        c_encolar(c_original, x);
    }

    while (c_es_vacia(c_original) != true)
    {
        x = c_desencolar(c_original);
        c_encolar(c, x);
    }
    
    return c_copia;
}

//--------------------------------------------------------
// Función para obtener una pila sin las claves repetidas
//--------------------------------------------------------
Cola sin_repetir(Cola c){
    TipoElemento te = te_crear(0);
    TipoElemento x = te_crear(0);
    Cola cola_duplicada = c_crear();
    Cola cola_auxiliar = c_crear();
    Cola cola_resultado = c_crear();
    bool encontrado;

    cola_duplicada = copia(c);
    
    while (c_es_vacia(c) != true)
    {
        encontrado = false; 
        te = c_desencolar(c);
        c_encolar(cola_auxiliar, te);
        while (c_es_vacia(cola_duplicada) != true)
        {
            x = c_desencolar(cola_duplicada);
            if(te->clave == x->clave){ encontrado = true; }
        }

        if(encontrado == false){ c_encolar(cola_resultado, te); }
    }

    return cola_resultado;
}