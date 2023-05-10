#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include"colas.h"

static const int MAX = 101;

struct ColaRep{
    TipoElemento *valores;
    unsigned int frente;
    unsigned int  final;
};


int paso(int posi){
    return ((posi%MAX)+1);
}

Cola c_crear(){
    Cola n_c=(Cola)malloc(sizeof(struct ColaRep));
    n_c->valores=calloc((MAX+1),sizeof(TipoElemento));
    n_c->frente=1;
    n_c->final=MAX;
    return n_c;
}

void c_encolar(Cola c,TipoElemento x){
    if (c_es_llena(c)){
        printf("esta llena la cola");
        return;
    }
    c->final=paso(c->final);
    c->valores[c->final]=x;
}

TipoElemento c_desencolar(Cola c){
    if (c_es_vacia(c)){
        return NULL;
    }
    TipoElemento x=c->valores[c->frente];
    c->frente=paso(c->frente);
    return x;
}

bool c_es_llena(Cola c){
    return paso(paso(c->final))==c->frente;
}

bool c_es_vacia(Cola c){
    return paso(c->final)==c->frente;
}

void c_mostrar(Cola c){
    if (c_es_vacia(c)){
        printf("la cola es vacia, no se muestra\n");
        return;
    }
    
    int i=1;
    Cola c_aux=c_crear();
    TipoElemento x=te_crear(0);

    printf("--------------\n");
    printf("los elementos de la cola\n");
    
    while (!c_es_vacia(c)){
        x=c_desencolar(c);
        printf("el elemento %i de la cola es: %i\n",i,x->clave);
        c_encolar(c_aux,x);
        i++;
    }

    while (!c_es_vacia(c_aux)){
        x=c_desencolar(c_aux);
        c_encolar(c,x);
    }

}

TipoElemento c_recuperar(Cola c){
    if (c_es_vacia(c)){
        return NULL;
    }
    TipoElemento x=c->valores[c->frente];
    return x;
}


