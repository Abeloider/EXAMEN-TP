#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------- Ejercicio 1: Subarray ---------------------- */
/**
 * Devuelve un subarray del array 'v' entre los índices 'i' y 'j'.
 * @param v Array original
 * @param i Índice inicial (debe ser >= 0)
 * @param j Índice final (debe ser >= i y < n)
 * @param n Tamaño del array original
 * @return Puntero al subarray creado dinámicamente o NULL si hay error
 */
 
float *subarray(float v[], int i, int j, int n) {
    // Validar parámetros de entrada
    if (i < 0 || j < i || j >= n) return NULL;
    
    // Calcular longitud del subarray
    int longitud = j - i + 1;
    
    // Reservar memoria para el subarray
    float *sub = (float *)malloc(longitud * sizeof(float));
    if (sub == NULL) return NULL;
    
    // Copiar elementos del array original al subarray
    for (int k = 0; k < longitud; k++) {
        sub[k] = v[i + k];
    }
    
    return sub;
}

/* --------------- Ejercicio 2: Estructura enlazada lineal --------------- */
typedef struct Nodo {
    int elemento;
    struct Nodo *sig;
} *Estructura;

/* -------------------- Ejercicio 3: Función mayores -------------------- */
/**
 * Crea una nueva estructura enlazada con elementos mayores que 'a'
 * @param e Estructura original
 * @param a Valor umbral
 * @return Nueva estructura con elementos mayores que 'a'
 */
Estructura mayores(Estructura e, int a) {
    Estructura nueva_lista = NULL;   // Cabeza de la nueva lista
    Estructura ultimo = NULL;        // Último nodo de la nueva lista
    
    while (e != NULL) {
        if (e->elemento > a) {
            // Crear nuevo nodo
            Estructura nuevo = malloc(sizeof(struct Nodo));
            nuevo->elemento = e->elemento;
            nuevo->sig = NULL;
            
            // Enlazar en la nueva lista
            if (nueva_lista == NULL) {
                nueva_lista = nuevo;
                ultimo = nuevo;
            } else {
                ultimo->sig = nuevo;
                ultimo = nuevo;
            }
        }
        e = e->sig;
    }
    return nueva_lista;
}

/* ----------------- Ejercicio 4: Función recursiva iguales ---------------- */
/**
 * Cuenta caracteres iguales a 'c' en la cadena 's'
 * @param s Cadena de caracteres
 * @param c Carácter a buscar
 * @return Número de ocurrencias
 */
int iguales(char *s, char c) {
    // Caso base: cadena vacía
    if (*s == '\0') return 0;
    
    // Caso recursivo: sumar 1 si coincide + procesar resto
    return (*s == c) + iguales(s + 1, c);
}

/* -------------- Ejercicio 5: Árbol Binario de Búsqueda (ABB) ------------- */
typedef struct NodoABB {
    int elemento;
    struct NodoABB *izq;  // Subárbol izquierdo
    struct NodoABB *der;   // Subárbol derecho
} *ABB;

/* ---------------- Ejercicio 6: Impresión orden decreciente --------------- */
/**
 * Imprime elementos del ABB en orden decreciente
 * @param a Árbol binario de búsqueda
 */
void imprime_ord_dec(ABB a) {
    if (a != NULL) {
        imprime_ord_dec(a->der);   // Recorre subárbol derecho primero
        printf("%d ", a->elemento); // Imprime el valor actual
        imprime_ord_dec(a->izq);   // Recorre subárbol izquierdo después
    }
}

/* --------------------------- Ejemplo de uso --------------------------- */
int main() {
    // --- Ejemplo subarray ---
    float arr[] = {3.5, 7.2, 4.8, 2.9};
    float *sub = subarray(arr, 1, 2, 4);
    printf("Subarray [1-2]: ");
    for (int i = 0; i < 2; i++) printf("%.1f ", sub[i]); // 7.2 4.8
    free(sub);
    printf("\n\n");

    // --- Ejemplo estructura enlazada ---
    // Crear lista: 5 -> 3 -> 20 -> -5
    Estructura lista = malloc(sizeof(struct Nodo));
    lista->elemento = 5;
    lista->sig = malloc(sizeof(struct Nodo));
    lista->sig->elemento = 3;
    lista->sig->sig = malloc(sizeof(struct Nodo));
    lista->sig->sig->elemento = 20;
    lista->sig->sig->sig = malloc(sizeof(struct Nodo));
    lista->sig->sig->sig->elemento = -5;
    lista->sig->sig->sig->sig = NULL;

    // Filtrar mayores que 3
    Estructura filtrados = mayores(lista, 3);
    printf("Elementos > 3: ");
    Estructura actual = filtrados;
    while (actual != NULL) {
        printf("%d ", actual->elemento); // 5 20
        actual = actual->sig;
    }
    printf("\n\n");

    // --- Ejemplo iguales ---
    char cadena[] = "programacion";
    printf("Número de 'a' en '%s': %d\n\n", cadena, iguales(cadena, 'a')); // 2

    // --- Ejemplo ABB ---
    // Crear árbol:
    //       10
    //      /  \
    //     5    15
    ABB arbol = malloc(sizeof(struct NodoABB));
    arbol->elemento = 10;
    arbol->izq = malloc(sizeof(struct NodoABB));
    arbol->izq->elemento = 5;
    arbol->izq->izq = arbol->izq->der = NULL;
    arbol->der = malloc(sizeof(struct NodoABB));
    arbol->der->elemento = 15;
    arbol->der->izq = arbol->der->der = NULL;

    printf("ABB en orden decreciente: ");
    imprime_ord_dec(arbol); // 15 10 5
    printf("\n");

    // Liberar memoria
    // (Implementar función de liberación para estructuras y árboles)

    return 0;
}