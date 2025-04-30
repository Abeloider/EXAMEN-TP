#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


// EJERCICIO 1 
int * vectorEnteros(int n) {
    int * v = malloc(sizeof(int) * n);
    v[0] = 1;
    v[1] = 3;
    for (int i = 2 ; i<n ; i++) {
        v[i] = (i+1) * (v[i-1] - v[i-2]);
    }
}


// EJERCICIO 2 
// DEFINIR UN TIPO DE DATOS QUE REPRESESNTA UNA ESTRCTURA ENLAZADA

typedef struct Nodo * NodoPtr {
    int elem; 
    struct Nodo * sig; 
} 


// ejercicio 3
// una funcion que reciba comoparametro un vector de enters y un entero que indica el numero de elementos 
// del vector y devuleva una estructura enlazada que contenga los elementos del vector
// del mismo orden. Por ejemplo, si llamamos a esta funcion con el vector obtenido en el apartado 1, devolveria
// una estructura con los elementos 1,3,6,12,30

NodoPtr VectorEnteros(int* v, int n) {
    NodoPtr e = malloc(sizeof(struct Nodo));
    NodoPtr aux = e; 
    for (int i=0; i<n; i++) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux->sig->elem = v[i]; 
        aux = aux->sig;
    }
    aux->sig = NULL;
    return e;
}

// EJERCICIO 4
// una funcion que reciba como parametro una estructura enlazada y
// elimine el primer elemento par de la lista enlazada
// si no hay ningun elemento par, la lista queda igual
// si la lista esta vacia, la lista queda vacia

void SuprimePrimerPar(NodoPtr l) {
    NodoPtr p = l;
    while (p->sig != NULL) {
        if (p->sig->elem % 2 == 0) {
            NodoPtr borrar = p->sig;
            p->sig = borrar->sig;
            free(borrar);
            break;
        }
        p = p->sig;
    }
} 

// EJERCICIO 5
// una funcion que recibe como parametro una estructura enlazada de enteros 
// y la imprime por pantalla 


void imprime(NodoPtr l) {
    l = l->sig; 
    while (l != NULL) {
        printf("%d\n", l->elem);
        l = l->sig;
    }

// EJERCICIO 6
// un procedimeinto que recie como parametro una 
// estructura de enteros y la libera 

void imprime 