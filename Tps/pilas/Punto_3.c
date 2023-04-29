#include <stdio.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
//#include "pilas_puntero.c"

void cargar_pila(Pila pila);
bool verificarEntradaInt(int* valor);
bool pilas_iguales(Pila p1, Pila p2);

int main(){
    Pila pila1 = p_crear();
    Pila pila2 = p_crear();
    bool resultado; 

    cargar_pila(pila1);
    p_mostrar(pila1);
    cargar_pila(pila2);
    p_mostrar(pila2);

    resultado = pilas_iguales(pila1, pila2);
    if(resultado){ printf("Las pilas son iguales\n"); }
    else{ printf("Las pilas NO son iguales\n"); }
    printf("Pila 1, ");
    p_mostrar(pila1);
    printf("Pila 2, ");
    p_mostrar(pila2);

    printf("---------------------------------------------------------------\n");
    printf("La complejidad algorítimica de la resolución es de Orden Lineal");
    return 0;
}


//---------------------------------------------------------------------
// Procedimiento para cargar pila de forma manual por el usuario
//---------------------------------------------------------------------
void cargar_pila(Pila pila){
    int valor = 0;
    bool agregar = true;

    while(agregar){
        printf("Ingrese el valor del dato para guardar en la Pila o cualquier letra para finalizar la carga : ");
        if(!verificarEntradaInt(&valor)){ agregar = false; }
        else{
            TipoElemento te = te_crear(valor);
            p_apilar(pila, te);
        }
    }

    // Limpiamos el buffer de entrada
    while (getchar() != '\n');
}

//---------------------------------------------------------------------
// Función para verificar que la entrada sea Entero
//---------------------------------------------------------------------
bool verificarEntradaInt(int* valor){
    if(scanf("%d", valor) != 1)return false;
    else return true;
}

//---------------------------------------------------------------------
// Dadas dos pilas, determinar si sus contenidos son 
// exactamente iguales (solo por la clave), sin destruirlas. 
// Utilizar para la resolución del problema una única pila auxiliar.
// Determinar la complejidad algorítmica de la solución.
//---------------------------------------------------------------------
bool pilas_iguales(Pila p1, Pila p2){
    TipoElemento te = te_crear(0);
    TipoElemento te2 = te_crear(0);
    Pila pila_aux = p_crear();
    bool resultado = true;

    while(p_es_vacia(p1) != true && p_es_vacia(p2) != true)
    {
        te = p_desapilar(p1);
        te2 = p_desapilar(p2);

        if(te->clave != te2->clave){ resultado = false; }
        
        p_apilar(pila_aux, te);
        p_apilar(pila_aux, te2);
    }

    if(p_es_vacia(p1) && p_es_vacia(p2) != true){ resultado = false; }
    else if ((p_es_vacia(p1) != true && p_es_vacia(p2))){ resultado = false; }

    while(p_es_vacia(pila_aux) != true)
    {
        te = p_desapilar(pila_aux);
        te2 = p_desapilar(pila_aux);
        p_apilar(p2, te);
        p_apilar(p1, te2);
    }
    
    return resultado;
}