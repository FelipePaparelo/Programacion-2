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

int validar_numeros_positivos(char *m)
{
    int aux = 0;
    int bandera = 1,numero;
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
        }

        if (aux == largo && aux<6)
        {
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero positivo o es mayor a 99.999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    numero=atoi(m);
    return numero;
}

void p_intercambiar(Pila pAux, Pila p)
{
    TipoElemento te = te_crear(0);

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }
}

bool estaEnCola(Cola cola,int elemento, int tamano){
    int longitudC = tamano;
    TipoElemento X;
    bool existe = false;
    for(int i=0;i<longitudC;i++){
        X = (c_desencolar(cola));
        if(X->clave == elemento){
            existe = true;
        }
        c_encolar(cola,X);
    }
    return existe;
}

void validar_numeros_no_rep_pila(char *m, Pila p1, int tamano)
{
    int aux = 0;
    int bandera = 1, p, num_de_m, bandera_2;
    TipoElemento x;
    Pila p_aux = p_crear();
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
            num_de_m = atoi(m);

            if (num_de_m > 100000000 || num_de_m < -10000000)
            {
                bandera_2 = 1;
                aux = -1;
                printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            }
            else{
                bandera_2 = 0;
            }


    
            for (p = 0; p < tamano; p++)
            {
                if(!p_es_vacia(p1)){
                    x = p_desapilar(p1);
                    if (x->clave == num_de_m && bandera_2 == 0)
                    {
                        printf("el numero ya fue ingresado\n");
                        bandera_2 = 1;
                        aux = -1;
                    }
                    p_apilar(p_aux, x);
                }
            }
            p_intercambiar(p_aux, p1);

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

void validar_numeros_no_rep_cola(char *m, Cola c1, int tamano)
{
    bool verificacion;
    int aux = 0;
    int bandera = 1, p, num_de_m, bandera_2;
    TipoElemento x;
    TipoElemento y;
    Cola c_aux = c_crear();
    Pila p_aux = p_crear();
    int cantidad = tamano;
    int cantidad2 = tamano;
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
            num_de_m = atoi(m);

            if (num_de_m > 100000000 || num_de_m < -10000000)
            {
                bandera_2 = 1;
                aux = -1;
                printf("ingrese un numero mayor a -10.000.000 o menor a 100.000.000\n");
            }
            else{
                bandera_2 = 0;
            } 

            while(!c_es_vacia(c1)){
                
                x = c_desencolar(c1);
                if (x->clave == num_de_m && bandera_2 == 0)
                {
                    printf("el numero ya fue ingresado\n");
                    bandera_2 = 1;
                    aux = -1;
                }
                c_encolar(c_aux, x);
            }

            while (!c_es_vacia(c_aux))
            {
                x = c_desencolar(c_aux);
                c_encolar(c1, x);
            }
            

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


void cargar_datos_teclado_pila(int tamano, Pila p1)
{
    TipoElemento x;
    char cad[100];
    int i, numero;
    
    for (i = 0; i < tamano; ++i)
    {
        printf("ingrese el valor para la clave del %i tipoelemento de la pila: ", 1 + i);
        validar_numeros_no_rep_pila(cad, p1, tamano);
        numero = atoi(cad);
        x = te_crear(numero);
        p_apilar(p1, x);
    }
    printf("Finalizo la Carga\n");
    printf("\n\n");
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


void cargar_cola(Cola c,int cant){
    int elemento = 0;
    int iterador = 1;
    char cadena[100];
    int tamano = cant;
    // Cola cola_aux = copiar_cola(c);
    TipoElemento x;
    while (cant>0){
        printf("ingrese el valor para la clave del %i tipoelemento de la cola: ", iterador);
        validar_numeros_no_rep_cola(cadena, c, tamano);
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
    printf("Ingreso de datos de la cola\n");
    printf("Tamaño de la cola. ");
    int tamano = leer_entero();
    while (tamano > TAM_MAXIMO || tamano <= 0) {
        printf("Tamaño invalido. Intentelo de nuevo. ");
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
    printf("Ingreso de datos a la pila\n");
    printf("Tamaño de la pila. ");
    int tamano = leer_entero();
    while (tamano > TAM_MAXIMO || tamano <= 0) {
        printf("Tamaño invalido. Intentelo de nuevo. ");
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
 
void mostrar_punto_6(Lista lista) { // C.A.: O(n)

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


Lista punto6(Pila pila, Cola cola) { // C.A.: O(m * n), donde "m" es el tamaño de la pila y "n" es el tamaño de la cola
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
    mostrar_punto_6(lista);
    return lista;
}


int main() {
    printf("----------Punto 6----------\n");
    char s;
    char m;
    char p;
    int n;
    Pila pila = p_crear();
    Cola cola = c_crear();
    int a = 1;
    int tamano_pila;
    int tamano_cola;
    Lista repetidos;
    printf("¿Como desea ingresar los datos?\nOpcion 1: Ingresar los datos por teclado\nOpcion 2: Ingresar elementos al azar.\nOpcion 3: finaliza el programa.\n");
    n = validar_numeros_positivos(&s);
    while (a == 1)
    {
        switch (n) {
        case 1:
            printf("\nIngrese la cantidad de elementos de la pila:\n");
            tamano_pila = validar_numeros_positivos(&p);
            while(tamano_pila > 100){
                printf("Ingrese una cantidad de elementos menor a 100: ");
                tamano_pila = validar_numeros_positivos(&p);
            }
            cargar_datos_teclado_pila(tamano_pila, pila);
            printf("\nIngrese la cantidad de elementos de la cola: \n");
            tamano_cola = validar_numeros_positivos(&p);
            while(tamano_cola > 100){
                printf("Ingrese una cantidad de elementos menor a 100: ");
                tamano_cola = validar_numeros_positivos(&p);
            }
            cargar_cola(cola, tamano_cola);
            p_mostrar(pila);
            c_mostrar(cola);
            repetidos = punto6(pila, cola);
            printf("\n-----------------\n");
            printf("La complejidad de la funcion pedida en el ejercicio (repetidos_con_ordinal()) tiene complejidad de O(m * n)\n");
            a = 0;
            break;
            
        case 2:
            pila = llenar_pila_al_azar();
            cola = llenar_cola_al_azar();
            int cantidad_elementos = 1;
            p_mostrar(pila);
            c_mostrar(cola);
            printf("[REPETIDOS CON ORDINAL]\n");
            repetidos = punto6(pila, cola);
            printf("\n-----------------\n");
            printf("La complejidad de la funcion pedida en el ejercicio (punto6) tiene complejidad de O(m * n)\n");
            a = 0;
            break;
        case 3:
            a = 0;
            break;

        default:
            printf("\n-----Valor invalido, ingrese 1 para ingresar datos por teclado o ingrese 2 para que la cola y la pila se generen con elementos al azar-----\n");
            n = validar_numeros_positivos(&s);
        }
    }
}

