#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Linea.h"

// Crea y devuelve una nueva línea desde el punto (x1,y1) hasta
// (x2,y2)
struct LineaRep {
    double x1;
    double x2;
    double y1;
    double y2;
};


Linea LineaCrea(double x1, double y1, double x2, double y2){
    Linea l = malloc(sizeof(struct LineaRep));
    l->x1=x1;
    l->x2=x2;
    l->y1=y1;
    l->y2=y2;
    return l;
};
// Libera la memoria asignada a la línea l
void LineaLibera(Linea l){
    free(l);
};



// Mueve la línea l con desplazamientos dx y dy en las
// coordenadas x e y respectivamente. Es decir, incrementa los
// valores x1 y x2 en una cantidad dx y los valores y1 e y2
// en una cantidad dy.

void LineaMueve(Linea l, double dx, double dy){
    l->x1+=dx;
    l->x2+=dx;
    l->y1+=dy;
    l->y2+=dy;

};
