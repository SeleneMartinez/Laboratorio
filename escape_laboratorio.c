#include <stdio.h>
#include "utiles.h"
#include <stdlib.h>
#include <stdbool.h>

const char PINCHE = 'P';
const char BALDOSA_LIBRE = ' ';
const char BOMBA = 'B';
const char GUARDIA = 'G';

const int IGUALAR_POSICION_NIVEL =1;
const int NIVEL_INICIAL = 1;
const int NIVEL2 = 2;
const int NIVEL3 = 3;
const int NIVEL4 = 4;

const int DIMENSION_NIVEL_PAR = 17;
const int DIMENSION_NIVEL_IMPAR = 12;


int main(){

    printf("hola");
    return 0;
}

int obtener_Dimension_Nivel(int nivel){
    int dimension = DIMENSION_NIVEL_IMPAR;
    if(nivel %2 ==0){
        dimension = DIMENSION_NIVEL_PAR;
    }
    return dimension;
}
void inicializar_juego(juego_t* juego, char tipo_personaje){
    
    (*juego).nivel_actual = NIVEL_INICIAL;
    int dimension = DIMENSION_NIVEL_IMPAR;

    for(int i = 0; i<MAX_NIVELES; i++){
        dimension = obtener_Dimension_Nivel(i);
        nivel_t nivel;
        int numero_nivel= i+IGUALAR_POSICION_NIVEL;
        int cantidad_guardias = 0;
        int baldosas_pinches =0;
        bool bomba = false;
        switch(numero_nivel){
            case 1:
                cantidad_guardias = 2;
                baldosas_pinches = 4;
                bomba = false;
                break;
            case 2:
                cantidad_guardias = 3;
                baldosas_pinches = 6;
                bomba = false;
                break;
            case 3:
                cantidad_guardias = 3;
                baldosas_pinches = 6;
                bomba = true;
                break;
            case 4:
                cantidad_guardias = 6;
                baldosas_pinches = 10;
                bomba = true;
                break;
            }

        inicializar_nivel(&nivel,numero_nivel,baldosas_pinches,cantidad_guardias, bomba);
    
        
    }
}
void inicializar_laboratorio( int dimension, char laboratorio[dimension][dimension]){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j< dimension; j++){
            laboratorio[i][j] = BALDOSA_LIBRE;
        }
    }
}

bool posicionLibre(int dimension, char laboratorio[dimension][dimension], int fila, int col){
    bool libre = false;
    if(laboratorio[fila][col] == BALDOSA_LIBRE){
        libre =true;
    }
    return libre;
}
void obtener_posicion_aleatoria( coordenada_t *posicion, int dimension, char laboratorio[dimension][dimension]){
    bool posicionValida = false;
    int fila;
    int col;
    do{
        fila = rand()%dimension;
        col = rand()%dimension;
        posicionValida = posicionLibre(dimension,laboratorio,fila,col);
    }   while(!posicionValida);
    posicion->col = col;
    posicion->fil = fila;
}


void inicializar_nivel(nivel_t* nivel, int numero_nivel, int cantidad_baldosas_pinches, int cantidad_guardia, bool hay_bomba){
    int dimension = obtener_Dimension_Nivel(numero_nivel);
    char laboratorio[dimension][dimension];
    inicializar_laboratorio(dimension,laboratorio);

    obtener_posicion_aleatoria(&(nivel->entrada), dimension, laboratorio);
    obtener_posicion_aleatoria(&(nivel->salida),dimension,laboratorio);

    obtener_paredes(numero_nivel,(nivel->paredes),&(nivel->tope_paredes));

    int tope_obstaculos =0;

    for(int i = 0; i< cantidad_baldosas_pinches; i++){
        elemento_t pinche;
        coordenada_t posicion;
        pinche.tipo = PINCHE;
        obtener_posicion_aleatoria(&posicion,dimension,laboratorio);
        pinche.posicion = posicion;
        nivel->obstaculos[i] = pinche;
        tope_obstaculos++;
    }

    for(int i = cantidad_baldosas_pinches; i< cantidad_guardia; i++){
        elemento_t guardia;
        coordenada_t posicion;
        guardia.tipo = GUARDIA;
        obtener_posicion_aleatoria(&posicion,dimension,laboratorio);
        guardia.posicion = posicion;
        nivel->obstaculos[i] = guardia;
        tope_obstaculos++;
    }
    if(hay_bomba){
        elemento_t bomba;
        coordenada_t posicion;
        bomba.tipo = BOMBA;
        obtener_posicion_aleatoria(&posicion,dimension,laboratorio);
        bomba.posicion = posicion;
        nivel->obstaculos[cantidad_guardia] = bomba;
        tope_obstaculos++;
    }

    nivel->tope_obstaculos = tope_obstaculos;


}