#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    int det;
    matriz matrizA;

    inic_matriz(&matrizA, 6, 6);

    leer_matriz(&matrizA);

    mostrar_matriz(matrizA);
    printf("\n");
    det = determinante_matriz(matrizA);
    printf("\n");
    printf("el determinante es %d", det);

    return 0;
}
