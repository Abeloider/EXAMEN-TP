#include <stdio.h>
#include <stdlib.h>

int * array (int n) {
    int *a = malloc(sizeof(int)*n);
    int cont =0;
    for (int i = n; n>0; n--) {
        a[cont] = i;
        cont++;
    }
    return a;
}

int main() {
    int n = 10;

    // Llamar a la función para obtener el array
    int *resultado = array(n);

    // Imprimir el array
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    // Liberar la memoria del array
    free(resultado);

    return 0;
}
