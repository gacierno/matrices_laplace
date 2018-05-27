#include <stdlib.h>
#include "matriz.h"
#include <math.h>

void inic_matriz(matriz *m, int f, int c){
    (*m).filas = f;
    (*m).columnas = c;
}

void mostrar_matriz(matriz m){
    int i = 0,
        j = 0;

    for(i=0; i< m.filas;i++){
        for(j=0; j<m.columnas; j++){
            printf("| %3d ", m.datos[i][j]);
        }
        printf("|\n");
    }
}

void leer_matriz(matriz *m){
    int i = 0,
        j = 0;

    for(i=0; i< (*m).filas;i++){
        for(j=0; j<(*m).columnas; j++){
            //printf("ingrese un valor entero en la posicion %d %d", i, j);
            //scanf("%d", &((*m).datos[i][j]));
            (*m).datos[i][j] = rand() % 3;
        }
    }
}

matriz sumar_matrices(matriz m1, matriz m2)
{
    int i = 0, j = 0;
    matriz mat_out;
    mat_out.filas = 0;
    mat_out.columnas = 0;

    if( m1.filas == m2.filas && m1.columnas == m2.columnas )
    {
        mat_out.filas = m1.filas;
        mat_out.columnas = m1.columnas;
        for(i = 0; i < m1.columnas; i++)
        {
            for( j = 0; j < m1.filas; j++)
            {
                mat_out.datos[i][j] = m1.datos[i][j] + m1.datos[i][j];
            }
        }
    }
    else
    {
        printf("No se han podido sumar las matrices seleccionadas porque no se corresponden las dimensiones \n");
    }
    return mat_out;
}

void cargar_dato_posicion(matriz *m, int f, int c, int valor){
    m->datos[f][c] = valor;
}

int determinante_2x2(matriz m)
{
    int determinante = 0;
    determinante = m.datos[0][0] * (m.datos[1][1]) - m.datos[0][1] * (m.datos[1][0]);
    //mostrar_matriz(m);
    //printf("2x2 %d\n", determinante);
    return determinante;
}

int determinante_matriz(matriz m){

    matriz *resultado_mats;
    int *indices_resultado_nums;
    int i = 0;
    int determinante = 0;

    resultado_mats = (matriz*)malloc( sizeof(matriz) * m.filas);
    indices_resultado_nums = (matriz*)malloc( sizeof(matriz) * m.filas);

    if(m.filas == 2 && m.columnas == 2){
        determinante = determinante_2x2(m);
    }else{
        bajar_nivel_matriz(m, resultado_mats, indices_resultado_nums );
        for(i=0; i < m.columnas; i++){
            determinante = determinante + pow(-1, i)*indices_resultado_nums[i]*(determinante_matriz(resultado_mats[i]));
            //printf("\n pow %f \n", pow(-1,i) );
        }
    }

    free(resultado_mats);
    free(indices_resultado_nums);

    return determinante;
}

void bajar_nivel_matriz(matriz m, matriz res_mat[], int res_num[])
{
    int f = 0;
    int c = 0;
    //int i = 0;
    int aux_col = 0;
    int aux_fil = 0;

    for(int i=0; i< m.columnas; i++){
       res_num[i] = m.datos[0][i];
    }

    for(int i=0; i< m.columnas; i++){
        res_mat[i].filas = m.filas -1;
        res_mat[i].columnas = m.columnas -1;
        aux_fil = 0;
        for(f=0; f<m.filas; f++){
            aux_col = 0;
            for(c=0; c < m.columnas; c++){
                if(f != 0 && c != i){
                    //printf("%d \n", m.datos[f][c]);
                    //res_mat[i].datos[aux_fil][aux_col] = m.datos[f][c];
                    cargar_dato_posicion(&res_mat[i], aux_fil, aux_col, m.datos[f][c]);
                    //printf("%d\n", res_mat[i].datos[aux_fil][aux_col]);
                    //printf("col %d ", aux_col);
                    //printf("fil %d\n", aux_fil);
                    aux_col++;
                }
            }
            if(f != 0 && c != i){
               aux_fil++;
            }

        }
        //printf("%d\n", res_num[i]);
        //mostrar_matriz(res_mat[i]);
    }
}
