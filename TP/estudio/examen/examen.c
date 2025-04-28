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


int *array(int n) {
    int *a = malloc(sizeof(int) * n);
    int cont = 0;
    for (int i = n; n > 0; n--) { // Bucle con error
        a[cont] = i; // El valor de "i" no cambia
        cont++;
    }
    return a;
}

int main() {
    int n = 5; // Ejemplo con n = 5

    int *resultado = array(n);

    printf("Array generado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultado[i]);
    }

    free(resultado);
    return 0;
}
