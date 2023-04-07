#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


float division(float n, float m, float *resultado, int *sobra){
    float resto;

    if(m == 0){
        return false;
    }
    if(n >= m){
        n -= m;
        *resultado += 1;
        division(n, m, resultado, sobra);
    }

    resto = n / m;
    *sobra = (int)resto;
    
    return *resultado + resto;
}






void ejecutar_punto4(){
    char input[100];
    float n = validar_punto4(input);
    float m = validar_punto4(input);
    float resultado = 0;
    int sobra = 0;
    float resultadox = division(n, m, &resultado, &sobra);
    printf("%.4f", resultadox - sobra);
}