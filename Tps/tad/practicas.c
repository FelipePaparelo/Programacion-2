#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "listas_de_areglos.c"
// #include "list_point.c"
// #include "list_cursor.c"
#include "T_Element.c"
#include <math.h>


// 3. Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1. Se considera múltiplo si cada
// elemento de L2 se divide en forma exacta por el valor L1 de la misma posición. Usar la
// clave como campo de datos solamente.
// Ejemplo: si L1 = (2, 5, 7, 3) y L2 = (8, 20, 28, 12) entonces L2 es múltiplo por L1 porque
// cada posición de L2 se divide por el valor de L1 de la misma posición en forma exacta
// (sin decimales). Si el resultado de la división retorna el mismo valor para cada posición
// se dice que “L2” es múltiplo de “L1” por un “escalar”. Para este caso “4” es el escalar
// de L1. El algoritmo debe contemplar esta situación. 

void cargar_lista(Lista lista, Lista lista2, int tamanio1, int tamanio2){
    int x;
    TipoElemento b;
    for(int i = 0 ; i <  tamanio1 ; i++){
        printf("Ingrese el %i° elemento de la lista 1: ", i+1);
        scanf("%i", &x);
        b = te_crear(x);
        l_agregar(lista, b);
    }
    printf("\n");
    // for(int i = 0 ; i < tamanio2 ; i++){
    //     printf("Ingrese el %i° elemento de la lista 2: ", i+1);
    //     scanf("%i", &x);
    //     b = te_crear(x);
    //     l_agregar(lista2, b);
    // }
}

void multiplo(Lista lista, Lista lista2, int tamanio){
    int contador = 0;
    TipoElemento x;
    TipoElemento y;
    int valor_l1;
    int valor_l2;
    for(int i = 0 ; i < tamanio ; i++){
        x = l_recuperar(lista, i+1);
        y = l_recuperar(lista2, i+1);
        if (y->clave % x->clave == 0){
            contador += 1;
        }
    }
    if (contador == tamanio){
        printf("\nL2 es multiplo de L1");
    }
    else{
        printf("\nL2 no es multiplo de L1");
    }
}

// Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1L2. Por lo tanto
// puede suceder que: L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparación es por
// la clave, posición a posición, donde si L1 tiene más cantidad de claves mayores que L2 se
// considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 será igual a L2.
// Determinar la complejidad algorítmica de la solución empleada. 



void comparador(Lista lista1, Lista lista2, int tamanio){
    TipoElemento x;
    TipoElemento y;
    int mayor = 0;
    int menor = 0;
    int igual = 0;
    for(int i = 0; i < tamanio; i++){
        x = l_recuperar(lista1, i+1);
        y = l_recuperar(lista2, i+1);
        if (x->clave > y->clave){
            mayor+=1;
        }
        else if (x->clave < y->clave){
            menor+=1;
        }
        else if (x->clave == y->clave){
            igual+=1;
        }
    }
    if (mayor > menor){
        printf("L1 > L2\n");
    }
    else if(mayor < menor){
        printf("L1 < L2\n");
    }
    else if (mayor == menor){
        printf("L1 = L2\n");
    }
}

// 6. Generar un algoritmo que determine si una lista es sublista de otra. Se considera que es
// una sublista si todos los valores de la segunda se encuentran dentro de la primera sin
// importar el orden o posición de cada elemento. La comparación es solo por la clave. Se
// pide además determinar la complejidad algorítmica de la solución. 

void sublista(Lista lista1, Lista lista2, int tamanio1, int tamanio2){
    TipoElemento x;
    TipoElemento y;
    int contador = 0;
    for(int i = 0 ; i < tamanio1 ; i++){
        x = l_recuperar(lista1, i+1);
        for(int j = 0; j < tamanio2 ; j++){
            y = l_recuperar(lista2, j+1);
            if (y->clave == x->clave){
                contador+=1;
            }
        }
    }
    if (contador == tamanio2){
        printf("Una lista es sublista de otra.\n");
    }
    // else if (contador == tamanio1){
    //     printf("Una lista es sublista de otra.\n");
    // }
    else{
        printf("No son sublistas.");
    }
}



