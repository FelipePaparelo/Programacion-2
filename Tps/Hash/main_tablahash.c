#include <stdio.h>
#include <stdlib.h>
#include "tabla_hash.h"

static const int TAMANIO_MAXIMO = 20;
static const int NRO_PRIMO = 19;

char* int_to_char(int num);


// Funcion Hash apuntada por la tabla
int hashFunctionNroPrimo(int a) {
    return (a % NRO_PRIMO);
}

// Funcion Hash apuntada por la tabla
int hashFunctionPorPlegamiento(int a) {
    printf("Clave:  %d ", a);
    if (a < TAMANIO_MAXIMO) {
        return a;
    }
    else {
        char *S = int_to_char(a);
        printf("Clave string: %s \n", S);
        char S1[10];
        strncpy(S1,S,1);
        printf("Clave string1: %s \n", S1);
      //  S := VarToStr(X.Clave);
      // S1 := S.Substring(0, (Length(S) Div 2));
      // S2 := S.Substring((Length(S) Div 2), Length(S));
      // P := StrToInt(S1) + StrToInt(S2);
      // if P > NSize then Begin
      //  P := (P Mod NSize);
      // end;
    }
    return (a % NRO_PRIMO);
}

// Funcion Hash apuntada por la tabla
int hashFunctionPorMitadCuadrado(int a) {
    return (a % NRO_PRIMO);
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------
//--- MAIN PRINCIPAL ---
//-----------------------------------------------------------------
//-----------------------------------------------------------------
int main()
{
    TablaHash T;
    TipoElemento X;
    int i=0;

    T = th_crear(TAMANIO_MAXIMO, &hashFunctionNroPrimo);

    srand(time(NULL)); //es como el randomize en delphi

    for(i=1;i<TAMANIO_MAXIMO;i++){
        X = te_crear((rand() % 100) + 1);
        th_insertar(T, X);
    }

    th_mostrar(T);

    printf("\n");

    //th_mostrar_solo_ocupados(T);
    //th_mostrar_solo_ocupados(T);

    return 0;
}

char* int_to_char(int num)
{
    int i = log10(num) + 1;
    char *s = (char*)calloc(i+1, sizeof(char));

    for(i--; num != 0; i--)
    {
        s[i] = (num % 10) + '0';
        num/=10;
    }

    return s;
}
