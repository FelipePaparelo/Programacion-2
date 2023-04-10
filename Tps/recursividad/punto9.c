#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>



int punto9(int n, int divisible){
    int aux;
    if(n < 70 && (n % 7 == 0)){
        return 1;
    }
    if (n >= 70){
        aux = n % 10;
        aux *= 2;
        n = n / 10;
        n -= aux;
        punto9(n, divisible);
    }

}


int ejecutar_punto9(){
    int divisible = 7;
    int num_r;
    char num_c[100];
    int resultado = 0;
    validar_punto9(num_c);
    num_r= atoi(num_c);

    if(num_r<0){
        printf("El numero tiene que ser positivo");
    }
    else {
        resultado = punto9(num_r, divisible);
        if (resultado == 1) {
            printf("el numero %i es divisible por %i", num_r, divisible);
        } else {
            printf("el numero %i no es divisible por %i", num_r, divisible);
        }
    }
}