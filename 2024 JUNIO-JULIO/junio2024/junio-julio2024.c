#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/* EJERCICIO 1

1. Implementar en C la siguiente función (3 puntos):

// Devuelve un array con los elementos mayores que a en el array v de
// tamaño n.
float * mayores (float v[], int n, float a)

Realizar los siguientes pasos para implementar la función:
- Contar el número m de elementos mayores que a en el array v.
- Construir, mediante asignación dinámica de memoria (malloc)
    un array nuevo de m elementos.
- Asignar los elementos del array v mayores que a en posiciones
    consecutivas del array nuevo.
- Devolver el array nuevo.

*/

float * mayores(float v[], int n, float a) {
    // contar el numero m de elementos mayores que a
    int m;
    for (int i=0; i<n; i++) {
        if (v [i]>0) {
            m++;
        }
    }
    if (m==0) {
        return NULL;
    }

    // Consturir mediante asignacio ndinamico malloc de m elementos
    float * array_nuevo = malloc(sizeof(float)*m);
    if (array_nuevo==NULL) {
        return NULL;
    }

    // Asigar los elementos del arrat v mayores que a
    int guardado=0;
    for (int i=0; i<n; i++) {
        if (v[i]>=a) {
            array_nuevo[guardado] = v[i];

        }
        guardado++;
    }
    return array_nuevo;
}
// float imprimimos resultado

