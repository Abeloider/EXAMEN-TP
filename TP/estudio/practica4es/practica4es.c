#include <stdio.h>
#define STRING_SIZE 100

void imprimirArray (int v[]int n) {
    for(int i=1; i<n; i++) {
        printf("v[%d] = %d\n",n , v[i]);

    }
}


int main(){

  // escribimos el array para buscar
    printf("Introduce tamano del array: ") ;
    int n;
    scanf("%d", &n);
    int v[n];

    for (int i=0; i<n; i++){
    printf("Introduce elemento %d del array ", i);
    scanf("%d", &v[i]);
    }
    imprimirArray(v,n);

    return 0;
}
