/*Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en 
cada ventanilla. Un día, dos de los tres empleados que atienden las ventanillas no 
pueden asistir al trabajo, quedando uno solo para atender a las tres colas. Este 
empleado decide que, a medida que lleguen los clientes, atenderá por cierta cantidad 
de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas 
equitativamente. 
Se pide que implemente un algoritmo que modele esta situación y dé como resultado 
el orden en que fueron atendidos los clientes*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipo_elemento.h"
#include "colas.h"
#include "T_Element.c"
// #include "colas_arreglos_circular.c"
#include "colas_punteros.c"

int validar_numeros_positivos(char *m)
{
    int aux = 0;
    int bandera = 1,numero;
    fgets(m, 100, stdin);
    int largo = strlen(m) - 1;
    while (bandera == 1)
    {
        if (strcmp(m, "\n") == 0)
        {
            printf("Has ingresado un salto de linea.\n");
            aux = -1;
        }

        for (int j = 0; j < largo; j++)
        {

            if ((isdigit(m[j]) != 0))
            {
                aux++;
            }
        }

        if (aux == largo && aux<6)
        {
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero positivo o es mayor a 99.999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    numero=atoi(m);
    return numero;
}

void cargar_cola(Cola c,int cant){
    int cliente=1,minutos=0;
    char cadena[100];
    TipoElemento x;
    while (cant>0){
        printf("cuantos minutos necesita para ser atendido el cliente %i:\n",cliente);
        minutos=validar_numeros_positivos(cadena);
        x=te_crear(minutos);
        c_encolar(c,x);
        cliente++;
        cant--;
    }
    printf("Finalizo la Carga\n");
}

void trabajo_del_empleado(Cola c1, Cola c2, Cola c3,int minutos){
    TipoElemento x;
    int cliente_cola_1=-1,cliente_cola_2=-1,cliente_cola_3=-1;
    int salida_cola_1=0,salida_cola_2=0,salida_cola_3=0;
    while (!c_es_vacia(c1) || !c_es_vacia(c2)|| !c_es_vacia(c3)){

        //proceso de la cola 1
        if (!c_es_vacia(c1)&&cliente_cola_1<0){
            x=c_desencolar(c1);
            cliente_cola_1=x->clave;
        }
        if (cliente_cola_1>0){
            cliente_cola_1-=minutos;
        }
        if (cliente_cola_1<=0){
            salida_cola_1++;
            printf("cliente %i, Cola 1\n",salida_cola_1);
            x=c_desencolar(c1);
            cliente_cola_1=x->clave;
        }

        //proceso de la cola 2
        if (!c_es_vacia(c2)&&cliente_cola_2<0){
            x=c_desencolar(c2);
            cliente_cola_2=x->clave;
        }
        if (cliente_cola_2>0){
            cliente_cola_2-=minutos;
        }
        if (cliente_cola_2<=0 && !c_es_vacia(c2)){
            salida_cola_2++;
            printf("cliente %i, Cola 2\n",salida_cola_2);
            x=c_desencolar(c2);
            cliente_cola_2=x->clave;
        }else if (c_es_vacia(c2)){
            salida_cola_2++;
            printf("cliente %i, Cola 2\n",salida_cola_2);
        }
        

        //proceso de la cola 3
        if (!c_es_vacia(c3)&&cliente_cola_3<0){
            x=c_desencolar(c3);
            cliente_cola_3=x->clave;
        }
        if (cliente_cola_3>0){
            cliente_cola_3-=minutos;
        }
        if (cliente_cola_3<=0 && !c_es_vacia(c3)){
            salida_cola_3++;
            printf("cliente %i, Cola 3\n",salida_cola_3);
            x=c_desencolar(c3);
            cliente_cola_3=x->clave;
        }else if (c_es_vacia(c3)){
            salida_cola_3++;
            printf("cliente %i, Cola 2\n",salida_cola_3);
        }
    }
    printf("finalizo el trabajo\n");
}



int main(){
    printf("\nBinvenido al punto 7 del TP de colas.\n");
    Cola cola_1=c_crear(),cola_2=c_crear(),cola_3=c_crear();
    char cadena[100];
    int cant_elem_cola1,cant_elem_cola2,cant_elem_cola3,minutos_empleado;
    printf("¿cuantos clientes va a tener en la cola 1?\n ");
    cant_elem_cola1=validar_numeros_positivos(cadena);
    if (cant_elem_cola1>=101){
        printf("la cola es de 100 elementos, intente con un valor entre 0 o 100.\n");
    }
    else{
        printf("Cargar de la Cola 1\n");
        cargar_cola(cola_1,cant_elem_cola1);
    }
    printf("¿cuantos clientes va a tener en la cola 2?\n ");
    cant_elem_cola2=validar_numeros_positivos(cadena);
    if (cant_elem_cola2>=101){
        printf("la cola es de 100 elementos, intente con un valor entre 0 o 100.\n");
    }
    else{
        printf("Cargar de la Cola 2\n");
        cargar_cola(cola_2,cant_elem_cola2);
    }
    printf("¿cuantos clientes va a tener en la cola 3?\n ");
    cant_elem_cola3=validar_numeros_positivos(cadena);
    if (cant_elem_cola2>=101){
        printf("la cola es de 100 elementos, intente con un valor entre 0 o 100.\n");
    }
    else{
        printf("Cargar de la Cola 3\n");
        cargar_cola(cola_3,cant_elem_cola3);
    } 
    printf("¿Cuanto tiempo va a tener el empleado para atender a cada cliente?\n");
    minutos_empleado=validar_numeros_positivos(cadena);
    trabajo_del_empleado(cola_1,cola_2,cola_3,minutos_empleado);
    



    
    return 0;
}
