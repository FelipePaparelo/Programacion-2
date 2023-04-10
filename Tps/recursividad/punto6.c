
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define max_c 1000

char* punto6(int n,char *cade,char aux[]){

        if (n==1){

        }else {
            strcpy(aux, "");
            strcat(aux, "(-.");
            strcat(aux, cade);
            strcpy(cade, aux);
            strcat(cade, ".-)");
            punto6(n - 1, cade, aux);
        }
    return cade;
}


void ejecutar_punto6(){
    int numero_r;
    char c[100];
    validar_punto6(c);
    numero_r= atoi(c);
    if ((numero_r!=0)&&(numero_r<=166)&&(numero_r>0)) {
        char *prueb = malloc(sizeof(char)*max_c);
        char auxiliar[max_c];
        strcpy(prueb, "(-.-)");
        punto6(numero_r, prueb, auxiliar);
        printf("%s\n", prueb);
        printf("Este es el grupo de chinos que asiste en el nivel %d.\n",numero_r);
        free(prueb);
    }
    else if((numero_r>166)||(numero_r<0)){
        printf("el numero que ingreso es muy grande para el programa, pruebe uno mas pequeño que 167 y mayor o igual que 0.\n");
        ejecutar_punto6();
    }
    else{
        char *prueb = malloc(sizeof(char)*max_c);
        char auxiliar[max_c];
        strcpy(prueb, "");
        printf("%s\n", prueb);
        printf("este es el grupo de chinos que asiste en el nivel %d.\n",numero_r);
        free(prueb);
    }
}