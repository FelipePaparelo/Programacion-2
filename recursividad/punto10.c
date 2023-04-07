#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
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

    printf("BIENVENIDO AL PPROGRAMA DEL PUNTO 10 DEL TP DE RECURSIVIDA.\n\n");
    printf("INGRESE EL VALOR DEL NUMERO.\n");
    validar_punto10(numero_c);
    numero_i= atoi(numero_c);
    printf("INGRESE EL VALOR DE LA BOMBA.\n");
    validar_punto10(bomba_c);
    bomba_i= atoi(bomba_c);
    if ((bomba_i<0)||(numero_i<0)){
        printf("EL VALOR DE LA BOMBA O EL NUMERO ES NEGATIVO, INGRESE NUMERO POSITIVOS.\n\n");
    }
    else if (bomba_i>numero_i){
        printf("EL VALOR DE LA BOMBA ES MAYOR AL NUMERO, INGRESE UN VALOR PARA LA BOMBA MAS CHICO QUE EL NUMERO.\n");

    }
    else if(bomba_i<2 && bomba_i>=0){
        printf("EL VALOR DE LA BOMBA NO PUEDE SER NI 1 NI 0, INGRESE UN VALOR PARA LA BOMBA MAYOR A 2.\n");
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