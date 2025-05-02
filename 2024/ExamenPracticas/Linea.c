#include <stdlib.h>
#include "Linea.h"

struct LineaRep {
    double x1,y1,x2,y2;
};

Linea LineaCrea(double x1, double y1, double x2, double y2)
{
    Linea l = malloc(sizeof(struct LineaRep));
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;
    return l;
}

void LineaLibera(Linea l)
{
    free(l);
}

void LineaMueve(Linea l, double dx, double dy)
{
    l->x1 +=dx;
    l->x2 +=dx;
    l->y1 +=dy;
    l->y1 +=dy;
}
