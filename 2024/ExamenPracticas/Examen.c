#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


double * deposito(int n, double c, double r)
{
    double * v = malloc((n+1)*sizeof(double));
    v[0]=c;
    for(int i = 1; i<=n; i++)
    {
        v[i]= v[i-1]+(v[i-1]*(r/100.0));
    }
    return v;
}

typedef struct EstructuraRep * Estructura;
struct EstructuraRep{
    int elem;
    Estructura sig;
};

Estructura crearEstructura(int m)
{
    Estructura l = malloc(sizeof(struct EstructuraRep));
    Estructura aux = l;
    for(int i = 0; i<m ; i++){
        aux->sig= malloc(sizeof(struct EstructuraRep));
        aux->sig->elem= -m + rand() % (2 * m + 1); // Entre -m y m
        aux= aux->sig;
    }
    aux->sig = NULL;
    return l;
}
void imprimirEstructura(Estructura l)
{
    Estructura aux=l->sig;
    while(aux != NULL)
    {
        printf("%d ", aux->elem);
        aux = aux->sig;
    }
}

void suprimir_negativos(Estructura e)
{
    Estructura aux = e;
    while(aux->sig != NULL){
        if(aux->sig->elem < 0){
            Estructura eliminado = aux->sig;
            aux->sig = eliminado->sig;
            free(eliminado);
        } else {
            aux = aux->sig;  // Avanzar solo si no se eliminó
        }


    }
}

void liberarEstructura(Estructura e)
{
    Estructura aux = e;
    while(aux!= NULL)
    {
        aux=aux->sig;
        free(aux);
    }
}

typedef struct ArbolBinarioRep * ArbolBinario;
struct ArbolBinarioRep {
    int dato;
    ArbolBinario izq, der;

};

ArbolBinario crearArbolBinario(){

    char d[10];
    printf("Introducir numero en arbol(o NULL para no introducir nada en esa rama): ");
    scanf("%s", d);
    if(strcmp(d, "NULL")==0) return NULL;
    ArbolBinario a= malloc(sizeof(struct ArbolBinarioRep));
    a->dato = atoi(d);
    a->izq = crearArbolBinario();
    if(a->izq != NULL)
        a->der = crearArbolBinario();

    return a;


}

int mayores(ArbolBinario a, int b)
{
    int n=0;
    if(a!=NULL)
    {
        if(a->dato > b)
            n++;

        n+= mayores(a->izq,b);
        n+= mayores(a->der,b);
    }
    return n;
}
int main()
{
     /*   srand(time(NULL));

    double * ejercicio1 = deposito(5,1000,3);

    for(int i = 0; i<=5; i++){
        printf("%f ", ejercicio1[i]);
    }

    free(ejercicio1);
    printf("\n");
    int m;
    printf("Introduce numero m:");
    scanf("%d", &m);

    Estructura l = crearEstructura(m);
    printf("Estructura generada:\n");
    imprimirEstructura(l);

    suprimir_negativos(l);
    printf("Estructura sin negativos:\n");
    imprimirEstructura(l);

    liberarEstructura(l);*/

    ArbolBinario ab = crearArbolBinario();
    int b;
    printf("Conteo de numeros mayores que: ");
    scanf("%d", &b);
    printf("Numeros mayores que %d en el arbol: %d", b, mayores(ab, b));
    return 0;
}
