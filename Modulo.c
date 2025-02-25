#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

void impMatriz(int *matriz, int S)
{
        for(int i=0; i<S;i++)
        {       for(int j=0; j<S;j++)
                        {
                        printf(" %d ", matriz[i*S+j]);
                        }
        printf("\n");
        }
        printf("----------------------------------------\n");
}

void inicializar_matriz(int *Ma,int *Mb, int s)
{
        for(int i=0; i<s*s;i++)
        {
        Ma[i] = 2*i +1;
        Mb[i] = 3*i;
        }
}
void multiplicar_Matriz(int *Ma,int *Mb,int *Mc,int s){
        for(int i= 0; i<s;i++){
                for(int j = 0;j<s;j++){

                        int Suma = 0;
                        int *pA, *pB;
                        pA = Ma + i*s;
                        pB = Mb + j;
                        for(int k = 0 ; k<s;k++,pA++,pB+=s){
                        Suma += (*pA * *pB);
                        }
                                Mc[i*s+j] = Suma;
                        }
                }
}

void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}

void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

void freeVector(vectorDinamico *V){
        free(V->elementos);
}

void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}

void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}


void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}
