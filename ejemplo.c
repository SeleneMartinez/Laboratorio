#include <stdio.h>
#include "utiles.h"
#include "escape_laboratorio.h"
void imprimirLaboratorio(int nivel1, coordenada_t paredes[MAX_PAREDES],int tope);
int main(){
    int nivel =1;
    coordenada_t paredes[MAX_PAREDES];
    int tope = 0;

    char laboratorio[12][12];
    for(int i =0; i<12; i+=1){
        for(int j = 0; j<12; j+=1){
            
            laboratorio[i][j] = ' ';
        }
    }
    laboratorio[1][1] = 'X';
    if(posicionLibre(12,laboratorio,1,1)){
        printf("YASSSSSS BITCH!");
    }
    else{
        printf("nOOOOoO");
    }

    return 0;
}
void imprimirLaboratorio(int nivel1, coordenada_t paredes[MAX_PAREDES],int tope){
    int dimension = 12;
    if (nivel1%2 == 0) //par
        dimension = 17;
    char matriz[17][17];

    for(int i =0; i<17; i+=1){
        for(int j = 0; j<dimension; j+=1){
            
            matriz[i][j] = ' ';
        }
    }
    for(int i = 0; i< tope;i++){
        matriz[paredes[i].fil][paredes[i].col] = '#';
    }
    for(int i =0; i<17; i+=1){
        for(int j = 0; j<dimension; j+=1){
            
            printf("%c ",matriz[i][j]);
        }
        printf("\n");
    }
}