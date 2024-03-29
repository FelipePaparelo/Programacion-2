#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbol-binario.h"
#include "tipo_elemento.h"
#include "nodo.h"
#include "Nodo_funciones.c"
#include "I_arboles_binarios.c"
#include "listas_de_arreglos.c"
//#include "listas_cursores.c"
//#include "listas_punteros.c"

void strtrim(char *cadena) {
    char *comienzoDeCadena = cadena;
    char *finalDeCadena = cadena + strlen(cadena) - 1;
    while (isspace(*comienzoDeCadena)) {
        comienzoDeCadena++;
    }
    while (isspace(*finalDeCadena) && finalDeCadena >= comienzoDeCadena) {
        finalDeCadena--;
    }
    *(finalDeCadena + 1) = '\0';
    memmove(cadena, comienzoDeCadena,   finalDeCadena - comienzoDeCadena + 2);
}

int leer_entero() {
    char entradaLeerEntero[100];
    long numero;
    char *finptr;
    bool valido = 0;

    while (!valido) {
        printf("Ingrese un numero entero: ");
        fgets(entradaLeerEntero, sizeof(entradaLeerEntero), stdin);
        entradaLeerEntero[strlen(entradaLeerEntero)-1] = '\0';
        strtrim(entradaLeerEntero);
        errno = 0;
        numero = strtol(entradaLeerEntero, &finptr, 10);
        if (errno != 0 || *finptr != '\0') {
            printf("Entrada invalida. Intentelo de nuevo.\n");
        } else {
            valido = 1;
        }
    }
    return (int) numero;
}

bool validar_numeros(char *m)
{
    int aux = 0;
    int bandera = 1;
    bool numero;
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

            if ((j == 0) && (m[j] == '-')&& (isdigit(m[j+1]) != 0))
            {
                aux++;
            }

        }

        if (aux == largo && aux<6)
        {
            bandera = 0;
        }
        else if(m[0] == '.' && m[1]== '\n'){
            bandera = 0;
        }
        else
        {
            aux = 0;
            printf("El dato que Ingresa no es un numero o es mayor a 99.999 o menor a -9999, intente otra vez: ");
            fgets(m, 100, stdin);
            fflush(stdin);
            largo = strlen(m) - 1;
        }
    }
    if (m[0] == '.'){
        numero=false;
    }
    else{
        numero=true;
    }
    return numero;
}

bool esBinarioTransformado(NodoArbol n){
    return (n_hijoderecho(n) == NULL);
}

void cargar_subArbol(ArbolBinario a, NodoArbol n, int hijo){
    TipoElemento x;
    NodoArbol n1;
    char cadena[100];
    bool numero;
    int numero_i;

    if(!a_es_lleno(a)){
        printf("Ingrese un numero o '.' para nulo: ");
        numero=validar_numeros(cadena);
        if (numero){

            numero_i=atoi(cadena);
            x = te_crear(numero_i);

            if(hijo == -1){ n1 = a_conectar_hi(a, n, x); }
            else if(hijo == 1){ n1 = a_conectar_hd(a, n, x); }
            else n1 = a_establecer_raiz(a, x);

            cargar_subArbol(a, n1, -1);
            cargar_subArbol(a, n1, 1);
        }
    }
}

void cargar_arbol(ArbolBinario a){
    cargar_subArbol(a, NULL, 0);
}

bool esHojaNArio(NodoArbol n){
    return (n_hijoizquierdo(n) == NULL);
}

int alturaArbolNArio(NodoArbol nodo, int contador, int altura) {
    if(!(nodo == NULL)) {
        if(contador > altura) {
            altura = contador;
        }
        altura = alturaArbolNArio(n_hijoizquierdo(nodo), contador + 1, altura);
        altura = alturaArbolNArio(n_hijoderecho(nodo), contador, altura);
    }
    return altura;
}

