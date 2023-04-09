#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int producto(int n,int m,int *resultado){
    if(n == 0 || m == 0){
        return 0;
    }
    else if(m<0){
        *resultado -= n;
        producto(n,m + 1, resultado);
    }
    else if(m>0){
        *resultado += n;
        producto(n,m - 1, resultado);
    }
}


int ejecutar_punto2 (){
    char num_c[100],mult_c[100];
    int num_i ;
    int mult_i ;
    printf("BIENVENIDO AL PUNTO 2 DEL TP DE RECURSIVIDAD\n\n");
    printf("INGRESE EL NUMERO QUE VA A MULTIPLICAR.\n");
    validar_punto2(num_c);
    num_i= atoi(num_c);
    printf("INGRESE POR CUANTO LO QUIERE MULTIPLICAR.\n");
    validar_punto2(mult_c);
    mult_i= atoi(mult_c);
    int resultado = 0;
    producto(num_i, mult_i, &resultado);
    printf("%i", resultado);
}