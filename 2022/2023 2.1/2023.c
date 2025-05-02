#include <stdio.h>
#include <stdlib.h>

/*** BLOQUE I ***/

// Ejercicio 3: Funciones para arrays
void imprimir(double *v, int n)
{
    int i;
    printf("[ ");
    for(i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    printf("]\n");
}

double *concatenar(double *v1, double *v2, int n, int m)
{
    int i, j;
    double *res = (double *)malloc((n + m) * sizeof(double));
    for(i = 0; i < n; i++)
    {
        res[i] = v1[i];
    }
    
    for(j = 0; j < m; j++)
    {
        res[n + j] = v2[j];
    }
    
    return res;
}

/*** BLOQUE II ***/

// Ejercicio 7: Estructura enlazada
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} Estructura;

// Ejercicio 8: Función progresión aritmética
Estructura *progresion_aritmetica(int n, int b, int d)
{
    int i;
    int valor = b;
    Estructura *inicio = NULL;
    Estructura *actual = NULL;
    Estructura *nuevo;
    
    // Crear el primer nodo
    inicio = (Estructura *)malloc(sizeof(Estructura));
    inicio->dato = valor;
    inicio->siguiente = NULL;
    actual = inicio;
    
    // Crear el resto de nodos
    for(i = 1; i < n; i++)
    {
        valor += d;
        nuevo = (Estructura *)malloc(sizeof(Estructura));
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        actual->siguiente = nuevo;
        actual = nuevo;
    }
    
    return inicio;
}

/*** BLOQUE III ***/

// Ejercicio 12: Estructura para árboles
typedef struct nodoArbol {
    int dato;
    struct nodoArbol *hijoIzq;
    struct nodoArbol *hermanoDer;
} *Arbol;

// Ejercicio 13: Crear nodo del árbol
Arbol crea_arbol(int elem)
{
    Arbol nuevo = (Arbol)malloc(sizeof(struct nodoArbol));
    nuevo->dato = elem;
    nuevo->hijoIzq = NULL;
    nuevo->hermanoDer = NULL;
    return nuevo;
}

// Ejercicio 14: Funciones para el árbol
void inorden(Arbol a)
{
    if(a != NULL)
    {
        inorden(a->hijoIzq);
        printf("%d ", a->dato);
        inorden(a->hermanoDer);
    }
}

int suma_internos(Arbol a)
{
    if(a == NULL)
    {
        return 0;
    }
    
    if(a->hijoIzq != NULL)
    {
        return a->dato + suma_internos(a->hijoIzq) + suma_internos(a->hermanoDer);
    }
    else
    {
        return suma_internos(a->hermanoDer);
    }
}

void liberar(Arbol a)
{
    if(a != NULL)
    {
        liberar(a->hijoIzq);
        liberar(a->hermanoDer);
        free(a);
    }
}

int main()
{
    /*** BLOQUE I ***/
    
    // Ejercicio 1: Crear arrays dinámicos
    int n, m, i;
    double *v1, *v2, *v3;
    
    printf("Tamaño del primer array (n): ");
    scanf("%d", &n);
    
    printf("Tamaño del segundo array (m): ");
    scanf("%d", &m);
    
    v1 = (double *)malloc(n * sizeof(double));
    v2 = (double *)malloc(m * sizeof(double));
    
    // Ejercicio 2: Leer valores para los arrays
    printf("Elementos del primer array:\n");
    for(i = 0; i < n; i++)
    {
        printf("v1[%d]: ", i);
        scanf("%lf", &v1[i]);
    }
    
    printf("Elementos del segundo array:\n");
    for(i = 0; i < m; i++)
    {
        printf("v2[%d]: ", i);
        scanf("%lf", &v2[i]);
    }
    
    // Ejercicio 4: Concatenar arrays
    v3 = concatenar(v1, v2, n, m);
    
    // Ejercicio 5: Imprimir arrays
    printf("\nPrimer array (v1):\n");
    imprimir(v1, n);
    
    printf("Segundo array (v2):\n");
    imprimir(v2, m);
    
    printf("Array concatenado (v3):\n");
    imprimir(v3, n + m);
    
    // Ejercicio 6: Liberar arrays
    free(v1);
    free(v2);
    free(v3);
    
    /*** BLOQUE II ***/
    
    // Ejercicio 9: Crear progresión aritmética
    Estructura *lista = progresion_aritmetica(5, 5, 3);
    
    // Ejercicio 10: Imprimir estructura enlazada
    printf("\nEstructura enlazada:\n");
    Estructura *temp = lista;
    while(temp != NULL)
    {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
    
    // Ejercicio 11: Liberar estructura enlazada
    temp = lista;
    while(temp != NULL)
    {
        Estructura *siguiente = temp->siguiente;
        free(temp);
        temp = siguiente;
    }
    
    /*** BLOQUE III ***/
    
    // Ejercicio 13: Construir árbol de la Figura 2
    Arbol arbol = crea_arbol(1);
    arbol->hijoIzq = crea_arbol(2);
    arbol->hijoIzq->hermanoDer = crea_arbol(3);
    arbol->hijoIzq->hijoIzq = crea_arbol(4);
    arbol->hijoIzq->hijoIzq->hermanoDer = crea_arbol(5);
    arbol->hijoIzq->hermanoDer->hijoIzq = crea_arbol(17);
    arbol->hijoIzq->hermanoDer->hijoIzq->hermanoDer = crea_arbol(8);
    arbol->hijoIzq->hermanoDer->hijoIzq->hermanoDer->hermanoDer = crea_arbol(11);
    arbol->hijoIzq->hermanoDer->hijoIzq->hermanoDer->hermanoDer->hermanoDer = crea_arbol(14);
    
    // Ejercicio 15.1: Recorrido inorden
    printf("\nRecorrido inorden del árbol:\n");
    inorden(arbol);
    printf("\n");
    
    // Ejercicio 15.2: Suma de nodos internos
    printf("Suma de los nodos internos: %d\n", suma_internos(arbol));
    
    // Ejercicio 15.3: Liberar árbol
    liberar(arbol);
    
    return 0;
}