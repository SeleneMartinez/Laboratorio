#ifndef __DETECTOR_PERSDONAJES_H__
#define __DETECTOR_PERSDONAJES_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define JHONNY "Jhonny Bravo"
#define BELLOTA "Bellota"
#define POLLITO "Pollito"
#define BLUE "Blue"
#define HUESO "Puro Hueso"
#define CORAJE "Coraje"
#define ID_JOHNNY 'J'
#define ID_POLLITO 'P'
#define ID_BELLOTA 'S'
#define ID_HUESO 'H'
#define ID_CORAJE 'C'
#define ID_BLUE 'B'

#define VERDE  'V'
#define ROSA  'R'
#define NEGRO  'N'
#define AMARILLO  'Y'
#define AZUL  'A'
#define BLANCO  'B'
#define SALADO  'S'
#define DULCE  'D'
#define AMARGO  'A'

const int ALTURA_JHONNY = 180;
const int ALTURA_BELLOTA = 120;
const int ALTURA_POLLITO = 50;
const int ALTURA_BLUE = 140;
const int ALTURA_HUESO = 200;
const int ALTURA_CORAJE = 30;



const char COLORES[] = {NEGRO, BLANCO,AMARILLO,ROSA,AZUL,VERDE};
const char SABORES[] = {SALADO,DULCE,AMARGO};
const int TALLES[] = {0,37,38,39,40,41,42,43,44,45,46,47};

const int SIN_ZAPATILLAS = 0, MIN_TALLE1 = 33, MAX_TALLE1 = 37;
const int MIN_TALLE2 = 38, MAX_TALLE2 = 42, MIN_TALLE3 = 43, MAX_TALLE3 = 47;
const int CANTIDAD_SABORES = 3;
const int CANTIDAD_COLORES = 6;
const int CANTIDAD_TALLES = 12;

const int PUNTO_ADICIONAL_ANIO = 1;
const int DIVISOR_ANIO = 20;

const int MULTIPLICADOR1 = 1, MULTIPLICADOR2 = 2, MULTIPLICADOR3 =3, MULTIPLICADOR4 =4;

const int ANIO_MAX = 2008, ANIO_MIN = 1988;
const int TALLE_MAX = 47, TALLE_MIN = 37, SIN_ZAPATOS = 0;
const int ALTURA_MAX =240, ALTURA_MIN =1;
const int MAX_ASCII = 126, MIN_ASCII =20;

const int PUNTOS_ROSA = 5, PUNTOS_AMARILLO = 5, PUNTOS_BLANCO = 15, PUNTOS_NEGRO = 15;
const int PUNTOS_AZUL = 20, PUNTOS_VERDE = 20;
const int PUNTOS_SALADO =5, PUNTOS_DULCE = 15, PUNTOS_AMARGO = 20;



typedef struct duo{
    char personaje1[12];
    char personaje2[12];
    int altura_personaje1;
    int altura_personaje2;
    char id_personaje1;
    char id_personaje2;
    
}duo_t;

void detectar_personaje(char* personaje_detectado);

#endif /* __DETECTOR_PERSDONAJES_H__ */