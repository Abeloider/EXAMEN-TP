#include "Cola.h"
#include <stdlib.h>
struct Celda
{
    Elemento elem;
    struct Celda * sig;
};
typedef struct Celda * Celda;
struct ColaRep
{
    Celda frente, posterior;
};
Cola crea()
{
    Cola c = malloc(sizeof(struct ColaRep));
    c->frente = malloc(sizeof(struct Celda));
    c->frente->sig = NULL;
    c->posterior = c->frente;
    return c;
}
void libera(Cola c)
{
    while(c->frente!=NULL)
    {
        Celda aux = c->frente;
        c->frente = c->frente->sig;
        free(aux);
    }
    free(c);
}
void inserta(Cola c, Elemento e)
{
    Celda aux = malloc(sizeof(struct Celda));
    aux->elem = e;
    aux->sig = NULL;
    c->posterior->sig = aux;
    c->posterior = aux;
}
void suprime(Cola c)
{
    Celda aux = c->frente;
    c->frente = c->frente->sig;
    free(aux);
}
Elemento recupera(Cola c)
{
    return c->frente->sig->elem;
}
int vacia(Cola c)
{
    return (c->frente->sig==NULL);
}
