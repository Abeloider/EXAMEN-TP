#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// EJERCIIO 1

/*
// Crea y devuelve un array con las cantidades anuales de un
// depósito bancario que comienza con una cantidad de c euros y
// se incrementa anualmente con interés compuesto del r%, en un
// periodo de n años, es decir:
// v0 = c
// vi= vi-1 + vi-1 ∙ r/100, 0 < i ≤ n
double * deposito(int n, double c, double r)
– Construir un array invocando a la función anterior para un p
*/

double * deposito (int n, double c, double r) {
    double * v = malloc(sizeof(double)*(n));
    v[0]=c;
    for (int i=1; i<n ;i++) {
        v[i] = v[i-1] + v[i-1]*r/100 ;
    }
    return v;
}


// EJERICICIO 2
/*
– Declarar un tipo de datos Estructura para representar estructuras de datos enlazadas (lineales) de
números enteros.
– Leer un número m desde teclado (m≥0) y construir una estructura de datos enlazada e, con celda de
encabezamiento, de m números enteros aleatorios entre -m y m.
– Imprimir en pantalla los elementos de la estructura de datos enlazada e.
– Implementar la siguiente función:

void suprimir_negativos(Estructura e)
– Suprimir los elementos negativos de la estructura de datos enlazada e invocando la función
suprimir_negativos.
– Imprimir en pantalla de nuevo los elementos de la estructura de datos enlazada e.
– Liberar la estructura de datos enlazada e.

*/

/*
    typedef struct Estructura * EstructuraPtr;
    struct Estructura
    {
        int m;
        struct Estructura * e;
    };

// Suprime los números negativos de la estructura de datos
// enlazada e.

    void suprimir_negativos(EstructuraPtr p) {

        while((p->e!=NULL) && (p->e->m >= 0))
        {
            p = p->e;
        }
    EstructuraPtr eliminado = p->e;
    p->e = eliminado->e;
    free(eliminado);
    };

    void imprimirEstructura(EstructuraPtr l)
{
    EstructuraPtr aux=l->e;
    while(aux != NULL)
    {
        printf("%d ", aux->m);
        aux = aux->e;
    }
}
*/

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
            aux = aux->sig;  // Avanzar solo si no se elimin�
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





// EJERCICIO 4

typedef struct ArbolRep * Arbol;
struct ArbolRep
{
    int str;
    Arbol izq, der;
};


Arbol crea_arbol()
{
    char d[10];
    printf("Introducir numero en arbol(o NULL para no introducir nada en esa rama): ");
    scanf("%s", d);
    if(strcmp(d, "NULL")==0) return NULL;
    Arbol a= malloc(sizeof(struct ArbolRep));
    a->str = atoi(d); // cambia de string a numero
    a->izq = crea_arbol();
    if(a->izq != NULL)
        a->der = crea_arbol();
    return a;
}

// Devuelve el número de elementos mayores que b en el árbol
// binario a.
int mayores(Arbol a, int b) {
    if (a==NULL)
    return 0;

    int valor = mayores(a->izq,b)+mayores(a->der,b);
    if (a->str>b)
    valor++;
    return valor;
}




int main () {

    SetConsoleCP(1252);              //Para poder usar caracteres espa�oles y otros...
    SetConsoleOutputCP(1252);       //Para poder usar caracteres espa�oles y otros...
    srand(time(NULL));
    // EJERICIO 1
    int n=10;
    double c=5000;
    double r=3;
    double * v = deposito(n,c,r);
    for (int i=0; i<n; i++)  {
        printf("%f", v[i]);
    }
    printf("\n");
    free(v);



    // EJERICICIO 2

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

    liberarEstructura(l);

    //EJERCICIO 4

    Arbol ab = crea_arbol();
    int b;
    printf("Conteo de numeros mayores que: ");
    scanf("%d", &b);
    printf("Numeros mayores que %d en el arbol: %d", b, mayores(ab, b));

    return 0;
}
