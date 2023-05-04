#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "pilas.h"
#include <stdbool.h>
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
// #include "pilas_puntero.c"


void validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    int bandera_2, num_de_m;
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

void validar_numeros_positivos(char *m)
{
    int aux = 0;
    int bandera = 1;
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

        if (aux == largo)
        {
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero positivo, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
}

void cargar_datos_teclado(int dato_i, Pila p1)
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
        p_apilar(p1, x);
    }
}
void cargar_datos_teclado2(int dato_i, Pila p2)
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
        p_apilar(p2, x);
    }
}

// 2. Dada una pila cargada con valores al azar realizar los siguientes ejercicios:
// a. Buscar una clave y determinar si existe en la Pila (sin perder la pila).
// b. Colocar en una posición ordinal determinada, recibida por parámetro, un
// nuevo elemento (Insertar un elemento nuevo).
// c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la
// clave).
// d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la
// 2da con la 4ta.
// e. Duplicar el contenido de una pila.
// f. Contar los elementos de la pila. 
void p_intercambiar(Pila pAux, Pila p){
    TipoElemento te;

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }

}

// a. Buscar una clave y determinar si existe en la Pila (sin perder la pila)

Pila consigna_a(Pila pila_original, int elemento){
    TipoElemento x;
    int tamanio = p_longitud(pila_original);
    Pila pila_aux = p_crear();
    int contador = 0;
    for(int i = 0 ; i < tamanio ; i++)
    {
        x = p_desapilar(pila_original);
        printf("elemento %i\n", x->clave);
        if (x->clave == elemento){
            contador++;
        }
        p_apilar(pila_aux, x);
    }
    if (contador > 0){
        printf("Se ha encontrado el elemento a buscar!\n");
    }
    p_intercambiar(pila_aux, pila_original);
    return pila_original;
}

// b. Colocar en una posición ordinal determinada, recibida por parámetro, un
// nuevo elemento (Insertar un elemento nuevo).

Pila consigna_b (Pila pila_original, int posicion, int elemento){
    TipoElemento x;
    TipoElemento y = te_crear(elemento);
    int tamanio = p_longitud(pila_original);
    Pila pila_aux = p_crear();
    
    for(int i = 0 ; i < tamanio ; i++){
        x = p_desapilar(pila_original);
        p_apilar(pila_aux, x);
    }
    for(int i = 0 ; i < tamanio ; i++){
        x = p_desapilar(pila_aux);
        if (i + 1 ==  posicion){
            p_apilar(pila_original, y); 
        } 
        p_apilar(pila_original, x);
    }
    return pila_original;
}

// c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la
// (clave). 

Pila consigna_c(Pila pila_original, int elemento){
    bool eliminado = false;
    Pila pila_aux = p_crear();
    TipoElemento x;
    TipoElemento y = te_crear(elemento);
    while (!p_es_vacia(pila_original))
    {
        x = p_desapilar(pila_original);
        if((x->clave != elemento) || (eliminado == true)){
            p_apilar(pila_aux, x);
        }
        else if((x->clave != elemento) && (eliminado ==  false)){
            eliminado = true;
        }
    }
    p_intercambiar(pila_aux, pila_original);
    return pila_original;
    
}

// d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la
// 2da con la 4ta. 

Pila consigna_d(Pila pila_original, int pos1, int pos2){
    Pila p_aux = p_crear()
}

int main()
{
    int dato_i = 5;
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    cargar_datos_teclado(dato_i, p1);
    // cargar_datos_teclado2(dato_i, p2);
    printf("Lista cargada:\n");
    p_mostrar(p1);
    // ---------- consigna a -------------  
    // printf("Verificando si existe el elemento...\n");
    // p_mostrar(consigna_a(p1, 5));

    // ---------- consigna b -------------
    // p_mostrar(consigna_b(p1, 2, 100));

    // ---------- consigna c -------------
    // p_mostrar(consigna_c(p1,3));

    // ---------- consigna d -------------



}
    