int determinarNivelNodo(int claveNodoABuscar,NodoArbol nodoArbol,int contador, int nivelNodo){
    if(nivelNodo == 0 && nodoArbol != NULL){
        TipoElemento elemento1 = n_recuperar(nodoArbol);
        if(elemento1->clave == claveNodoABuscar){
            nivelNodo = contador;
        }
        nivelNodo = determinarNivelNodo(claveNodoABuscar,n_hijoizquierdo(nodoArbol),contador+1,nivelNodo);
        nivelNodo = determinarNivelNodo(claveNodoABuscar,n_hijoderecho(nodoArbol),contador,nivelNodo);
    }
    return nivelNodo;
};

//ESTA ES MIA NO ES DEL EJERCICIO
int nivelPrimerHoja(NodoArbol n,int nivel,int cont){
    if((n != NULL) && (nivel == 0)){
        if(esHojaNArio(n)){
            nivel = cont;
        }
        nivel = nivelPrimerHoja(n_hijoizquierdo(n),nivel,cont+1);
    }
    return nivel;
}

bool hojasEnMismaAltura(NodoArbol n,int nivel,int contador,bool resultado){
    if((n!=NULL) && (resultado)){
        if(esHojaNArio(n)){
            if(nivel != contador){
                resultado = false;
            }
        }
        resultado = hojasEnMismaAltura(n_hijoizquierdo(n),nivel,contador+1,resultado);
        resultado = hojasEnMismaAltura(n_hijoderecho(n),nivel,contador,resultado);
    }
    return resultado;
}

bool es_nodo_interno(NodoArbol n, ArbolBinario a) {
    return ((n_hijoizquierdo(n) != NULL) && (a_raiz(a) != n));
}

void nodos_internos_arbol_recursivo(NodoArbol n, Lista lista, ArbolBinario a) {
    if (n != NULL) {
        if (es_nodo_interno(n, a)) {
            l_agregar(lista, n_recuperar(n));
        }
        nodos_internos_arbol_recursivo(n_hijoizquierdo(n), lista, a);
        nodos_internos_arbol_recursivo(n_hijoderecho(n), lista, a);
    }
}

Lista nodos_internos_arbol(ArbolBinario a) {
    Lista lista = l_crear();
    nodos_internos_arbol_recursivo(a_raiz(a), lista, a);
    return lista;
}

int main() {
    printf("----------------------- PUNTO A -----------------------\n");
    printf("Determinar la altura del mismo.");
    ArbolBinario arbolTransformado = a_crear();
    printf("[ARBOL TRANSFORMADO 1 - INGRESO]\n");
    cargar_arbol(arbolTransformado);
    if(esBinarioTransformado(a_raiz(arbolTransformado))){
        if (!a_es_vacio(arbolTransformado)) {
        int altura = alturaArbolNArio(a_raiz(arbolTransformado),1,1);
        printf("La altura del arbol es de %d.\n", altura);
        } else{
        printf("El arbol no tiene altura ya que esta vacio.\n");
        }

        printf("---------------------- PUNTO B -----------------------\n");
        printf("Determinar el nivel de un nodo, ingrese la claver del nodo a buscar.\n");
        int valorIngresado = leer_entero();
        int resultado = determinarNivelNodo(valorIngresado,a_raiz(arbolTransformado),1,0);
        if( resultado != 0){
            printf("Nivel %d. \n",resultado);
        }else{printf("\nNo se encontro\n");}

        printf("---------------------- PUNTO C -----------------------\n");
        printf("Listar todos los nodos internos (solo las claves).\n");
        Lista nodosInternos = nodos_internos_arbol(arbolTransformado);
        if (l_es_vacia(nodosInternos)) {
            printf("El arbol no tiene nodos internos.\n");
        } else {
            printf("[NODOS INTERNOS] \n");
            l_mostrarLista(nodosInternos);
        }

        printf("---------------------- PUNTO D -----------------------\n");
        printf("Determinar si todas las hojas estan al mismo nivel\n");
        bool mismoNivel =true;
        bool resultadoBooleano = hojasEnMismaAltura(a_raiz(arbolTransformado),nivelPrimerHoja(a_raiz(arbolTransformado),0,1),1,mismoNivel);
        if(resultadoBooleano){
            printf("mismo nivel");
        }else{printf("distinto nivel");}
    }else{printf("No es arbol binario transformado,no se realizaran las operaciones");}
    return 0;
}
