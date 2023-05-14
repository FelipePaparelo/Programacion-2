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

void l_mostrarListaConValor(Lista lista)
{
    
    printf("Contenido de la lista:\n");
    printf("{\n ");
    for (int i = 0; i < lista->cantidad; i++) {
        printf("clave: %d\n ", lista->valores[i]->clave);
        printf("valor: %s\n ", lista->valores[i]->valor);
    }
    printf("}");
    printf("\n");
}

// 6. Dada una pila y una cola generada con valores al azar retornar en una lista todos los
// valores comunes a ambas y en qué posición ordinal se encontró cada uno en su
// estructura. No se deben destruir las estructuras originales. No se deben perderse las
// estructuras originales. Determinar la complejidad algorítmica de la solución empleada.
// Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:5). 

// void punto_6(Pila p1, Cola c1, Lista l1){  
    // Cola c_aux = c_crear();
    // int elemento_pila, elemento_cola;
    // int vector_cola[100];
    // TipoElemento x;
    // TipoElemento y;
    // TipoElemento z;
    // int pos = 0;
    // char posiciones[200];
    // int tamanio_pila = p_longitud(p1);
    // int tamanio_cola = c_longitud(c1);
    // for(int i = 0 ; i < tamanio_cola ; i++){
    //     x = c_desencolar(c1);
    //     vector_cola[i] = x->clave;
    //     c_encolar(c_aux, x);
    // }
    // while(!p_es_vacia(p1)){
    //     x = p_desapilar(p1);

    //     for ( int i = 0 ; i < tamanio_cola ; i++){
    //         if(x->clave == vector_cola[i]){
    //             char str[10];
    //             if (pos > 0){
    //                 strcat(str, ", ");
    //             }
    //             sprintf(str, "%i", i+1);
    //             strcat(posiciones, str);
    //             pos++;
    //             // printf("dato que entra a valor: %s\n", posiciones);
    //             x->valor = posiciones;
    //             // printf("valor ciclo = %s\n", x->valor);
    //             l_agregar(l1, x);
    //         }
    //     }
    //     printf("valor  = %s\n", x->valor);
    //     posiciones[0] = '\0';
    //     printf("valor  = %s\n", x->valor);
    // }
    // l_mostrarListaConValor(l1);
// }

// void punto_6(Pila p1, Cola c1, Lista l1){  
//     Cola c_aux = c_crear();
//     int elemento_pila, elemento_cola;
//     int vector_cola[100];
//     TipoElemento x;
//     TipoElemento y;
//     TipoElemento z;
//     int pos = 0;
//     char posiciones[200] = "";
//     int tamanio_pila = p_longitud(p1);
//     int tamanio_cola = c_longitud(c1);
//     for(int i = 0 ; i < tamanio_cola ; i++){
//         x = c_desencolar(c1);
//         vector_cola[i] = x->clave;
//         c_encolar(c_aux, x);
//     }
//     while(!p_es_vacia(p1)){
//         x = p_desapilar(p1);

//         for ( int i = 0 ; i < tamanio_cola ; i++){
//             if(x->clave == vector_cola[i]){
//                 char str[10] = "";
//                 if (pos > 0){
//                     strcat(str, ", ");
//                 }
//                 sprintf(str, "%i", i+1);
//                 strcat(posiciones, str);
//                 x->valor = posiciones;
//                 l_agregar(l1, x);
//                 pos++;
//             }
//         }
//         x->valor = posiciones;
//         // posiciones[0] = '\0';
//     }
//     l_mostrarListaConValor(l1);
// }  


int main(){
    int cant_elementos = 5;
    Cola c1 = c_crear();
    Lista l1 = l_crear();
    Pila p1 = p_crear();
    cargar_datos_teclado_pila(cant_elementos, p1);
    cargar_cola(c1, cant_elementos);
    p_mostrar(p1);
    c_mostrar(c1);
    punto_6(p1, c1, l1);
    
}