/*Fecha: 18 de Febrero 2025                                                                                                          
* Autor: Tomás Ospina Ulloa.                                                                                                        
* Materia: Sistemas Operativos                                                                                                       
* Tema: Memoria dinamica y operacion de multiplicacion de matrices, complejidad, creacion de benchmark, programacion modular y autom>**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

int main(int argc, char *argv[])
{
        //se toma el valor de entrada Tamaño de matriz
        int N = (int) atoi(argv[1]);
        printf("Valor ingresado %d \n",N);
        //reserva de memoria para matriz dinamica
        int *Ma = (int*) malloc(N*N*sizeof(int));
        int *Mb = (int*) malloc(N*N*sizeof(int));
        int *Mc = (int*) malloc(N*N*sizeof(int));
        //inicializacion de matriz
        inicializar_matriz(Ma,Mb,N);
        //multiplicacion de matriz
        multiplicar_Matriz(Ma,Mb,Mc,N);
        //impresion de matrices
        impMatriz(Ma,N);
        impMatriz(Mb,N);
        impMatriz(Mc,N);
        //liberacion de memoria
        free(Ma);
        free(Mb);
        free(Mc);
        return 0;
}
