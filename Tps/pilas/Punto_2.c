#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_arreglos.c"
//#include "pilas_puntero.c"

void p_intercambiar(Pila pAux, Pila p);
void cargar_azar(Pila p, int longitud, int maximo);
void cargar_pila(pila);
bool verificarEntradaInt(int* valor);

bool buscar_clave(Pila p, int clave);
Pila insertar_elemento(Pila p, TipoElemento te, int posicion);
Pila eliminar_clave(Pila p, int clave);
Pila intercambiar_valores(Pila p, int posicion1, int posicion2);
Pila duplicar_pila(Pila p);
int cantidad_elementos(Pila p);


//------------------------------------------------------
// MAIN
//------------------------------------------------------
int main(){
    int clave, longitud, maximo, posicion, valor_auxiliar, clave_a_eliminar;
    int posicion1, posicion2;
    bool valor_en_pila = false;
    Pila pila = p_crear();
    Pila pila_clave_agregada = p_crear();
    Pila pila_clave_eliminada = p_crear();
    Pila pila_claves_intercambiadas = p_crear();
    Pila pila_clonada = p_crear();
    TipoElemento tipo_elemento = te_crear(0);


    printf("-------------IMPORTANTE-------------\n");
    printf("Todas las funciones del ejercicio se van a realizar sobre la pila original creada al azar o cargada por el usuario\n");
    printf("------------------------------------\n");
    //------------------------------------------------------
    // Se pide los valores de la longitud y del máximo valor
    // que va a contener la Pila
    //------------------------------------------------------
    printf("Ingresar la longitud deseada para la pila : ");
    if(!verificarEntradaInt(&longitud)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else if (longitud <= 0)
    {
        printf("El valor de la longitud debe ser Positivo...");
        return 0;
    }
    
    printf("La Pila se genera entre 1 y ¿qué valor? Ingrese dicho valor máximo : ");
    if(!verificarEntradaInt(&maximo)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else if (maximo <= 1)
    {
        printf("El valor del máximo debe ser MAYOR que 1...");
        return 0;
    }

    //cargar_pila(pila);
    //p_mostrar(pila);

    //------------------------------------------------------
    // Se carga la Pila con valores al azar y se muestra
    // por pantalla la Pila cargada
    //------------------------------------------------------
    cargar_azar(pila, longitud, maximo);

    if(p_es_vacia(pila) != true){ 
        printf("Pila creada con éxito\n"); 
        p_mostrar(pila);
    }else{
        printf("La Pila no ha sido creada\n");
    }

    //------------------------------------------------------
    // Se pide que ingrese la clave a buscar 
    // dentro de la Pila
    //------------------------------------------------------
    printf("Ingrese la clave a buscar en la Pila : ");
    if(!verificarEntradaInt(&clave)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }

    //------------------------------------------------------
    // Verificamos si la clave dada está dentro de la Pila
    //------------------------------------------------------
    valor_en_pila = buscar_clave(pila, clave);
    if(valor_en_pila){ printf("La clave '%d' está dentro de la Pila\n", clave); }
    else{ printf("La clave '%d' NO existe dentro de la Pila\n", clave); }
    // Mostramos que no se perdió la Pila original
    p_mostrar(pila);

    printf("\n");
    printf("---------------------------------------------------------");
    printf("\n");

    //------------------------------------------------------
    // Pedimos el valor y la posición para agregar en la Pila
    //------------------------------------------------------
    printf("Ingrese el valor que desea agregar a la Pila : ");
    if(!verificarEntradaInt(&valor_auxiliar)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else{
        tipo_elemento->clave = valor_auxiliar;
    }

    printf("Ingrese la posición en la que desea agregar el valor dado : ");
    if(!verificarEntradaInt(&posicion)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else if (posicion <= 0)
    {
        printf("El valor de la posición debe ser Positivo...");
        return 0;
    }

    //------------------------------------------------------
    // Insertamos el valor en la posicion dada
    // Y mostramos la pila por pantalla
    //------------------------------------------------------
    pila_clave_agregada = insertar_elemento(pila, tipo_elemento, posicion);
    printf("Pila original --> ");
    p_mostrar(pila);
    printf("Pila con clave insertada --> ");
    p_mostrar(pila_clave_agregada);

    printf("\n");
    printf("---------------------------------------------------------");
    printf("\n");


    //------------------------------------------------------
    // Pedimos el valor a eliminar de la Pila
    //------------------------------------------------------
    printf("Ingrese el valor que desea eliminar de la Pila : ");
    if(!verificarEntradaInt(&clave_a_eliminar)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }

    pila_clave_eliminada = eliminar_clave(pila, clave_a_eliminar); 
    printf("Pila original --> "); 
    p_mostrar(pila);
    printf("Pila con clave eliminada --> "); 
    p_mostrar(pila_clave_eliminada);
    
    printf("\n");
    printf("---------------------------------------------------------");
    printf("\n");

    //------------------------------------------------------
    // Se pide las posiciones que se desean intercambiar
    //------------------------------------------------------
    printf("Ingresar la 1° posición a intercambiar : ");
    if(!verificarEntradaInt(&posicion1)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else if (posicion1 <= 0 || posicion1 > longitud)
    {
        printf("El valor de la posición debe ser Positivo y Menor a la longitud '%d'...", longitud);
        return 0;
    }

    printf("Ingresar la 2° posición a intercambiar : ");
    if(!verificarEntradaInt(&posicion2)){
        printf("El valor ingresado no es un Entero...");
        return 0;
    }else if (posicion2 <= 0 || posicion2 > longitud)
    {
        printf("El valor de la posición debe ser Positivo y Menor a la longitud '%d'...", longitud);
        return 0;
    }

    pila_claves_intercambiadas = intercambiar_valores(pila, posicion1, posicion2);
    printf("Pila original --> ");
    p_mostrar(pila);
    printf("Pila con valores intercambiados --> ");
    p_mostrar(pila_claves_intercambiadas);
    

    printf("\n");
    printf("---------------------------------------------------------");
    printf("\n");

    //------------------------------------------------------
    // Duplicamos la Pila
    //------------------------------------------------------
    pila_clonada = duplicar_pila(pila);
    printf("La pila original : ");
    p_mostrar(pila);

    printf("La pila clonada : ");
    p_mostrar(pila_clonada);

    printf("\n");
    printf("---------------------------------------------------------");
    printf("\n");

    //------------------------------------------------------
    // Mostramos la cantidad de elementos en la Pila
    //------------------------------------------------------
    printf("La cantidad de Elementos en la Pila es : %d", cantidad_elementos(pila));

    printf("\n");
    printf("---------------------------------------------------------");
    printf("\n");

    return 0;
}

//------------------------------------------------------
// Procedimiento para intercambiar los elementos 
// de una pila
//------------------------------------------------------
void p_intercambiar(Pila pAux, Pila p){
    TipoElemento te = te_crear(0);

    while (p_es_vacia(pAux) != true)
    {
        te = p_desapilar(pAux);
        p_apilar(p, te);
    }
}

//------------------------------------------------------
// Procedimiento para cargar la Pila con claves al azar 
//------------------------------------------------------
void cargar_azar(Pila p, int longitud, int maximo){
    srand(time(NULL));
    
    for (int i = 0; i < longitud; i++)
    {
        TipoElemento valor = te_crear(0);
        
        valor->clave = (rand() % maximo) + 1;
        p_apilar(p, valor);
    }  
}

//---------------------------------------------------------------------
// Procedimiento para cargar pila de forma manual por el usuario
//---------------------------------------------------------------------
void cargar_pila(Pila pila){
    int valor = 0;
    bool agregar = true;

    while(agregar){
        printf("Ingrese el valor del dato para guardar en la Pila o cualquier letra para finalizar la carga : ");
        if(!verificarEntradaInt(&valor)){ agregar = false; }
        else{
            TipoElemento te = te_crear(valor);
            p_apilar(pila, te);
        }
    }

    // Limpiamos el buffer de entrada
    while (getchar() != '\n');
}

//------------------------------------------------------
// Función para verificar que la entrada sea Entera 
//------------------------------------------------------
bool verificarEntradaInt(int* valor){
    if(scanf("%d", valor) != 1)return false;
    else return true;
}


//------------------------------------------------------
// Punto 2a. Buscar una clave y determinar si 
// existe en la Pila (sin perder la pila).
//------------------------------------------------------
bool buscar_clave(Pila p, int clave){
    bool resultado = false;
    Pila pila_aux = p_crear();
    TipoElemento te = te_crear(0);

    while (p_es_vacia(p) != true)
    {
        te = p_desapilar(p);
        if(te->clave == clave){ resultado = true; }
        p_apilar(pila_aux, te);
    }
    
    p_intercambiar(pila_aux, p);
    return resultado;
}


//------------------------------------------------------
// Punto 2b. Colocar en una posición ordinal determinada, 
// recibida por parámetro, un nuevo elemento 
// (Insertar un elemento nuevo).
//------------------------------------------------------
Pila insertar_elemento(Pila p, TipoElemento te, int posicion){
    Pila pila_aux = p_crear();
    Pila pila_resultado = p_crear();
    TipoElemento auxiliar = te_crear(0);
    int indice = 1;

    p_intercambiar(p, pila_aux);
    if(cantidad_elementos(pila_aux) < posicion){
        while (p_es_vacia(pila_aux) != true)
        {
            auxiliar = p_desapilar(pila_aux);
            p_apilar(p, auxiliar);
            p_apilar(pila_resultado, auxiliar);
        }
        p_apilar(pila_resultado, te);        
    }else{
        while(p_es_vacia(pila_aux) != true){
            if(indice == posicion){
                p_apilar(pila_resultado, te);
            }
            auxiliar = p_desapilar(pila_aux);
            p_apilar(p, auxiliar);
            p_apilar(pila_resultado, auxiliar);
            indice++;
        }
    }

    return pila_resultado;
}


//------------------------------------------------------
// Punto 2c. Eliminar de una pila un elemento dado 
// (primera ocurrencia encontrada por la clave).
//------------------------------------------------------
Pila eliminar_clave(Pila p, int clave){
    bool eliminado = false;
    Pila pila_aux = p_crear();
    Pila pila_aux_resultado = p_crear();
    Pila pila_resultado = p_crear();
    TipoElemento te = te_crear(0);

    while (p_es_vacia(p) != true)
    {
        te = p_desapilar(p);
        if(eliminado == true || te->clave != clave){
            p_apilar(pila_aux_resultado, te);
        }else if (te->clave == clave && eliminado == false)
        { 
            eliminado = true; 
        }
        p_apilar(pila_aux, te);
    }
    
    p_intercambiar(pila_aux, p);
    p_intercambiar(pila_aux_resultado, pila_resultado);
    return pila_resultado;
}


//------------------------------------------------------
// Punto 2d. Intercambiar los valores de 2 posiciones 
// ordinales de la pila, por ejemplo la 2da con la 4ta.
//------------------------------------------------------
Pila intercambiar_valores(Pila p, int posicion1, int posicion2){
    int indice = cantidad_elementos(p);
    int insertados = 0;
    Pila pila_aux = p_crear();
    Pila pila_resultado = p_crear();
    TipoElemento te = te_crear(0);
    TipoElemento te_pos1 = te_crear(0);
    TipoElemento te_pos2 = te_crear(0);

    if(posicion1 > indice || posicion2 > indice || posicion1 == posicion2){ return pila_resultado; }

    while(p_es_vacia(p) != true)
    {
        if(posicion1 == indice){
            te_pos2 = p_desapilar(p);
        }else if (posicion2 == indice){
            te_pos1 = p_desapilar(p);
        }else{
            te = p_desapilar(p);
            p_apilar(pila_aux, te);
        }
        
        indice--;
    }

    indice = 1;
    while (p_es_vacia(pila_aux) != true || insertados != 2)
    {
        if(indice == posicion1){
            p_apilar(pila_resultado, te_pos1);
            p_apilar(p, te_pos2);
            insertados++;
        }else if (indice == posicion2){
            p_apilar(pila_resultado, te_pos2);
            p_apilar(p, te_pos1);
            insertados++;
        }else{
            te = p_desapilar(pila_aux);
            p_apilar(p, te);
            p_apilar(pila_resultado, te);
        }

        indice++;
    }

    return pila_resultado;
}



//------------------------------------------------------
// Punto 2e. Duplicar el contenido de una pila.
//------------------------------------------------------
Pila duplicar_pila(Pila p){
    Pila pila_resultado = p_crear();
    Pila pila_aux = p_crear();
    Pila pila_original = p_crear();
    TipoElemento te = te_crear(0);

    while (p_es_vacia(p) != true)
    {
        te = p_desapilar(p);
        p_apilar(pila_aux, te);
        p_apilar(pila_original, te);
    }

    p_intercambiar(pila_aux, pila_resultado);
    p_intercambiar(pila_original, p);

    return pila_resultado;
}  

//------------------------------------------------------
// Punto 2f. Contar los elementos de la pila.
//------------------------------------------------------
int cantidad_elementos(Pila p){
    int cantidad = 0;
    Pila pila_aux = p_crear();
    TipoElemento te = te_crear(0);
    
    while(p_es_vacia(p) != true)
    {
        cantidad++;
        te = p_desapilar(p);
        p_apilar(pila_aux, te);
    }

    p_intercambiar(pila_aux, p);
    return cantidad;
}