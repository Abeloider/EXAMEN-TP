#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Ejercicio 1
float * crear_array(int n)
{
    float * a=malloc(sizeof(float)*n);
    for (int i=1; i<=n; i++)
    {
        a[i-1]=((i-1.0)/i);
    }
    return a;
}

//Ejercicio 2
typedef struct EstructuraRep * Estructura;
struct EstructuraRep
{
    float n;
    Estructura sig;
};
//Ejercicio 3
Estructura arrayToEstructura(float * v, int n)
{
    Estructura e=malloc(sizeof(struct EstructuraRep));
    Estructura aux= e;
    for (int i=0; i<n; i++)
    {
        aux->sig=malloc(sizeof(struct EstructuraRep));
        aux->sig->n=v[i];
        aux= aux->sig;
    }
    aux->sig=NULL;
    return e;
}
//Ejercicio 4
void suprimePrimero(Estructura l)
{
    Estructura eliminado = l->sig;
    l->sig = l->sig->sig;
    free(eliminado);
}
//Ejercicio 5
void imprimirEstructura(Estructura e)
{
    Estructura l=e;
    while(l->sig!=NULL)
    {
        printf("%.2f ",l->sig->n);
        l = l->sig;

    }
}
//Ejercicio 6

void liberarEstructura(Estructura l)
{
    while (l!=NULL)
    {
        Estructura aux = l;
        l = l->sig;
        free(aux);
    }
}
//Ejercicio 7
typedef struct ArbolRep * Arbol;
struct ArbolRep
{
    char str[10];
    Arbol izq, der;
};
//Ejercicio 8
float ExpresionValor(Arbol a)
{
    float v = 0;
    if (a->izq==NULL) v = atof(a->str);
    else
        switch(a->str[0])
        {
        case '+':
            v = ExpresionValor(a->izq)+ExpresionValor(a->der);
            break;
        case '-':
            v = ExpresionValor(a->izq)-ExpresionValor(a->der);
            break;
        case '*':
            v = ExpresionValor(a->izq)*ExpresionValor(a->der);
            break;
        case '/':
            v = ExpresionValor(a->izq)/ExpresionValor(a->der);
        }
    return v;
}


//Ejercicio 9
void libera(Arbol a)
{
    if (a==NULL) return;
    libera(a->izq);
    libera(a->der);
    free(a);
}


int main ()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
//Ej 10
    int n=5;
    float * v=crear_array(n);
    Estructura e= arrayToEstructura(v,n);
    suprimePrimero(e);
    imprimirEstructura(e);
    // Ejercicio 11:

    Arbol f=malloc(sizeof(struct ArbolRep));
    strcpy(f->str, "+");
    f->izq=malloc(sizeof(struct ArbolRep));
    strcpy(f->izq->str, "3.2");
    f->izq->izq=NULL;
    f->izq->der=NULL;
    f->der=malloc(sizeof(struct ArbolRep));
    strcpy(f->der->str,"5.1");
    f->der->izq=NULL;
    f->der->der=NULL;
    printf("\n%.2f",ExpresionValor(f));
    return 0;
}
