#ifndef LINEA_H_INCLUDED
#define LINEA_H_INCLUDED

typedef struct LineaRep * Linea;
// Crea y devuelve una nueva l�nea desde el punto (x1,y1) hasta
// (x2,y2)
Linea LineaCrea(double x1, double y1, double x2, double y2);
// Libera la memoria asignada a la l�nea l
void LineaLibera(Linea l);
// Mueve la l�nea l con desplazamientos dx y dy en las
// coordenadas x e y respectivamente. Es decir, incrementa los
// valores x1 y x2 en una cantidad dx y los valores y1 e y2
// en una cantidad dy.
void LineaMueve(Linea l, double dx, double dy);

#endif // LINEA_H_INCLUDED
