#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol-binario.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "Nodo_funciones.c"
#include "I_arboles_binarios.c"
#include <ctype.h>

bool sonEquivalentes(ArbolBinario A, ArbolBinario B,NodoArbol NAA,NodoArbol NAB,bool equivalente){
    if((!a_es_rama_nula(NAA) && !a_es_rama_nula(NAB))){
        TipoElemento elemento1 = n_recuperar(NAA);
        TipoElemento elemento2 = n_recuperar(NAB);
        if((elemento1->clave) != (elemento2->clave)){
            equivalente = false;
        }
        if(equivalente){
            equivalente = sonEquivalentes(A,B,n_hijoizquierdo(NAA),n_hijoizquierdo(NAB),equivalente);
            equivalente = sonEquivalentes(A,B,n_hijoderecho(NAA),n_hijoderecho(NAB),equivalente);
        }

    }
    if((a_es_rama_nula(NAA) && !a_es_rama_nula(NAB)) || (a_es_rama_nula(NAB) && !a_es_rama_nula(NAA))){ //verifica que las estructuras sean iguales
        equivalente =  false;
    }
    return equivalente;

};

bool validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    bool numero;
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

            if ((j == 0) && (m[j] == '-')&& (isdigit(m[j+1]) != 0))
            {
                aux++;
            }

        }

        if (aux == largo && aux<6)
        {
            bandera = 0;
        }
        else if(m[0] == '.' && m[1]== '\n'){
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero o es mayor a 99.999 o menor a -9999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    if (m[0] == '.'){
        numero=false;
    }
    else{
        numero=true;
    }
    return numero;
}

void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo){
    TipoElemento x;
    NodoArbol n1;
    char cadena[100];
    bool numero;
    int numero_i;

    if(!a_es_lleno(a)){
        printf("Ingrese un numero o '.' para nulo: ");
        numero=validar_numeros(cadena);
        if (numero){

            numero_i=atoi(cadena);
            x = te_crear(numero_i);

            if(hijo == -1){ n1 = a_conectar_hi(a, n, x); }
            else if(hijo == 1){ n1 = a_conectar_hd(a, n, x); }
            else n1 = a_establecer_raiz(a, x);

            cargar_subArbol(a, n1, -1);
            cargar_subArbol(a, n1, 1);
        }
    }
}

void cargar_arbol(ArbolBinario a){
    cargar_subArbol(a, NULL, 0);
}

int main() {
    ArbolBinario arbolA = a_crear();
    printf("[ARBOL A - INGRESO]\n");
    cargar_arbol(arbolA);
    ArbolBinario arbolB = a_crear();
    printf("[ARBOL B - INGRESO]\n");
    cargar_arbol(arbolB);
    NodoArbol raizA = a_raiz(arbolA);
    NodoArbol raizB = a_raiz(arbolB);
    if (sonEquivalentes(arbolA, arbolB,raizA, raizB,true)){
        printf("Los arboles ingresados son equivalentes\n");
    } else {
        printf("Los arboles ingresados NO son equivalentes\n");
    }
    return 0;
}

// bool verificar_entrada(int *valor){
//     char entrada[10];
//     bool resultado = true;
//     bool negativo = false;
//     int i = 0;
//     *valor=0;
//     printf("Ingrese un numero o '.' para nulo: ");
//     scanf("%s", entrada);
//     if (entrada[0] == '.'){
//         resultado = false;
//     }else{
//         if(entrada[0] == '-'){
//             negativo = true;
//             i++;
//         }
//         for (i; entrada[i] != '\0'; i++) {
//             if (!isdigit(entrada[i])){
//                 printf("El valor ingresado no es un entero, intente de nuevo\n");
//                 verificar_entrada(valor);
//                 break;
//             }else if((entrada[i]>='0')&&(entrada[i]<='9')){
//                 *valor = *valor * 10 + (entrada[i] - 48);
//             }
//         }
//         if(negativo){ *valor = *valor * (-1); }
//     }

//     return resultado;
// }

// void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo){
//     TipoElemento x;
//     NodoArbol n1;
//     int valor_a_ingresar;
//     bool entero;
//     if(!a_es_lleno(a)){
//         entero = verificar_entrada(&valor_a_ingresar);
//         if(entero){
//             x = te_crear(valor_a_ingresar);

//             if(hijo == -1){ n1 = a_conectar_hi(a, n, x); }
//             else if(hijo == 1){ n1 = a_conectar_hd(a, n, x); }
//             else n1 = a_establecer_raiz(a, x);

//             cargar_subArbol(a, n1, -1);
//             cargar_subArbol(a, n1, 1);
//         }
//     }
// }

// void cargar_arbol(ArbolBinario a){
//     cargar_subArbol(a, NULL, 0);
// }
