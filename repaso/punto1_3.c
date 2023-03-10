#include <stdio.h>
#include "TP0_Repaso.h"
#include <math.h>


int main()
{
    enum Referencia punto = dondeEstaElPunto(1, 0, 1, 1, 0);
    switch (punto) {
        case EN_CIRCUNFERENCIA:
            printf("Esta en ciercunferencia\n");
            break;
        case EXTERNO:
            printf("Esta en fuera ciercunferencia\n");
            break;
        case INTERNO:
            printf("Esta en dentro ciercunferencia\n");
            break;
        default:
            printf("DATO INVALIDO\n");
    }
    struct Punto c,p;
    c.y=0;
    c.x=1;
    p.x=1;
    p.y=0;
    enum Referencia punto2 = dondeEstaElPuntoBis(c,1,p);
    switch (punto2) {
        case EN_CIRCUNFERENCIA:
            printf("Esta en ciercunferencia\n");
            break;
        case EXTERNO:
            printf("Esta en fuera ciercunferencia\n");
            break;
        case INTERNO:
            printf("Esta en dentro ciercunferencia\n");
            break;
        default:
            printf("DATO INVALIDO\n");
    }

    return 0;
}

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc,struct Punto p){
    float distancia = sqrt(pow(p.x - centroC.x, 2) + pow(p.y- centroC.y, 2));
    if (rc == distancia)
        return EN_CIRCUNFERENCIA;
    else if(distancia<rc)
        return INTERNO;
    else if(distancia>rc)
        return EXTERNO;
    else
        printf("Dato invalido\n");
}

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp)
{
    float distancia = sqrt(pow(xp - xc, 2) + pow(yp - yc, 2));
    if (rc == distancia)
        return EN_CIRCUNFERENCIA;
        else if(distancia<rc)
        return INTERNO;
    else if(distancia>rc)
        printf("Dato invalido\n");
        return EXTERNO;

}
