#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


void palindromo(char cadena[], int i, int cant_caracteres, int *contador){

    if (cadena[i] != cadena[cant_caracteres] || strlen(cadena)==0 ){
        printf("\nEl palindromo es: falso\n\n");
        *contador-=10;
    }
    else if(cadena[i] == cadena[cant_caracteres] && cadena[cant_caracteres] != '\0' && cadena[i] == cadena[cant_caracteres] != '\0'){
        *contador += 1;
        palindromo(cadena, i + 1, cant_caracteres - 1, contador);
    }
}

char* eliminarEspacios(char* str) {
    // Caso base: llegamos al final del string
    if (*str == '\0') {
        return strdup(""); // Devuelve una cadena vacía
    }
    // Caso recursivo 1: el primer carácter es un espacio en blanco
    if (*str == ' ') {
        return eliminarEspacios(str + 1); // Saltamos el primer carácter
    }
    // Caso recursivo 2: el primer carácter no es un espacio en blanco
    char* nuevaStr = eliminarEspacios(str + 1); // Llamada recursiva
    char* resultado;
    if (*str == '\0') {
        resultado = strdup(""); // Si llegamos al final del string, devuelve una cadena vacía
    } else {
        resultado = malloc(strlen(nuevaStr) + 2); // Reserva memoria para la nueva cadena
        resultado[0] = *str; // Copia el primer carácter
        strcpy(resultado + 1, nuevaStr); // Copia el resto de la cadena
    }
    free(nuevaStr); // Libera la memoria de la cadena temporal
    return resultado;
}

void ejecutar_punto1(){
    int contador = 0;
    int i = 0;
    char cadena[100];
    validacion_mayus_minus(cadena);
    int cant_caracteres = strlen(cadena);
    int comprobacion = cant_caracteres * 2;
    eliminarEspacios(cadena);
    palindromo(cadena, i, cant_caracteres - 1, &contador);
    if (contador == cant_caracteres){
        printf("\nEl palindromo es: Verdadero\n\n");
    }
}