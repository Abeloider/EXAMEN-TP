#include "bombo.h"
#include <stdlib.h>
#include <stdio.h>

int error;
char mensaje[100];


// para arreglar ya que solo llega a numeros hasta 32000 y algo ....
unsigned long long large_rand() {
	const int ndigits = 19;
	unsigned long long r = 0;
	for (int i=1; i<ndigits; i++) {
			r*=10;
			r+=rand()%10;
	}
	return r;
}


struct BomboRep
{
    int *bolas;
    int max;
    int n;
};

Bombo BomboCrea(int max){
    if (max<2)
    {
        error = 1;
        return NULL;
    }
    Bombo b = malloc(sizeof(struct BomboRep));
    b-> bolas = malloc(sizeof(int)*max);
    b-> max=max;
    b-> n =0;
    return b;
}


int BomboInserta(Bombo b, int bola)
{
    if (b->max == b->n)
    {
        error =2;
        return -1;
    }
    b->bolas[b->n] = bola;
    b->n++;
    return 0;
}


void BomboLibera(Bombo b)
{
    if (b != NULL) {
        free(b->bolas);  // Liberar el array de bolas
        free(b);
    }
}

// genera numeros aleatorios entre 0 y 2 elevado a 20 -1
int BomboExtrae(Bombo b)
{
    if (b->n == 0)
    {
        error = 3;
        return 0;
    }
    int indice = large_rand()%b->n;
    int bola = b-> bolas[indice];
    b->bolas[indice] = b-> bolas[b->n-1];
    b->n--;
    return bola;
}


int BomboVacia(Bombo b)
{
    return (b->n ==0); // comprobacion
}


char *BomboMensajeError(int codigoError) {
    switch(codigoError) {
        case 1: {
            sprintf(mensaje, "El numero de bolas debe de ser mayor de 2. \n");
            return mensaje;
        }
        case 2: {
            sprintf(mensaje, "El bombo esta lleno. \n");
            return mensaje;
        }
        case 3: {
            sprintf(mensaje, "bombo vacio. \n");
            return mensaje;
        }
        default : {
            return NULL;
        }
    }
}


