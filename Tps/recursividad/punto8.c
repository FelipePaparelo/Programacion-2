#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int validacion_tamano(char* tamano){
    int tamano_int;
    bool tamano_flag=false;
    while(tamano_flag==false){
        printf("Ingresa el tamano del conjunto: ");
        fgets(tamano, 100, stdin);
        int largo = strlen(tamano) - 1;
        if (largo == 0) {
            printf("No ingresaste ningun valor.\n");
            continue;
        }
        bool es_entero = true;
        for (int i = 0; i < largo; i++) {
            if (!isdigit(tamano[i])) {
                es_entero = false;
                break;
            }
        }
        if (es_entero) {
            tamano_int = atoi(tamano);
            if(tamano_int <=0 || tamano_int >= 25){
                printf("El tamaño del conjunto no puede ser o negativo o mayor o igual a 25 \n");
            }else{
                tamano_flag = true;
            }
        }
    }
    return tamano_int;
}



void cargar_conjunto(char* conjunto[], int tamano_int) {
    char cadena[100];
    for (int i = 0; i < tamano_int; i++) {
        strcpy(cadena, "");
        validar_conjunto_punto8(cadena);
        conjunto[i] = (char*) malloc(100 * sizeof(char));
        strcpy(conjunto[i], cadena);
    }
}

void verificar_vec(char* conjunto[], int tamano_int, int conjunto_int[]) {
    int objetivo_int;
    bool tamano_flag = false;
    for (int i = 0; i < tamano_int; ++i) {
        int largo = strlen(conjunto[i]);
        if (largo == 0) {
            printf("No ingresaste ningun valor.\n");
            continue;
        }
        bool es_entero = true;
        if (es_entero==true) {
            conjunto_int[i] = atoi(conjunto[i]); // eliminar * para asignar el valor
            tamano_flag = true;
        } else {
            printf("Dato ingresado incorrectamente.\n");
            return;
        }
    }
}




void  encontrar_subconjuntos(int *A, int tamanio, int *subconjunto, int indice, int sum, int objet_sum) {
    if (indice == tamanio) {
        // Si se llega al final del conjunto, se verifica si la suma del subconjunto es igual al objetivo
        if (sum == objet_sum) {
            // Se imprime el subconjunto
            printf("{");
            for (int i = 0; i < tamanio; i++) {
                if (subconjunto[i] == 1) {
                    printf("%d,", A[i]);
                }
            }
            printf("}\n");
        }
        return;
    }
    
    // Se incluye el elemento actual en el subconjunto y se sigue construyendo el subconjunto
    subconjunto[indice] = 1;
    encontrar_subconjuntos(A, tamanio, subconjunto, indice + 1, sum + A[indice], objet_sum);
    
    // Se excluye el elemento actual del subconjunto y se sigue construyendo el subconjunto
    subconjunto[indice] = 0;
    encontrar_subconjuntos(A, tamanio, subconjunto, indice + 1, sum, objet_sum);
}

int ejecutar_punto8() {
    int tamano_int, objetivo_int;
    char tamano[100], objetivo[100];
    char *conjunto[100]; // arreglo de punteros a caracteres
    int conjunto_int[100];
    int n_subconjuntos = 0;
    tamano_int = validacion_tamano(tamano);
    validar_objetivo_punto8(objetivo);
    objetivo_int = atoi(objetivo);
    cargar_conjunto(conjunto, tamano_int); // pasar el arreglo de punteros a caracteres
    verificar_vec(conjunto, tamano_int, conjunto_int);
    int tamanio = sizeof(conjunto_int) / sizeof(conjunto_int[0]);
    int *subconjunto = malloc(tamanio * sizeof(int));
    printf("\nlos subconjuntos son: \n");
    encontrar_subconjuntos(conjunto_int, tamano_int, subconjunto, 0, 0, objetivo_int);
    
    free(subconjunto);
    return 0;
}