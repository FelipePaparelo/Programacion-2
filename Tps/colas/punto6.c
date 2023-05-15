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




// 6. Dada una pila y una cola generada con valores al azar retornar en una lista todos los
// valores comunes a ambas y en qué posición ordinal se encontró cada uno en su
// estructura. No se deben destruir las estructuras originales. No se deben perderse las
// estructuras originales. Determinar la complejidad algorítmica de la solución empleada.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5). 

void validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    int bandera_2;
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

            if ((j == 0) && (m[j] == '-'))
            {
                aux++;
            }

            if ((isdigit(m[j]) != 0))
            {
                aux++;
            }
        }

        bandera_2 = 0;
        if (aux == largo && aux <= 9)
        {
            if (bandera_2 == 1)
            {
                bandera = 1;
            }
            else if (bandera_2 == 0)
            {
                bandera = 0;
            }
        }
        else
        {
            aux = 0;
            printf("intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
}



void p_intercambiar(Pila pAux, Pila p)
{
    TipoElemento te;

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }
}


void validar_numeros_no_rep_pila(char *m, Pila pila)
{
    int aux = 0;
    Pila p_aux = p_crear();
    int bandera = 1, p, num_de_m, bandera_2;
    TipoElemento x;
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

            if ((j == 0) && (m[j] == '-'))
            {
                aux++;
            }

            if ((isdigit(m[j]) != 0))
            {
                aux++;
            }
        }

        bandera_2 = 0;
        num_de_m = atoi(m);
        if (aux == largo && aux <= 9)
        {

            if (num_de_m > 100000000 || num_de_m < -10000000)
            {
                bandera_2 = 1;
                aux = -1;
                printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            }
            else{
                bandera_2 = 0;
            }

            while(!p_es_vacia(pila)){
                x = p_desapilar(pila);
                if (x->clave == num_de_m && bandera_2 == 0)
                {
                    bandera_2 = 1;
                    aux = -1;
                    printf("el numero ya existe en la pila, Ingrese un elemento distinto a los ingresados anteriormente.\n");
                }
                p_apilar(p_aux, x);
            }
            p_intercambiar(p_aux, pila);

            

            if (bandera_2 == 1){
                bandera = 1;
            }
            else if (bandera_2 == 0){
                bandera = 0;
            }
        }
        else
        {
            aux = 0;
            printf("intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
}

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


void cargar_datos_teclado_lista(int dato_i, Lista list_1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; ++i)
    {
        printf("ingrese el valor para la clave del %i tipoelemento:\n", 1 + i);
        validar_numeros(cad);
        numero = atoi(cad);
        x = te_crear(numero);
        l_agregar(list_1, x);
    }
}

void cargar_datos_teclado_pila(int dato_i, Pila p1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    for (i = 0; i < dato_i; ++i)
    {
        printf("ingrese el valor para la clave del %i tipoelemento de la pila: ", 1 + i);
        validar_numeros_no_rep_pila(cad, p1);
        numero = atoi(cad);
        x = te_crear(numero);
        p_apilar(p1, x);
    }
    printf("Finalizo la Carga\n");
    printf("\n\n");
}

void cargar_cola(Cola c,int cant){
    int elemento = 0;
    int iterador = 1;
    char cadena[100];
    TipoElemento x;
    while (cant>0){
        printf("ingrese el valor para la clave del %i tipoelemento de la cola: ", iterador);
        validar_numeros(cadena);
        elemento = atoi(cadena);
        x = te_crear(elemento);
        c_encolar(c,x);
        iterador++;
        elemento++;
        cant--;
    }
    printf("Finalizo la Carga\n");
    printf("\n\n");
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
    
    Pila pila = p_crear();
    Cola cola = c_crear();
    int cantidad_elementos = 1;
    cargar_cola(cola, cantidad_elementos);
    cargar_datos_teclado_pila(cantidad_elementos, pila);
    printf("------------------\n");
    p_mostrar(pila);
    c_mostrar(cola);
    printf("[REPETIDOS CON ORDINAL]\n");
    Lista repetidos = repetidos_con_ordinal(pila, cola);
    printf("\n-----------------\n");
    printf("La mayor complejidad la posee la funcion leer_entero() -> O(n^2)\n");
    printf("La complejidad de la funcion pedida en el ejercicio, repetidos_con_ordinal(), tiene complejidad de O(m * n)\n");
    printf("\n========= FIN DEL PROGRAMA =========\n");
    return 0;
}