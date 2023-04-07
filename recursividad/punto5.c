#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


char* punto5(char* cadena, int tamano, int* aux, char* cadena2, char punto, int i){
    char sup = '0';
    if (*aux < 3 && tamano >= 0)
    {
        sup = cadena[tamano-1];  
        cadena2[i] = sup;   
        *aux = *aux + 1;
        punto5(cadena, tamano -1, aux, cadena2, punto, i + 1);
    }
    if (*aux == 3)
    {
        sup = cadena[tamano-1];  
        cadena2[i] = punto;
        *aux = 0;

        punto5(cadena, tamano, aux, cadena2, punto,i+1);
    }
    
    return cadena2;
}

void eliminar_ceros_izquierda(char* str, int *c)
{
    if (*str == '0') {
        *c += 1;
        memmove(str, str + 1, strlen(str));
        eliminar_ceros_izquierda(str, c);
    }

}

char eliminar_punto(char *cadena) {
    size_t longitud = strlen(cadena);
    if (longitud > 0 && cadena[0] == '.') {
        memmove(cadena, cadena+1, longitud);
        cadena[longitud-1] = '\0';
    }
}


void ejecutar_punto5(){
    char cadena[100] = "";
    validar_punto5(cadena);
    char cadena2[100] = "";
    char punto = '.';
    int aux = 0;
    int i = 0;
    int c = 0;
    int tamano = strlen(cadena+1);
    eliminar_ceros_izquierda(cadena, &c);
    if(c == tamano){
        printf("la respuesta es: 0");
    }
    else{
        tamano = strlen(cadena+1);
        char* modificacion = punto5(cadena, tamano, &aux, cadena2, punto, i);
        char resultado = eliminar_punto(strrev(cadena2));
        printf("la respuesta es: %s\n", cadena2);
    }
}