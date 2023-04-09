#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


void ejecutar_punto3(){
    char k[100];
    int numero = validar_punto3(k);
    int m = atoi(k);
    int resultado = fibonacci(m);
    printf("El %d-esimo numero de Fibonacci es %d\n", numero, resultado);
    
}