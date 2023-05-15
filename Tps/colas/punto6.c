#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
#include "colas_punteros.c"
// #include "colas_arreglos_circular.c"
#include "../tad/listas.h"
#include "../tad/listas_de_areglos.c"
#include "../pilas/pilas.h"
#include "../pilas/pilas_arreglos.c"
// #include "../pilas/pilas_puntero.c"

const int TAM_MAXIMO = 100;


void strtrim(char *cadena) { // C.A.: O(n)
    char *comienzoDeCadena = cadena;
    char *finalDeCadena = cadena + strlen(cadena) - 1;
    while (isspace(*comienzoDeCadena)) {
        comienzoDeCadena++;
    }
    while (isspace(*finalDeCadena) && finalDeCadena >= comienzoDeCadena) {
        finalDeCadena--;
    }
    *(finalDeCadena + 1) = '\0';
    memmove(cadena, comienzoDeCadena,   finalDeCadena - comienzoDeCadena + 2);
}



bool estaEnLista(Lista L, int dato) { // C.A.: O(n)
    Iterador iter = iterador(L);
    TipoElemento X;
    bool resultado=false;
    while(hay_siguiente(iter) && (resultado==false)){
        X = siguiente(iter);
        if(X->clave == dato){
            resultado= true;
        }
    }
    return resultado;
}
int leer_entero() { // C.A.: O(n^2)
    char entrada[100];
    long numero;
    char *finptr;
    int valido = 0;
    while (!valido) {
        printf("Ingrese un numero entero: ");
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strlen(entrada)-1] = '\0';
        strtrim(entrada);
        errno = 0;
        numero = strtol(entrada, &finptr, 10);
        if (errno != 0 || *finptr != '\0') {
            printf("Entrada invalida. Intentelo de nuevo.\n");
        } else {
            valido = 1;
        }
    }
    return (int) numero;
}

Cola llenar_cola_al_azar() { // C.A.: O(tamano * n)
    Cola cola = c_crear();
    Lista listaAux = l_crear();
    printf("[INGRESO - COLA]\n");
    printf("Tamano de la cola. ");
    int tamano = leer_entero();
    while (tamano > TAM_MAXIMO || tamano <= 0) {
        printf("Tamano invalido. Intentelo de nuevo. ");
        tamano = leer_entero();
    }
    int valor = 0;
    for (int i = 0; i < tamano; i++) {
        valor = (rand() % tamano) + 1;
        while (estaEnLista(listaAux, valor)) {
            valor = (rand() % tamano) + 1;
        }
        TipoElemento elemento = te_crear(valor);
        l_agregar(listaAux, elemento);
        c_encolar(cola, elemento);
    }
    return cola;
}

Pila llenar_pila_al_azar() { // C.A.: O(tamano * n)
    Pila pila = p_crear();
    Lista listaAux = l_crear();
    printf("[INGRESO - PILA]\n");
    printf("Tamano de la pila. ");
    int tamano = leer_entero();
    while (tamano > TAM_MAXIMO || tamano <= 0) {
        printf("Tamano invalido. Intentelo de nuevo. ");
        tamano = leer_entero();
    }
    int valor = 0;
    for (int i = 0; i < tamano; i++) {
        valor = (rand() % tamano) + 1;
        while (estaEnLista(listaAux, valor)) {
            valor = (rand() % tamano) + 1;
        }
        TipoElemento elemento = te_crear(valor);
        l_agregar(listaAux, elemento);
        p_apilar(pila, elemento);
    }
    return pila;
}

Cola copiar_cola(Cola colaOriginal) { // C.A.: O(n)
    Cola colaAuxiliar = c_crear();
    Cola colaCopia = c_crear();
    while (!c_es_vacia(colaOriginal)) {
        TipoElemento elemento = c_desencolar(colaOriginal);
        c_encolar(colaAuxiliar, elemento);
    }
    while (!c_es_vacia(colaAuxiliar)) {
        TipoElemento elemento = c_desencolar(colaAuxiliar);
        c_encolar(colaCopia, elemento);
        c_encolar(colaOriginal, elemento);
    }
    return colaCopia;
}

Pila copiar_pila(Pila pilaOriginal) { // C.A.: O(n)
    Pila pilaAuxiliar = p_crear();
    Pila pilaCopia = p_crear();
    while (!p_es_vacia(pilaOriginal)) {
        TipoElemento elemento = p_desapilar(pilaOriginal);
        p_apilar(pilaAuxiliar, elemento);
    }
    while (!p_es_vacia(pilaAuxiliar)) {
        TipoElemento elemento = p_desapilar(pilaAuxiliar);
        p_apilar(pilaOriginal, elemento);
        p_apilar(pilaCopia, elemento);
    }
    return pilaCopia;
}



// 6. Dada una pila y una cola generada con valores al azar retornar en una lista todos los
// valores comunes a ambas y en qué posición ordinal se encontró cada uno en su
// estructura. No se deben destruir las estructuras originales. No se deben perderse las
// estructuras originales. Determinar la complejidad algorítmica de la solución empleada.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5).
 
void mostrar_posiciones_ordinales(Lista lista) { // C.A.: O(n)

    if (l_es_vacia(lista)) {
        printf("No se repiten posiciones.\n");
    } else {
        Iterador iter = iterador(lista);
        while (hay_siguiente(iter)) {
            TipoElemento elemento = siguiente(iter);
            printf("%d:%s ", elemento->clave, (char*)elemento->valor);
        }
    }
}


Lista repetidos_con_ordinal(Pila pila, Cola cola) { // C.A.: O(m * n), donde "m" es el tamaño de la pila y "n" es el tamaño de la cola
    Lista lista = l_crear();
    Cola copiaCola = copiar_cola(cola);
    Pila copiaPila = copiar_pila(pila);
    int contadorCola = 0;
    int contadorPila = 0;
    while (!p_es_vacia(copiaPila)) {

        TipoElemento elementoActualPila = p_desapilar(copiaPila);
        contadorPila++;

        while (!c_es_vacia(copiaCola)) {

            TipoElemento elementoActualCola = c_desencolar(copiaCola);
            contadorCola++;

            if (elementoActualCola->clave == elementoActualPila->clave) {

                char posP[10];
                itoa(contadorPila, posP, 10);
                char posC[10];
                itoa(contadorCola, posC, 10);

                char resultado[20] = "";
                strcat(resultado, posP);
                strcat(resultado, ":");
                strcat(resultado, posC);
                char* valorAux = (char*) malloc(sizeof(char) * 10);
                strcpy(valorAux, resultado);

                TipoElemento elementoAgregar = te_crear(elementoActualPila->clave);
                elementoAgregar->valor = valorAux;
                l_agregar(lista, elementoAgregar);
            }
        }

        contadorCola = 0;
        copiaCola = copiar_cola(cola);
    }
    mostrar_posiciones_ordinales(lista);
    return lista;
}


int main() {
    
    Pila pila = llenar_pila_al_azar();
    Cola cola = llenar_cola_al_azar();
    int cantidad_elementos = 1;
    cargar_cola(cola, cantidad_elementos);
    cargar_datos_teclado_pila(cantidad_elementos, pila);
    p_mostrar(pila);
    c_mostrar(cola);
    printf("[REPETIDOS CON ORDINAL]\n");
    Lista repetidos = repetidos_con_ordinal(pila, cola);
    printf("\n-----------------\n");
    printf("La mayor complejidad la posee la funcion leer_entero() -> O(n^2)\n");
    printf("La complejidad de la funcion pedida en el ejercicio (repetidos_con_ordinal()) tiene complejidad de O(m * n)\n");
    return 0;
}