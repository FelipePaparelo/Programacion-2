#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


int palindromo(char cadena[], int i, int cant_caracteres, int *contador){
    
    if (cadena[i] != cadena[cant_caracteres]){
        printf("\nfalse");
    }
    else if(cadena[i] == cadena[cant_caracteres] && cadena[cant_caracteres] != '\0' && cadena[i] == cadena[cant_caracteres] != '\0'){
        *contador += 1;
        palindromo(cadena, i + 1, cant_caracteres - 1, contador);
    }
}   

void ejecutar_punto1(){
    int contador = 0;
    int i = 0;
    char cadena[100];
    validacion_mayus_minus(cadena);
    int cant_caracteres = strlen(cadena);
    int comprobacion = cant_caracteres * 2;
    palindromo(cadena, i, cant_caracteres - 1, &contador);
    if (contador == cant_caracteres){
        printf("\ntrue");
    }
}