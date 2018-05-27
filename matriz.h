#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include <stdio.h>


typedef struct{
    int datos[50][50];
    int filas;
    int columnas;
}matriz;

void inic_matriz(matriz*, int, int);
void mostrar_matriz(matriz);
void leer_matriz(matriz*);
matriz sumar_matrices(matriz, matriz);
int determinante_2x2(matriz);
int determinante_matriz(matriz);

void cargar_dato_posicion(matriz*, int, int, int);

#endif // MATRIZ_H_INCLUDED
