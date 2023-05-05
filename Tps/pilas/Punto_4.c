#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
//#include "pilas_puntero.c"

bool verificarEntradaInt(int* valor);
char* conversion_de_base(int valor, int base);
int cantidad_elementos(Pila p);
void p_intercambiar(Pila pAux, Pila p);

int main(){
    int a_convertir, base;
    char* resultado;

    //------------------------------------------------------
    // Se pide el valor a convertir y la base
    //------------------------------------------------------
    printf("Ingresar el valor que desea convertir : ");
    if(!verificarEntradaInt(&a_convertir)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }
    
    printf("Ingrese la base a la que quiere convertir [2, 16] : ");
    if(!verificarEntradaInt(&base)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else if (base < 2 || base > 16)
    {
        printf("El valor de la base debe estar entre 2 y 16...");
        return 0;
    }

    resultado = conversion_de_base(a_convertir, base);
    printf("El valor %d en base %d es : %s \n", a_convertir, base, resultado);

    printf("-------------------Complejidad----------------------\n");
    printf("La complejidad algorítmica es Orden Logarítmico");

    free(resultado);
    return 0;
}

//---------------------------------------------------------------------
// Función para verificar que la entrada sea Entero
//---------------------------------------------------------------------
bool verificarEntradaInt(int* valor){
    if(scanf("%d", valor) != 1)return false;
    else return true;
}

//---------------------------------------------------------------------
// Función para verificar la cantidad de elementos de la pila
//---------------------------------------------------------------------
int cantidad_elementos(Pila p){
    int cantidad = 0;
    Pila pila_aux = p_crear();
    TipoElemento te = te_crear(0);
    
    while(p_es_vacia(p) != true)
    {
        cantidad++;
        te = p_desapilar(p);
        p_apilar(pila_aux, te);
    }

    p_intercambiar(pila_aux, p);
    return cantidad;
}

//------------------------------------------------------
// Procedimiento para intercambiar los elementos 
// de una pila
//------------------------------------------------------
void p_intercambiar(Pila pAux, Pila p){
    TipoElemento te = te_crear(0);

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }
}

//-----------------------------------------------------------------------------
// Construir un algoritmo que, utilizando el TAD Pila, 
// permita convertir un número decimal pasado como parámetro, 
// a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal). 
// Determinar la complejidad algorítmica de la solución.
//-----------------------------------------------------------------------------

char* conversion_de_base(int valor, int base){
    TipoElemento te = te_crear(0);
    Pila pila_resultado = p_crear();
    char* resultado = (char*)calloc(30,1);
    int resto = 0;
    int indice = 0;

    while(valor > 0)
    {
        resto = valor % base;
        valor = valor / base;

        te = te_crear(resto);
        p_apilar(pila_resultado, te);
    }
    

    while (p_es_vacia(pila_resultado) != true)
    {   
        te = p_desapilar(pila_resultado);

        if (te->clave > 9 && te->clave < 16){ 
            *(resultado + indice) = 55 + te->clave; 
        }
        else{ 
            *(resultado + indice) = 48 + te->clave; 
        }
        indice++;
    }

    return resultado;
}