#include <stdio.h>
#include <string.h>
#include <stdbool.h>



void conversion(long n, short d, char *bufer_n, char *bufer_d){
    sprintf(bufer_n,"%lu",n);
    sprintf(bufer_d, "%i",d);
}

int main(){
    char cadena_n[21];
    char cadena_d[5];
    conversion(987,0, cadena_n, cadena_d);
    int longitud = strlen(cadena_n);
    bool encontrado=false;
    for (int i = 0; i <= longitud; ++i) {
        if ( cadena_n[i] == *cadena_d){
            encontrado=true;
            break;
        }
    }
    if (encontrado){
        printf("Encontrado\n");
    }
    else{
        printf("No encontrado\n");
    }
    return 0;
}




