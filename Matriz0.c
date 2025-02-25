/*Fecha: 18 de Febrero 2025                                                                                                          
* Autor: Tomás Ospina Ulloa.                                                                                                        
* Materia: Sistemas Operativos                                                                                                       
* Tema: Memoria dinamica y operacion de multiplicacion de matrices, complejidad, creacion de benchmark, programacion modular y autom>**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"
#include "moduloVector.h"
#define CAPACIDAD_INICIAL 4

int main(int argc, char *argv[]){
    int opcion;
    cout << "Menú:\n1. Usar Matriz Modular\n2. Manejar Vectores\nSeleccione una opción: ";
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            	//se toma el valor de entrada Tamaño de matriz
        	int N = (int) atoi(argv[1]);
        	printf("Valor ingresado %d \n",N);
        	//reserva de memoria para matriz dinamica
        	int *Ma = (int*) malloc(N*N*sizeof(int));
        	int *Mb = (int*) malloc(N*N*sizeof(int));
        	int *Mc = (int*) malloc(N*N*sizeof(int));

        	inicializar_matriz(Ma,Mb,N);
        	multiplicar_Matriz(Ma,Mb,Mc,N);
        	impMatriz(Ma,N);
        	impMatriz(Mb,N);
        	impMatriz(Mc,N);
	
        	free(Ma);
        	free(Mb);
        	free(Mc);
            break;
        case 2:
                typedef struct vectorDinamico{
                int capacidad;
                int totalElementos;
                void **elementos;
                } vectorDinamico;
		vectorDinamico editor;
        	vectorInicio(&editor);

        	addVector(&editor, "Hola");
        	addVector(&editor, "Profesional");

        	for (i = 0; i < totalVector(&editor); i++)
        	printf("%s", (char *) getVector(&editor, k));

        	borrarVector(&editor, 1);

        	setVector(&editor, 1, "Buenos");

        	for (i = 0; i < totalVector(&editor); i++)
        	printf("%s ", (char *) getVector(&editor, k));
            break;
        default:
            cout << "Opción no válida." << endl;
    }
    return 0;
}
