#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

char validar_numero_menu(char* m, int *f)
{
    int aux = 0;
    int bandera = 1;
    bool flag2 = false;
    printf("\nIngresa una opcion del 1 al 10: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
        printf("Has ingresado un salto de línea.\n");
        aux = -1;
        } 

        for(int j = 0; j<largo;j++){
            
            if((isdigit(m[j]) != 0)){
                    aux++;
            }
        }
        
        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("Seleccione una opcion nuevamente: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
        if (m == 0){
            *f = 0;
        }
    }
}

void validacion_mayus_minus(char palabra[]) {
    printf("Ingrese un palindromo a comprobar: ");
    fgets(palabra, 100, stdin);
    if (strcmp(palabra, "\n") == 0){
        printf("Has ingresado un salto de linea.\n");
        validacion_mayus_minus(palabra);
    }
    for (int i = 0; i < strlen(palabra); i++) {
        palabra[i] = tolower(palabra[i]);
        if (palabra[strlen(palabra)-1] == '\n'){
            palabra[strlen(palabra)-1] = '\0'; 
            
        }
    }
    if(isspace(palabra[0])){
        printf("Ingrese una cadena de caracteres valida para comprobar si es palindromo.\n");
        validacion_mayus_minus(palabra);
    }
}


char validar_punto2(char* m)
{
    int aux = 0;
    int bandera = 1;
    bool flag2 = false;
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("El dato que Ingresa no es un numero entero, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}

int validar_punto3(char* input) {
    int num;
    bool es_valido = false;
    while (!es_valido) {
        printf("Ingresa un numero entero a comprobar de la sucesion de Fibonacci entre 0 y 40: ");
        fgets(input, 100, stdin);
        int largo = strlen(input) - 1;
        if (largo == 0) {
            printf("No ingresaste ningun valor.\n");
            continue;
        }
        bool es_entero = true;
        for (int i = 0; i < largo; i++) {
            if (!isdigit(input[i])) {
                es_entero = false;
                printf("No ingresaste un valor valido.\n");
                break;
            }
        }
        if (es_entero) {
            num = atoi(input);
            if (num >= 0 && num <= 40) {
                es_valido = true;
        } else {
            printf("No ingresaste un valor valido.\n");
            }
        } 
    } 
    return num;
}



int validar_punto4(char* input) {
    int num;
    bool es_valido = false;
    while (!es_valido) {
        printf("Ingresa un numero entero : ");
        fgets(input, 100, stdin);
        int largo = strlen(input) - 1;
        if (largo == 0) {
            printf("No ingresaste ningun valor.\n");
            continue;
        }
        bool es_entero = true;
        for (int i = 0; i < largo; i++) {
            if (!isdigit(input[i])) {
                es_entero = false;
                break;
            }
        }
        if (es_entero) {
            num = atoi(input);
            if (num <= 30000){
                es_valido = true;    
            }
            else{
                printf("Uno de los numeros ingresados es mayor que 30.000, por favor, ingrese un numero mas pequeño.\n");
                validar_punto4(input);
            }
            es_valido = true;
        } else {
            printf("No ingresaste un numero entero valido.\n");
        }
    }
    return num;
}

char validar_punto5(char* m)
{
    int aux = 0;
    int bandera = 1;
    printf("Ingrése numero para insertar los puntos cada miles: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }

        else{
            aux = 0;
            printf(" el dato que Ingresa no es un numero entero, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}

char validar_punto6(char* m)
{
    int aux = 0;
    int bandera = 1;
    printf("Ingresa un nivel: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("el dato que Ingresa no es valido, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}

char validar_punto7(char* m)
{
    int aux = 0;
    int bandera = 1;
    char ayuda;
    printf("Ingresa un l o h para la onda digital: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){
           if(m[j] == 'H' || m[j] == 'h'){
            aux++;
           }
           if(m[j] == 'L' || m[j] == 'l'){
            aux++;
           }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("uno de los caracteres ingresados no es valido, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    if(strlen(m) > 50){
        printf("Ingrese una cantidad maxima de h y l de 50 caracteres.\n");
        validar_punto7(m);
    }

}

char validar_conjunto_punto8(char* m)
{
    int aux = 0;
    int bandera = 1;
    bool flag2 = false;
    printf("Ingresa un numero entero para cargar el vector: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("el dato que Ingresa no es un numero entero, reingrese un numero entero para cargar el vector: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}

char validar_objetivo_punto8 (char* m)
{
    int aux = 0;
    int bandera = 1;
    bool flag2 = false;
    printf("Ingresa un numero entero para definir el objetivo a alcanzar: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("el dato que ingresa no es un numero entero, reingrese el objetivo a alcanzar otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}



char validar_punto9(char* m)
{
    int aux = 0;
    int bandera = 1;
    printf("Ingresa un numero entero para verificar si es divisible por 7: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf(" el dato que Ingresa no es un numero entero, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}



char validar_punto10(char* m)
{
    int aux = 0;
    int bandera = 1;
    printf("Ingresa un numero entero: ");
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for(int j = 0; j<largo;j++){

            if ((j==0)&&(m[j]=='-')){
                aux++;
            }

            if((isdigit(m[j]) != 0)){
                aux++;
            }
        }

        if (aux == largo){
            bandera = 0;
        }
        else{
            aux = 0;
            printf("el dato que Ingresa no es un numero entero, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }


}



