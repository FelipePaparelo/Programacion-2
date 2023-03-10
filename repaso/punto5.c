#include <stdio.h>
#include "TP0_Repaso.h"



int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){
    int aux2=0;
    int piso_mas_habitantes;
    for (int i = 1; i < CANT_PISOS ; ++i) {
        int aux = 0; // Reiniciar la variable aux antes de sumar los habitantes de cada piso
        for (int j = 1; j < CANT_DEPARTAMENTOS ; ++j) {
            aux += edificio[i][j];
        }
        if(aux > aux2){
            aux2 = aux;
            piso_mas_habitantes = i;
        }
    }

    printf("pisoConMasHabitantes(edificio) => %i\n",piso_mas_habitantes);
    return 0;
}
int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){
    int viviendas_vacias = 0;
    for (int i = 0; i < CANT_PISOS ; ++i) {
        int aux = 0; // Reiniciar la variable aux antes de sumar los habitantes de cada piso
        for (int j = 0; j < CANT_DEPARTAMENTOS ; ++j) {
            if(edificio[i][j] == 0){
                viviendas_vacias+=1;
                }
            }
        }
    printf("cantidadDeViviendasVacias(edificio) =>%i\n",viviendas_vacias );
    return 0;
}
float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){
    float suma=0;
    for (int i = 0; i < CANT_PISOS ; ++i) {
        for (int j = 0; j < CANT_DEPARTAMENTOS ; ++j) {
            suma += edificio[i][j];
        }
    }
   float resultado=suma/(CANT_PISOS*CANT_DEPARTAMENTOS);
    printf("promedioHabitantesPorVivienda(edificio) =>%.2f",resultado);
    return resultado;
}
Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){
    int aux2=0;
    int vivienda_mas_habitantes;
    int vivienda_mas_habitantes2;
    for (int i = 0; i < CANT_PISOS ; ++i) {
        int aux = 0; // Reiniciar la variable aux antes de sumar los habitantes de cada piso
        for (int j = 0; j < CANT_DEPARTAMENTOS ; ++j) {
            aux = edificio[i][j];
            if(aux > aux2){
                aux2 = aux;
                vivienda_mas_habitantes =i+1;
                vivienda_mas_habitantes2=j;

            }
        }

    }
    switch (vivienda_mas_habitantes2) {
        case 0:
            printf("pisoConMasHabitantes(edificio) => %i-A\n",vivienda_mas_habitantes);
            break;
        case 1:
            printf("pisoConMasHabitantes(edificio) => %i-B\n",vivienda_mas_habitantes);
            break;
        case 2:
            printf("pisoConMasHabitantes(edificio) => %i-C\n",vivienda_mas_habitantes);
            break;
        case 3:
            printf("pisoConMasHabitantes(edificio) => %i-D\n",vivienda_mas_habitantes);
            break;
        case 4:
            printf("pisoConMasHabitantes(edificio) => %i-D\n",vivienda_mas_habitantes);
            break;
        default:
            break;
    }
}



int main(){
    int edificio[CANT_PISOS][CANT_DEPARTAMENTOS] = {
            {3, 5, 2, 1, 0},
            {2, 4, 3, 0, 2},
            {1, 0, 1, 2, 1},
            {0, 1, 0, 0, 0},
            {1, 3, 2, 1, 1},
            {2, 2, 0, 1, 3},
            {1, 0, 0, 2, 1},
            {0, 0, 1, 1, 1}
    };

    pisoConMasHabitantes(edificio);
    cantidadDeViviendasVacias(edificio);
    viviendaConMasHabitantes(edificio);
    promedioHabitantesPorVivienda(edificio);
    return 0;
}