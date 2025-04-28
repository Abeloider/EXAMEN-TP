#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Nodo * Estructura ; // tipo d edato con estruct apuntado a strcut nodo *

struct Nodo{
    int elem;
    Estructura sig; //struct nodo * sigueinte
};

Estructura estructura_ramdom(int n,int a,int b) {

    Estructura e = malloc(sizeof(struct Nodo)); // nodod de encabezamiento
    e->sig =NULL; // el siguiente es null [ | -]-> [8|x(NULL)]
    for (int i=0; i<n;i++) {
        Estructura nuevo = malloc(sizeof(struct Nodo));
        nuevo -> elem = a + rand()%(b-a+1) ;
        nuevo -> sig = e -> sig;
        e -> sig = nuevo;
    }
    return e;

}
Estructura estructura_ramdom_v2(int n,int a,int b) {

    Estructura e = malloc(sizeof(struct Nodo)); // nodod de encabezamiento
    Estructura aux= e; // el siguiente es null [ | -]-> [8|x(NULL)]
    for (int i=0; i<n;i++) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux = aux->sig;
        aux->elem = a + rand()%(b-a+1) ;
    }
    aux -> sig = NULL;
    return e;
}


void imprimir(Estructura e){
    Estructura aux = e->sig;
    while (aux !=NULL) {
        printf("%d ", aux->elem);
        aux = aux -> sig;
    }
    printf("\n");
}

void imprimir_v2(Estructura e){
    while (e->sig!=NULL) {
        printf("%d ", e->sig->elem);
        e = e->sig;
    }
    printf("\n");

}


Estructura concatenar(Estructura e1,Estructura e2){
    Estructura e = malloc(sizeof(struct Nodo));
    Estructura aux= e;
    while (e1->sig!=NULL) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux = aux->sig;
        aux->elem = e1->sig->elem;
        e1 = e1->sig;
    }
    while (e2->sig!=NULL) {
        aux->sig = malloc(sizeof(struct Nodo));
        aux = aux->sig;
        aux->elem = e2->sig->elem;
        e2 = e2->sig;
    }

    aux->sig=NULL;
    return e;
    }

void suprime_todos(Estructura l, int dato){
    Estructura p        = l;
    while (p->sig != NULL){
        if (p->sig->elem == dato){
        Estructura eliminado = p->sig;
        p->sig = eliminado->sig;
        free(eliminado);
        } else {
        p = p->sig;
        }
    }
}

void suprimir_repetidos(Estructura e) {

    while(e->sig!=NULL) {
        suprime_todos(e->sig, e->sig->elem);
        e=e->sig;
    }

}

void liberar (Estructura e) {
    while (e!=NULL) {
        Estructura aux = e;
        e = e ->sig;
        free (aux);
    }
}

    int main(){
        int n,a,b;
        printf("Introducce numero de elementos: ");
        scanf("%d", &n);
        printf("Introducce limite inferior: ");
        scanf("%d", &a);
        printf("Introducce limite sueperior: ");
        scanf("%d", &b);
        Estructura e1 = estructura_ramdom_v2(n,a,b);
        imprimir_v2(e1);

        // repetir con e2
        //int n,a,b;
        printf("Introducce numero de elementos: ");
        scanf("%d", &n);
        printf("Introducce limite inferior: ");
        scanf("%d", &a);
        printf("Introducce limite sueperior: ");
        scanf("%d", &b);
        Estructura e2 = estructura_ramdom_v2(n,a,b);
        imprimir_v2(e2);
        Estructura e3 = concatenar(e1,e2);
        imprimir_v2(e3);

        suprimir_repetidos(e3);
        imprimir_v2(e3);
        liberar(e1);
        liberar(e2);
        liberar(e3);


        return 0;

}
