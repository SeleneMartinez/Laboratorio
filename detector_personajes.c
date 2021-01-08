#include "detector_personajes.h"


void imprimir(char mensaje[]);
void pedirAnioNacimiento(int *anio);
void pedirSabor(char *sabor);
void pedirTalle(int *talle);
void pedirColor(char *color);
void pedirAltura(int *altura);
void calcularPuntajePorColor(int *puntaje, char color);
void calcularPuntajePorSabor(int *puntaje, char sabor);
void calcularPuntajePorAnio( int *puntaje, int anio);
int calcularMultiplicador(int talle);
void calcularPuntaje(int *puntaje, int talle, int altura, int anio, char color, char sabor);
duo_t obtenerDuo(int puntaje);
void obtenerPersonaje(int puntos, int altura, char *personae);
bool estaElElemento(const char vector[], char elemento, int tamanio);

/* pre: recibe un vector de chars*/
/*post: imprime el vector como cadena por pantalla*/
void imprimir(char mensaje[]){
printf("%s",mensaje);
}
/*pre: recibe una referencia a un entero*/
 /*post: pide por consola un numero entre 1988 y 2008 y actualiza el valor del entero referenciado*/ 
void pedirAnioNacimiento(int *anio){

    while( *anio > ANIO_MAX || *anio< ANIO_MIN){
        printf("Ingrese su anio de nacimiento (Entre %d y %d) \n --->: ", ANIO_MIN, ANIO_MAX);
        scanf(" %d", anio);
        
    }
}
/* pre: recibe una referencia a un caracter*/
/* post: pide por consola que ingrese S, D o A y actualiza el valor del caracter referenciado*/

void pedirSabor( char *sabor){

    while(!estaElElemento(SABORES, *sabor, CANTIDAD_SABORES)){
        printf("Elija un sabor \n %c -> salado \n %c -> amargo \n %c -> dulce \n --->: ", SALADO, AMARGO, DULCE);
        scanf(" %c", sabor);
    
    }
}

/* pre: recibe una referencia a un entero*/
/* post: pide por consolta que ingrese un numero entre 37 y 47 o que ingrese 0. 
Actualiza el entero referenciado con este valor*/
void pedirTalle(int *talle){
    
    while((*talle > TALLE_MAX || *talle < TALLE_MIN) && (*talle != SIN_ZAPATOS)){
        printf("Ingrese talle  \n Si usa zapatos ingrese un numero entre %d y %d \n Si no usa zapatos ingrese %d \n --->: ", TALLE_MIN, TALLE_MAX,SIN_ZAPATILLAS);
        scanf(" %d", talle);
   
    }
}
/*pre: recibe una referencia a caracter*/
/* post: pide por consola que ingrese A,Y,B,N,R o V. Actualiza el caracter referenciado con el nuevo valor*/
void pedirColor(char *color){
    while( !estaElElemento(COLORES, *color, CANTIDAD_COLORES)){
        printf("Ingrese color:\n");
        printf(" %c para rosa \n %c para verde \n %c para azul \n", ROSA,VERDE,AZUL);
        printf(" %c para amarillo \n %c para blanco \n %c para negro \n", AMARILLO, BLANCO,NEGRO);
        printf("--->");
        scanf(" %c", color);
    }
}
/*pre: recibe una referencia a entero*/
/*post: pide por consola un numero entre 1 y 240. Actualiza el entero referenciado con el nuevo valor*/
void pedirAltura(int *altura){
    char line[256];
    int numero;
    char mensaje[] = "Ingrese altura (entre 1 y 240) \n --->";
    while( *altura < ALTURA_MIN || *altura > ALTURA_MAX){
        imprimir(mensaje);
        fgets(line,sizeof line,stdin);
        *altura = sscanf(line, "%d", &numero);
        if(*altura){
            break;
        }
    }
}

