#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "colas.h"

int c_longitud_fu(Cola c){
    int cont=0;
    TipoElemento x;
    Cola c_aux=c_crear();
    while (!c_es_vacia(c)){
        x=c_desencolar(c);
        cont++;
        c_encolar(c_aux,x);
    }
    while (!c_es_vacia(c_aux)){
        x=c_desencolar(c_aux);
        c_encolar(c,x);
    }
    return cont;
}