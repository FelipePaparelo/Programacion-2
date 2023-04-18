#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listas.h"
#include "tipo_elemento.h"
// #include "listas_de_areglos.c"
#include "list_point.c"
//#include "list_cursor.c"
#include "T_Element.c"

char validar_numeros(char* m)
{
    int aux = 0;
    int bandera = 1;
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

char validar_numeros_positivos(char* m)
{
    int aux = 0;
    int bandera = 1;
    fgets(m, 100,stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0){
            printf("Has ingresado un salto de linea.\n");
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
            printf("El dato que Ingresa no es un numero positivo, intente otra vez: ");
            fgets(m, 100,stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }

}

void cargar_datos_teclado(int dato_i,Lista list_1){
    TipoElemento x;
    char cad[100];
    int  i,numero;
    for (i = 0; i <dato_i ; i++) {
        printf("ingrese el valor para la clave del %i tipoelemento:\n",1+i);
        validar_numeros(cad);
        numero= atoi(cad);
        x=te_crear(numero);
        l_agregar(list_1,x);
    }

}
//. Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1. Se considera múltiplo si cada 
//elemento de L2 se divide en forma exacta por el valor L1 de la misma posición. Usar la 
//clave como campo de datos solamente

void resolver_punto3(Lista l1,Lista l2){
   bool bandera=true;
   int i;
   TipoElemento x1,x2;
   for (i=0; i<l_longitud(l1); i++){
        x1=l_recuperar(l1,i+1);
        x2=l_recuperar(l2,i+1);
        if (x2->clave%x1->clave==0 && bandera==true){
            bandera=true;
        }
        else{
            bandera=false;
        }
   }
   if (bandera==true){
        printf("LA LISTA 2 ES MULTIPLO DE LA LISTA 1\n");
    }
    else{
        printf("LA LISTA 2 NO ES MULTIPLO DE LA LISTA 1\n");
    }

}


int main(){
    char cad_l1[100];
    int num_l1;
    Lista l1,l2;
    printf("\nBIENENIDO AL PUNTO 3 DEL TP DE LISTAS\n");
    printf("CUANTOS ELEMENTOS VA INGRESAR EN LA LISTA 1:\n");
    validar_numeros_positivos(cad_l1);
    num_l1=atoi(cad_l1);
    printf("COMIENZO DE CARGA DE LA LISTA 1:\n");
    l1=l_crear();
    cargar_datos_teclado(num_l1,l1);
    printf("SE CARGO CORRECTAMENTE LA LISTA 1:\n");
    printf("COMIENZO DE CARGA DE LA LISTA 2:\n");
    l2=l_crear();
    cargar_datos_teclado(num_l1,l2);
    printf("SE CARGO CORRECTAMENTE LA LISTA 2:\n");
    resolver_punto3(l1,l2);

}