/*pre: recibe una referencia a entero puntate y un caracter color*/
/*post: actualiza el valor de puntaje dependiendo del caracter color*/
void calcularPuntajePorColor(int *puntaje, char color){
    int puntajePorColor = 0;
    switch(color){
        case ROSA:
            puntajePorColor = PUNTOS_ROSA;
            break;
        case AMARILLO:
            puntajePorColor = PUNTOS_AMARILLO;
            break;
        case BLANCO:
            puntajePorColor = PUNTOS_BLANCO;
            break;
        case NEGRO:
            puntajePorColor = PUNTOS_NEGRO;
            break;
        case VERDE:
            puntajePorColor = PUNTOS_VERDE;
            break;
        case AZUL:
            puntajePorColor = PUNTOS_AZUL;
            break;
    
    }
    *puntaje += puntajePorColor;
}
/* pre: recibe una referencia a un entero puntaje y un caracter sabor*/
/*post: actualiza el valor de puntaje dependiendo del caracter sabor*/
void calcularPuntajePorSabor(int *puntaje, char sabor){
    int puntajePorSabor = 0;

    switch(sabor){
        case SALADO:
            puntajePorSabor = PUNTOS_SALADO;
            break;
        case DULCE:
            puntajePorSabor = PUNTOS_DULCE;
            break;
        case AMARGO:
            puntajePorSabor = PUNTOS_AMARGO;
            break;
    }
    *puntaje += puntajePorSabor;

}
/*pre: recibe una referencia a entero puntaje y un entero anio entre 1998 y 20008*/
/*post: actualiza el valor de puntaje dependiendo del valor del entero anio*/
void calcularPuntajePorAnio( int *puntaje, int anio){
    int puntajePorAnio = anio% DIVISOR_ANIO +PUNTO_ADICIONAL_ANIO;
    *puntaje += puntajePorAnio;
}
/*pre: recibe un entero entre 37 y 47 o 0*/
/*post: devuelve el multiplicador dependiendo el valor del talle*/
int calcularMultiplicador(int talle){
    int multiplicador = 0;
    if (MIN_TALLE1 <= talle && talle <=MAX_TALLE1)
    {
        multiplicador = MULTIPLICADOR2;
    }
    else if(MIN_TALLE2 <= talle && talle<= MAX_TALLE2){
        multiplicador = MULTIPLICADOR3;
    }
    else if( MIN_TALLE3 <= talle && talle <= MAX_TALLE3){
        multiplicador = MULTIPLICADOR4;
    }
    else{
        multiplicador = MULTIPLICADOR1;
    }
    
    return multiplicador;
}
/*pre: recibe una referencia entero puntaje, caracter color, caracter sabor, entero altura, entero talle
entero anio*/
/*post: actualiza el valor de puntaje dependiendo de los otros parametros*/
void calcularPuntaje(int *puntaje, int talle, int altura, int anio, char color, char sabor){
    int multiplicador = 0;
    multiplicador = calcularMultiplicador(talle);
    
    calcularPuntajePorColor(puntaje, color);
    calcularPuntajePorAnio(puntaje, anio);
    calcularPuntajePorSabor(puntaje, sabor);
    *puntaje = *puntaje * multiplicador;
}
duo_t obtenerDuo(int puntaje){
    duo_t pollitoPuroHueso = {POLLITO, HUESO, ALTURA_POLLITO,ALTURA_HUESO,ID_POLLITO, ID_HUESO};
    duo_t johnyCoraje = {CORAJE, JHONNY, ALTURA_CORAJE,ALTURA_JHONNY, ID_CORAJE,ID_JOHNNY};
    duo_t blueBellota = {BLUE, BELLOTA, ALTURA_BLUE, ALTURA_BELLOTA, ID_BLUE, ID_BELLOTA};

    duo_t resultado;
    if( 1 <= puntaje  && puntaje <= 80){
        resultado = johnyCoraje;
    }
    else if( 81 <= puntaje && puntaje <= 160){
        resultado = pollitoPuroHueso;
    }
    else {
        resultado = blueBellota;
    }
    return resultado;
}
/* pre: recibe un entero puntaje y un entero altura*/
/*post: imprime el personaje seleccionado dependiendo del puntaje obtenido y de la menor diferencia entre
la altura de los personajes y la altura ingresada*/
void obtenerPersonaje(int puntaje, int altura, char *personaje){
    duo_t resultado = obtenerDuo(puntaje);
    char mensaje[] = "Con un total de ";
    char mensaje1[] = " puntos tu personaje es: ";
    imprimir(mensaje);
    printf("%d", puntaje);
    imprimir(mensaje1);
    if( abs(altura - resultado.altura_personaje1)< (abs ( altura - resultado.altura_personaje2))){
        printf("%s \n", resultado.personaje1);
        *personaje = resultado.id_personaje1;
    }
    else{
        printf("%s\n", resultado.personaje2);
        *personaje = resultado.id_personaje2;
    }
}
/* pre: recibe un vector de caracteres y un caracter elemento */
/* post: devuelve true si el elemento esta en el vector, false si no*/
    bool estaElElemento(const char vector[], char elemento, int tamanio){
 
    int i = 0;
    bool esta = false;

    while (esta == false && i<tamanio){
        if(vector[i] == elemento){
            esta = true;
        }
        i+=1;
    }
    return esta;
}

void detectar_personaje(char* personaje_detectado){

    int puntaje = 0;
    int anio = 0;
    int altura = 0;
    int talle = 1;
    char sabor, color;




    pedirAltura(&altura);
    pedirTalle(&talle);    
    pedirSabor(&sabor);
    pedirAnioNacimiento(&anio);
    pedirColor(&color);

    
    calcularPuntaje(&puntaje, talle,altura,anio,color,sabor);
    obtenerPersonaje(puntaje, altura, personaje_detectado);

    return 0;
}

