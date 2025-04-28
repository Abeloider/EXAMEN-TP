#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void despejarEntrada(void){
    while (getchar() != '\n'); // comparamos el caracter con el salto de linea
}

/*
        VERSION SIMPLIFICADA
    int cod_error = scanf ("%d", n);
    if (cod_error!=1)
        despejarEntrada();
        return 1;
    return 0;
*/

int leer_entero(int * n) { // con el * pasamos la direccion de n en el segmento de la funcion main
    int dato;
    int cod_error = scanf ("%d", &dato);
    despejarEntrada();
    if (cod_error!=1)
        return 1;
    *n= dato; // tenemos que poner un * en n ya que si no lo pusieramos este estaria igualando una direccion a un int
    return 0;
}

int leer_entero_mayorIgual(int * n, int a) {
    int cod_error = scanf ("%d", n);
    despejarEntrada();
    if (cod_error!=1)
        return 1;
    if (*n<a)
        return 2;
    return 0;
}

int leer_entero_rango(int * n, int a, int b) {
    int cod_error = scanf ("%d", n);
    despejarEntrada();
    if (cod_error!=1) // Error corregido: antes era "!=0"
        return 1;
    if (*n<a)
        return 2;
    if (*n>b)
        return 3;
    return 0;
}

int entero_aleatorio_rango(int a, int b) {
    return rand() %(b-a+1) +a;
}

void pausa (void) {
    printf("Presiona una tecla para continuar... \n");
    getchar();
}

int leer_real(double * n) {
    double dato; // Corregido de int a double
    int cod_error = scanf ("%lf", &dato); // Corregido de %d a %lf
    despejarEntrada();
    if (cod_error!=1)
        return 1;
    *n= dato; // tenemos que poner un * en n ya que si no lo pusieramos este estaria igualando una direccion a un int
    return 0;
}

double real_aleatorio_rango(double a, double b){
    return ((double)rand() / RAND_MAX) * (b - a) + a;
}

int main()
{
    int n; // valor minimo de entrada
    int cod_error;

    do {    //El tratamiento de error: AVISO AL USUARIO Y VUELVO A PEDIRLE EL DATO
        printf("Introduce un numero entero: ");
        cod_error = leer_entero(&n); // aqui coge la direccion de la n que hemos puesto anteriormente con el *
        if (cod_error==1)
            printf("Formato de numero incorrecto. \n");
    } while (cod_error!=0) ;

    int m;
    do {    //El tratamiento de error: AVISO AL USUARIO Y VUELVO A PEDIRLE EL DATO
        printf("Introduce un numero entero mayor o igual a %d: ", n);
        cod_error = leer_entero_mayorIgual(&m, n); // aqui coge la direccion de la n que hemos puesto anteriormente con el *
        if (cod_error==1)
            printf("Formato de numero incorrecto. \n");
        else if (cod_error==2)
            printf("Rango incorrecto. \n");
    } while (cod_error!=0) ;

    int r;
    do { //Tratamiento de error: AVISO AL USUARIO Y VUELVO A PEDIRLE EL DATO
        printf("Introduce un numero entero en el rango [%d, %d]: ", n, m);
        cod_error = leer_entero_rango(&r, n, m); // aqui coge la direccion de la n que hemos puesto anteriormente con el *
        if (cod_error==1)
            printf("Formato de numero incorrecto. \n");
        else if (cod_error==2|| cod_error==3)
            printf("Rango incorrecto. \n");
    } while (cod_error!=0);

    printf("Dato correcto: %d\n", r);

    srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios
    printf("Entero aleatorio en el rango [%d, %d]: %d\n", n, m, entero_aleatorio_rango(n, m));

    pausa();
    return EXIT_SUCCESS; // es lo mismo que si ponemos 0;
}
