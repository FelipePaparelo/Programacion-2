#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int producto(int n, int m, int *resultado) {
    if (n == 0 || m == 0){
        return 1;
    }
    if ( n >= 10000 || m >= 10000 || n <= -10000 || m <= -10000) {
        return 0;
    }
    else if (m < 0) {
        *resultado -= n;
        producto(n, m + 1, resultado);
    }
    else {
        *resultado += n;
        producto(n, m - 1, resultado);
    }
    return 1;
}



int ejecutar_punto2() {
    char num_c[100], mult_c[100];
    int num_i, mult_i;
    printf("Ingrese el multiplicando: \n");
    validar_punto2(num_c);
    num_i = atoi(num_c);
    printf("Ingrese el multiplicador: .\n");
    validar_punto2(mult_c);
    mult_i = atoi(mult_c);
    int resultado = 0;
    if (producto(num_i, mult_i, &resultado)) {
        printf("RESULTADO: %i\n", resultado);
    }
    else {
        printf("Ingresaste un numero fuera de rango o invalido.\ndebe ingresar valores menores a 10.000 tanto para el multiplicador como para el multiplicando\n");
        ejecutar_punto2();
    }
    return 0;
}