void imprimir_array(const char* nombre, float arr[], int size) {
    printf("%s: [", nombre);
    if (arr == NULL || size <= 0) {
        printf(" (vacío o inválido) ");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%.2f", arr[i]);
            if (i < size - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

 // EJERCICIO 2
typedef struct EstructuraRep * Estructura;
struct EstructuraRep{
    int elem;
    Estructura sig; // que es lo mismo que: struct EstructuraRep *sig;
};

// EJERICICIO 3

// suprime los elementos mayores que a de las estrcutura enlazada e.

Estructura crear_nodo_lista(int valor) {
    Estructura nuevo = malloc(sizeof(struct EstructuraRep));
    if (nuevo != NULL) {
        nuevo->elem = valor;
        nuevo->sig = NULL;
    } else {
        perror("Error reservando memoria en crear_nodo_lista");
    }
    return nuevo;
}

void suprime_mayores(Estructura e,int a) {
    while ((e->sig!=NULL) && (e->sig->elem<a)) {
        e=e->sig;
    }
    Estructura eliminado = e->sig; // guardamos el elemento a eliminar
    e->sig = eliminado->sig; // lo eliminamo de la lista
    free(eliminado);
}

/* deepseek
void suprime_mayores(Estructura *e, int a) {
    struct Nodo *actual = *e;
    struct Nodo *anterior = NULL;

    while (actual != NULL) {
        if (actual->elemento > a) {
            if (anterior == NULL) { // Eliminar el primer nodo
                *e = actual->sig;
                free(actual);
                actual = *e;
            } else { // Eliminar nodo intermedio o final
                anterior->sig = actual->sig;
                free(actual);
                actual = anterior->sig;
            }
        } else { // Avanzar
            anterior = actual;
            actual = actual->sig;
        }
    }
}
*/
void imprimir_lista(const char* mensaje, Estructura e) {
    printf("%s: ", mensaje);
    if (e == NULL) {
        printf("[Lista vacía]\n");
        return;
    }
    Estructura actual = e;
    while (actual != NULL) {
        printf("%d -> ", actual->elem);
        actual = actual->sig;
    }
    printf("NULL\n");
}

void liberar_lista(Estructura head) {
    Estructura actual = head;
    while (actual != NULL) {
        Estructura siguiente = actual->sig;
        // printf("Liberando nodo lista: %d\n", actual->elem); // Descomentar para depurar
        free(actual);
        actual = siguiente;
    }
}


// EJERCICIO 4
// decalra en C un tipo de datos, de nombre ArbolBinario, para representar
// arboles binarios de numeros enteros
typedef int Elemento;
struct Nodo
{
    Elemento elem;
    struct Nodo * hijoIzquierdo, * hijoDerecho;
};
typedef struct Nodo * ArbolBinario;



ArbolBinario crea_arbol(Elemento elem)
{
    ArbolBinario nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = elem;
    nuevo->hijoIzquierdo = NULL;
    nuevo->hijoDerecho = NULL;
    return nuevo;
}

void libera_arbol(ArbolBinario a) // postorden
{
    if (a == NULL) return; // caso base, si no hay nada que liberar no se hace nada
    libera_arbol(a->hijoIzquierdo); // liberamos el hijo izquierdo
    libera_arbol(a->hijoDerecho); // liberamos el hijo derecho
    free(a); // liberamos el nodo actual
}


// EJERCICIO 5

// Devuelve 1 (cierto) si el elemento e existe en el árbol binario a,
// y 0 (falso) en caso contrario.

int busca_nodo (ArbolBinario a, int e) {
    if (a == NULL) return 0;
    if (a->elem == e) return 1;
    return (busca_nodo(a->hijoIzquierdo,e) ||
            busca_nodo(a->hijoDerecho,e)) ;
}




int main (){

  printf("### INICIO EJERCICIO 1: Array Mayores ###\n");
    float v[] = {1.5, 8.0, 3.2, 4.5, 6.7, 2.1, 5.0};
    int n = sizeof(v) / sizeof(v[0]);
    float a_float = 3.0;

    imprimir_array("Array original (v)", v, n);
    printf("Valor de a: %.2f\n", a_float);

    // Calcular m (tamaño esperado del resultado) basado en la *descripción* (> a)
    // aunque la función 'mayores' proporcionada tenga bugs en su cálculo y llenado.
    int m_esperado = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > a_float) { // Usando la condición correcta de la descripción
            m_esperado++;
        }
    }
    printf("Número esperado de elementos mayores que %.2f: %d\n", a_float, m_esperado);

    // Llamar a la función 'mayores' tal como fue proporcionada
    float *resultado = mayores(v, n, a_float);

    // Imprimir el resultado. Usamos m_esperado para el tamaño, aunque el contenido
    // del array 'resultado' puede ser incorrecto debido a los bugs en 'mayores'.
    if (resultado != NULL) {
        printf("Resultado de 'mayores' (puede ser incorrecto debido a bugs):\n");
        // Imprimimos usando m_esperado, pero advertimos que el contenido puede ser erróneo
        imprimir_array("Resultado", resultado, m_esperado);
        free(resultado); // Liberar memoria del array resultado
        resultado = NULL;
    } else {
         printf("La función 'mayores' devolvió NULL.\n");
    }
    printf("### FIN EJERCICIO 1 ###\n\n");

    // -----------------------------------------------------

    printf("### INICIO EJERCICIOS 2 y 3: Lista Enlazada ###\n");
    // Crear una lista de ejemplo: 5 -> 15 -> 8 -> 2 -> 20 -> 12 -> NULL
    Estructura miLista = crear_nodo_lista(5);
    if (miLista) miLista->sig = crear_nodo_lista(15);
    if (miLista && miLista->sig) miLista->sig->sig = crear_nodo_lista(8);
    if (miLista && miLista->sig && miLista->sig->sig) miLista->sig->sig->sig = crear_nodo_lista(2);
    // Añadir más nodos si se desea...

    int valor_a_lista = 10;
    imprimir_lista("Lista original", miLista);
    printf("Valor a superar para borrar (lista): %d\n", valor_a_lista);
    printf("Llamando a 'suprime_mayores' (versión con bugs)...\n");

    // Llamar a suprime_mayores tal como está definida (con sus limitaciones)
    // No se puede pasar &miLista porque la función no espera Estructura*
    // Si el primer nodo (5) necesitara borrarse, esta llamada no podría hacerlo.
    // Solo intentará borrar el primer nodo encontrado cuyo valor sea >= 10 (el 15 en este caso).
    suprime_mayores(miLista, valor_a_lista);

    printf("Resultado de 'suprime_mayores' (puede ser incorrecto o incompleto):\n");
    imprimir_lista("Lista modificada", miLista);

    // Liberar memoria de la lista restante
    printf("Liberando lista restante...\n");
    liberar_lista(miLista);
    miLista = NULL;
    printf("### FIN EJERCICIOS 2 y 3 ###\n\n");

    // -----------------------------------------------------

    printf("### INICIO EJERCICIOS 4 y 5: Árbol Binario ###\n");
    // Crear un árbol de ejemplo
    //       10
    //      /  \
    //     5    15
    ArbolBinario miArbol = crea_arbol(10);
    if (miArbol) miArbol->hijoIzquierdo = crea_arbol(5);
    if (miArbol) miArbol->hijoDerecho = crea_arbol(15);
    // Añadir más nodos si se desea...

    printf("Árbol creado (10 raiz, izq 5, der 15)\n");

    // Probar busca_nodo
    int elemento_buscar_1 = 5;
    int elemento_buscar_2 = 99;

    printf("Buscando %d en el árbol... Resultado: %d (1=encontrado, 0=no encontrado)\n",
           elemento_buscar_1, busca_nodo(miArbol, elemento_buscar_1));

    printf("Buscando %d en el árbol... Resultado: %d (1=encontrado, 0=no encontrado)\n",
           elemento_buscar_2, busca_nodo(miArbol, elemento_buscar_2));

    // Liberar memoria del árbol
    printf("Liberando árbol...\n");
    libera_arbol(miArbol);
    miArbol = NULL;
    printf("### FIN EJERCICIOS 4 y 5 ###\n\n");

    printf("Programa terminado.\n");
    return 0;
}

