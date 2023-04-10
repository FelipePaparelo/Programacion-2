#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_c 1000

char* bombita(int n,int b,char c[]){
    int n2;
    char aux[3];
    if (n <= b) {
        sprintf(aux,"%i",n);
        strcat(c,aux);
        strcat(c,",");

    } else{
        n2=n-(n/b);
        n=n/b;
        bombita(n2,b,c);
        bombita(n,b,c);
    }

    return c;
}

void ejecutar_punto10(){
    char numero_c[100],bomba_c[100];
    int numero_i,bomba_i;
    validar_punto10(numero_c);
    numero_i= atoi(numero_c);
    validar_punto10(bomba_c);
    bomba_i= atoi(bomba_c);
    if ((bomba_i<0)||(numero_i<0)){
        printf("El valor de la bomba o el numero son negativos.\n\n");
        ejecutar_punto10();
    }
    else if (bomba_i>numero_i){
        printf("El valor de la bomba es mayor al numero, ingrese un valor para la bomba mas pequeño que el numero.\n");
        ejecutar_punto10();
    }
    else if(bomba_i<2 && bomba_i>=0){
        printf("El valor de la bomba no puede ser menor o igual a 2, reintentar.\n");
        ejecutar_punto10();
    }
    else{

       char *cadena= malloc(Max_c*(sizeof(char)));
        strcpy(cadena,"{");
        cadena=bombita(numero_i,bomba_i,cadena);
        strcat(cadena,"}");
        printf("%s\n",cadena);
        free(cadena);
    }
}