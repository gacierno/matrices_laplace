#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "matriz.h"

float calcular_porcentajes(int parametrocapital, int porcentaje_entrada)
{
    float resultado_salida;
    resultado_salida = (float)parametrocapital*porcentaje_entrada/100;
    return resultado_salida;
}

float sumar2numeros(int sumando1, int sumando2)
{
    float salida;
    salida = sumando1+sumando2;
    return salida;
}

int main()
{
    int capital;
    int porcentaje;
    matriz matrizA;
    matriz matrizB;
    matriz resultado;

    inic_matriz(&matrizA, 11, 11);
    inic_matriz(&matrizB, 3, 3);

    leer_matriz(&matrizA);
    //leer_matriz(&matrizB);

    //resultado = sumar_matrices(matrizA, matrizB);
    //mostrar_matriz(resultado);

    //capital = determinante_2x2(matrizA);
    mostrar_matriz(matrizA);
    printf("\n");
    capital = determinante_matriz(matrizA);
    printf("\n");
    printf("el determinante es %d", capital);

    return 0;
}
