#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define Maxcadena 50  




void convertirMayusculaRecursivo(char* str)
{
    if (*str) {
        *str = toupper(*str); 
        convertirMayusculaRecursivo(str + 1);  
    }
}

char * leerHondas(char cad[],char *p,int aux, int i, char last_signal){

    char ayuda;


    if ((i == aux)){

        if ((cad[i] == 'H')){
            strcat(p, "¯");
        }

        else if ((cad[i] == 'L')){
            strcat(p, "_");
        }
        return p;
    }

    else{

        
        ayuda = cad[i];


        if(ayuda != last_signal && last_signal != '\0'){
            printf("|");
        }
        if ((ayuda == 'H')){
            printf("¯");
        }

        else if ((ayuda == 'L')) {
            printf("_");
        }


        

        leerHondas(cad,p,aux, i+1, ayuda);
    }
}


int ejecutar_punto7(){
    int i = 0;
    char mochila = '\0';
    char cadena[Maxcadena];
    char* prub= malloc(sizeof(char));
    validar_punto7(cadena);
    convertirMayusculaRecursivo(cadena);
    strcpy(prub,"");
    int aux=strlen(cadena+1);
    prub=leerHondas(cadena,prub,aux, i, mochila);
}
