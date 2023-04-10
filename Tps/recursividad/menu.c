#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "validacioness.c"
#include "punto1.c"
#include "punto2.c"
#include "punto3.c"
#include "punto4.c"
#include "punto5.c"
#include "punto6.c"
#include "punto7.c"
#include "punto8.c"
#include "punto9.c"
#include "punto10.c"
#define max_size 100

void esperarEnter() {
    int c;
    printf("Presione Enter para continuar...");
    while ((c = getchar()) != '\n' && c != EOF) { } // Lee caracteres hasta encontrar Enter
}


void menu(){
    printf("\nMenu de trabajo practico n°1 de recursividad\n\n");
    printf("1)_ Punto 1\n");
    printf("2)_ Punto 2\n");
    printf("3)_ Punto 3\n");
    printf("4)_ Punto 4\n");
    printf("5)_ Punto 5\n");
    printf("6)_ Punto 6\n");
    printf("7)_ Punto 7\n");
    printf("8)_ Punto 8\n");
    printf("9)_ Punto 9\n");
    printf("10)_ Punto 10\n");
    printf("Presione 0 si quiere finalizar el programa\n");
}

int main(){
    char p[max_size];
    int opcion;
    int flag = 1;
    int f = 1;
    menu();
    validar_numero_menu(p, &f);
    opcion = atoi(p);
    while (f == 1){
        switch (opcion)
        {
        case 0:
            f = 0;
            break;

        case 1:
            ejecutar_punto1();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 2:
            ejecutar_punto2();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 3:
            ejecutar_punto3();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 4:
            ejecutar_punto4();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 5:
            ejecutar_punto5();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 6:
            ejecutar_punto6();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 7:
            ejecutar_punto7();
            printf("\n");
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 8:
            ejecutar_punto8();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 9:
            ejecutar_punto9();
            printf("\n");
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        case 10:
            ejecutar_punto10();
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        default:
            printf("Opcion no valida\n");
            esperarEnter();
            menu();
            validar_numero_menu(p, &f);
            opcion = atoi(p);
            break;
        }
    }
    printf("Adios, vuelva pronto!");
}