//se asume una lista cargada con una secuencia de nros de 1 a N (1,2,3,4,5,n). luego algunos elementos fueron
//sustraidos. se pide retornar cuales son los elementos sustraidos de la secuencia.

int sustraidos(Lista lista1, int var, int vec[100], int i, int papa, int acum, Iterador ite){
    if (!hay_siguiente(ite)){
        return 1;
    }
    else{
        TipoElemento x = l_recuperar(lista1, var+1);
        printf("clave = %i\n", x->clave);
        printf("i = %i\n", i);
        if(x->clave > i){         //{1,3,4,7,8}
            vec[papa] = i;
            sustraidos(lista1, var, vec, i+1, papa+1, acum+1, ite);
        }
        siguiente(ite);
        sustraidos(lista1, var+1, vec, i+1, papa,acum+1, ite);

    }
}


void mostrar_v(int vec[100]){
    for(int i = 0 ; i < 17 ; i ++){
        printf("Elemento sustraido: %i\n", vec[i]);
    }
}

// realizar una funcion que devuelva las claves mayores de una lista y meterlas en una lista nueva.

Lista mayores(Lista lista, int tamano, Iterador ite){
    TipoElemento x = l_recuperar(lista, 1);  // o(1)
    int mayor = x->clave;   // o(1)
    Lista ln = l_crear();   //o(1)

    while (hay_siguiente(ite))  // o(n)
    {
        x = siguiente(ite);    // o(1)
        if(mayor < x->clave){   // o(1)
            mayor = x->clave;   // o(1)
            ln = l_crear();     // o(1)
            l_agregar(ln, x);   // o(1)
        }
        else if(mayor == x->clave){
            l_agregar(ln, x);
        }

    }
    return ln; // o(1)
    
}

// O(1) + O(1) + o(1) + O(N) + o(1).4 = O(1) + O(N) = O(n)


// 1 + 3n + n^2.(3)+n = 3n^2 + 4n + 1 = n^2


// FILE fp = fopen(nombre, r+b)
// fseek(asda()*legajo, seek_set)
// fread
//usuario.nota = promedio
// fseek(asda()*legajo, seek_cur-1)
//fwrite()
//fclose


// realizaruna funcion q transforme una lista en la que se almacena un numero binario en un numero decimal.





int binario(Lista lista, Iterador ite, int* acum, int i){
    int aux = 2;
    if(!hay_siguiente(ite)){
        return *acum;
    }
    else{
        TipoElemento x = siguiente(ite);
        if (x->clave == 1){
            aux = pow(aux, l_longitud(lista)-i);
            *acum += aux;
            binario(lista, ite, acum, i+1);
        }
        binario(lista, ite, acum, i+1);
    }
}

// 1    0    1 
// 2^2  2^1   2^0







int main(){
    Lista lista = l_crear(lista);
    Lista lista2 = l_crear(lista2);
    cargar_lista(lista, lista2, 5, 3);
    int tamanio = l_longitud(lista);
    printf("\nLista 1: ");
    l_mostrarLista(lista);
    // printf("\nLista 2: ");
    // l_mostrarLista(lista2);
    // multiplo(lista, lista2, 5);
    // comparador(lista,lista2,5);
    // sublista(lista, lista2, 4, 3);
    int i = 1;
    int var = 0;
    int papa = 0;
    int salida = 0;
    Iterador ite;
    ite = iterador(lista);
    int *vec = (int*) calloc(100, sizeof(int));
    int n = 8;
    // sustraidos(lista, var, vec, i, papa, salida, ite);
    // mostrar_v(vec);
    // l_mostrarLista(mayores(lista, 5, ite));
    binario(lista, ite, &salida,i); 
    printf("%i", salida);
}
