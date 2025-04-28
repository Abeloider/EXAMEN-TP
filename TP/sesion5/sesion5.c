#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 100
//cambiamos los arrays para luego poder aplicar un free(v)

// imprimimos el array
void imprimir(int * v,int n) { //
    for (int i=0; i<n; i++){
        printf("v[%d] = %d\n",n,*(v+i)); //
    }
}

int buscarmatrix (int f, int c, int ** matrix,int b)
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
void imprimirfc(int f, int c, int ** matrix) {
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++) {
        printf("v[%d][%d] = %d\n",f,c,matrix[i][j]);
        }
    }
}

    // 4.4 CADENAS DE TEXTO CARACTERES

char iguales(char * s1, char * s2) {
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
    //declara un array v de enteros de tamaño n
    int * v = malloc(sizeof(int)*n); //

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



    //realloc

    printf("Introduce tamano del array: ") ;
    int nuevo;
    scanf("%d", &nuevo);
    v = realloc(v,sizeof(int)*nuevo);

    for (int i=n; i<nuevo;i++ )
    {
        printf("Introduce elemeto %d: ", i);
        printf("%d", &v[i]);
    }
    imprimir(v,nuevo);
    free(v);





    //########### FILAS Y COLUMNAS ###############
    int f,c;
    printf("Introduce tamaño de la fila: ");
    scanf("%d", &f);
    printf("Introduce tamaño de la columna: ");
    scanf("%d", &c);

    // introduce los elemenos de FILA y COLUMNA
    int ** matrix = malloc(f*sizeof(int *)); //
    // calculamos el numero de filas
    for(int i=0; i<f; i++) {
        matrix [i] = malloc(c*sizeof(int));
    }

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


    // INTRODUCE EL NUEVO NUMERO DE FILAS////////////////////////////////////////////
    printf ("Introduce nuevo numero de filas: ");
    int nuevo_f;
    scanf("%d", &nuevo_f);

    // llevo filas si nuevo filas < fila

    for (int i=nuevo_f; i<f;i++)
        free (matrix[i]);
        matrix = realloc(matrix,nuevo_f*sizeof(int *));
    //asigno memoria a las nuevas lifas cuando filas < nuevo filas
    for (int i=f; i < nuevo_f; i++)
        matrix[i] = calloc(c,sizeof(int));


    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++) {
            printf("v[%d][%d]=  ",i, j);
            scanf("%d", &matrix[i][j]);
        }
    }


    // INTRODUCE EL NUMERO NUEVO DE COLUMAS //////////////////////////////////7
    printf ("Introduce nuevo numero de columnas: ");
    int nuevo_c;
    scanf("%d", &nuevo_c);

    for (int i=nuevo_c; i<c;i++)
        free (matrix[i]);
        matrix = realloc(matrix,nuevo_c*sizeof(int *));
    //asigno memoria a las nuevas lifas cuando filas < nuevo filas
    for (int i=c; i < nuevo_c; i++)
        matrix[i] = calloc(c,sizeof(int));


    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++) {
            printf("v[%d][%d]=  ",i, j);
            scanf("%d", &matrix[i][j]);
        }
    }



    imprimirfc(nuevo_f ,c ,matrix);

    for(int i=0; i<f ;i++)
        free(matrix[i]);
        free(matrix); // si lo haces con [] no funciona


    // 4.4 REALIZAR LOS SIGUIENTES NUEVOS PASOS CACACTERES

    char * s1 = malloc(STRING_SIZE*sizeof(char));
    printf("Introuce la cadena s1: ");
    scanf("%s", s1);

    char * s2 = malloc(STRING_SIZE*sizeof(char));
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

