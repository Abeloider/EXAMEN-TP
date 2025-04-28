#include <stdio.h>
#define STRING_SIZE 100

// imprimimos el array
void imprimir(int v[],int n) {
    for (int i=0; i<n; i++){
        printf("v[%d] = %d\n",n,v[i]);
    }
}

int buscarmatrix (int f, int c, int matrix[][c],int b)
{
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++) {
        if (matrix[i][j]==b)
        return 1;
        }
    }
    return 0;
}


// funcion para buscar el array
int buscar(int v[], int n, int a) {
     for (int i=0; i<n; i++){
        if (v[i]==a)
            return 1;
    }
    return 0;
}
// funcion para buscar el array segunda forma con while
int buscar2(int v[], int n, int a) {
     int encontrado = 0;
     int i =0;
     while (i<n && !encontrado){
        if (v[i]==a)
            encontrado = 1;
        i++;
     }
    return encontrado;
}

// funcion para buscar el array tercera forma
//int buscar3(int v[], int n, int a) {
//     int i =0;
//     while (i<n && !v[i]=a){ error
//        i++;
//     }
//    return i<n; // lo ha encontrado
//}

// REPETIMOS TODO CON FILAS Y CCOLUMNAS

// imprimimos filas y las columas
void imprimirfc(int f, int c, int matrix[][c]) {
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++) {
        printf("v[%d][%d] = %d\n",f,c,matrix[i][j]);
        }
    }
}

    // 4.4 CADENAS DE TEXTO CARACTERES

char iguales(char s1 [], char s2 []) {
    for(char i=0; i<s1; i++) {
        if (s1[i]!=s2[i])
            return 0;
    }
    return 1;
}

int main () {

// escribimos el array para buscar
    printf("Introduce tamano del array: ") ;
    int n;
    scanf("%d", &n);
    int v[n];

    for (int i=0; i<n; i++){
    printf("Introduce elemento %d del array ", i);
    scanf("%d", &v[i]);
    }

    // llamo imprimir
    imprimir (v,n);

    printf("Introduce un numero para buscar el array: ");
    int a;
    scanf("%d", &a);
    if (buscar(v,n,a))
        printf("Encontrado ...\n");
    else
        printf("No encontrado ...\n");

    //########### FILAS Y COLUMNAS ###############
    int f,c;
    printf("Introduce tamaño de la fila: ");
    scanf("%d", &f);
    printf("Introduce tamaño de la columna: ");
    scanf("%d", &c);

    // introduce los elemenos de fila y columnas
    int matrix[f][c];


    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++) {
            printf("v[%d][%d]=  ",i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    imprimirfc(f,c,matrix);

    printf("Introduce un numero para buscar el matrix: ");
    int b;
    scanf("%d", &b);
    if (buscarmatrix(f,c,matrix,b))
        printf("Encontrado ...\n");
    else
        printf("No encontrado ...\n");


    // 4.4 REALIZAR LOS SIGUIENTES NUEVOS PASOS CACACTERES

    char s1 [STRING_SIZE];
    char s2 [STRING_SIZE];

    printf("Introuce la cadena s1: ");
    scanf("%s", s1);

    printf("Introuce la cadena s2: ");
    scanf("%s", s2);

    if (iguales(s1, s2)) {
    printf("SON IGUALES");
    }
    else {
    printf("SON DISTINTOS");
    }



    return 0;
}

