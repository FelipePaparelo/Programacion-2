#include <stdio.h>
#include "TP0_Repaso.h"

struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[]){
    /*CREAMOS UN VECTOR DEL LARGO DE LA ESTRUCTURA JUGADORES, QUE ES DONDE VAMOS A IR GUARDANDO LA LISTA ORDENADA
     * TAMBIÉN CREAMOS UNA VARIABLE AUXILIAR QUE NOS VA A SERVIR PARA HACER UN ORDENAMIENTO BURBUJA
     * */
    struct Jugador vectorJugadores[CANT_JUGADORES];
    struct Jugador aux;
    /*VAMOS GUARDANDO LOS VALORES EN EL VECTOR*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        vectorJugadores[i] = equipo[i];
    }

    /*APLICAMOS EL ORDENAMIENTO BURBUJA*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        for (int j = 0; j < CANT_JUGADORES - 1 ; ++j) {
            if(vectorJugadores[j].partidosJugados < vectorJugadores[j+1].partidosJugados ){
                aux=vectorJugadores[j];
                vectorJugadores[j]=vectorJugadores[j+1];
                vectorJugadores[j+1]=aux;
            }

        }
    }
    /*IMPRIMIMOS EL VECTOR YA ORDENADO*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        printf("Nombre: %s, Partidos jugados: %d\n", vectorJugadores[i].nombre, vectorJugadores[i].partidosJugados);
    }
    return vectorJugadores;
}

struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[]){
    /*CREAMOS UN VECTOR DEL LARGO DE LA ESTRUCTURA JUGADORES, QUE ES DONDE VAMOS A IR GUARDANDO LA LISTA ORDENADA
 * TAMBIEN CREAMOS UNA VARIABLE AUXILIAR QUE NOS VA A SERVIR PARA HAER UN ORDENAMIENTO BURBUJA
 * */
    struct Jugador vectorJugadores[CANT_JUGADORES];
    struct Jugador aux;
    /*VAMOS GUARDANDO LOS VALORES EN EL VECTOR*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        vectorJugadores[i] = equipo[i];
    }

    /*APLICAMOS EL ORDENAMIENTO BURBUJA*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        for (int j = 0; j < CANT_JUGADORES - 1 ; ++j) {
            if(vectorJugadores[j].edad > vectorJugadores[j+1].edad ){
                aux=vectorJugadores[j];
                vectorJugadores[j]=vectorJugadores[j+1];
                vectorJugadores[j+1]=aux;
            }
        }
    }
    /*IMPRIMIMOS EL VECTOR YA ORDENADO*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        printf("Nombre: %s, edad: %i\n", vectorJugadores[i].nombre, vectorJugadores[i].edad);
    }
    return vectorJugadores;
}

float promedioDePartidosJugados(struct Jugador equipo[]) {
    float aux2;
    struct Jugador vectorJugadores[CANT_JUGADORES];
    /*VAMOS GUARDANDO LOS VALORES EN EL VECTOR*/
    for (int i = 0; i < CANT_JUGADORES; ++i) {
        vectorJugadores[i] = equipo[i];
    }
    for (int i = 0; i < CANT_JUGADORES ; ++i) {
        aux2+= vectorJugadores[i].partidosJugados ;
    }
    float resultado_promedio=aux2/CANT_JUGADORES;
    printf("El promedio de partidos jugados es: %.1f\n",resultado_promedio);
    return resultado_promedio;
}


int main(){
    struct Jugador equipo[] = {
            {"Messi", 34, 800},
            {"Ronaldo", 37, 900},
            {"Neymar Jr.", 29, 500},
            {"Mbappe", 22, 200},
            {"Lewandowski", 33, 700},
            {"Salah", 29, 400},
            {"De Bruyne", 30, 600},
            {"van Dijk", 30, 400},
            {"Ramos", 35, 650},
            {"Neuer", 35, 800},
            {"Davies", 20, 100}
    };
    printf("##########Ordenados por partidos #######\n");
    jugadoresOrdenadosPorCantDePartidos(equipo);
    printf("##########Ordenados por edad #######\n");
    jugadoresOrdenadosPorEdad(equipo);
    printf("##########Promedio de partidos #######\n");
    promedioDePartidosJugados(equipo);
    return 0;
}