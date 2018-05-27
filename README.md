# Determinante de MAtrices NxN (matrices_laplace)

Este es un programa desarllado en C que permite calcular el determinante de una matriz de hasta 50x50
Si, lo puede resolver solo que necesitara un array de 50!(factorial de 50) posiciones para lograrlo y el tiempo para recorrerlo se hara enorme.
En una matriz de 12x12 tardo unos 9 minutos en una computadora con un procesador i5.

Lo llame matrices_laplace debido a que logre hacer una funcion que aplica el [Teorema de Laplace](https://es.wikipedia.org/wiki/Teorema_de_Laplace) de manera recursiva para lograr obtener N matrices de 2x2 para resolver su determinante.

## Antes de comenzar

Este programa al haber sido programado en C puede correr en cualquier complilador que que desees.
Yo particularmente me siento comodo utilizando [Codeblocks](http://www.codeblocks.org/) ya que es un IDE bastante completo y es open source
Pero insisto que se puede utilizar cualquier compliador.

### Archivos importantes

Si usas Codeblocks recuerda importar los archivos .c y .h en el proyecto.

### Detalles:

* Las matrices que se utilizan aqui parten de una estructura definida de la siguiente manera:

```
 typedef struct{
    int data[50][50];
    int filas;
    int columnas;
 }matriz;
```
 ## Autor
 
* **German Acierno** - *Initial work*
 
 ## Licencia
 
 En proceso.

