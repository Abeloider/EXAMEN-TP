#include <stdio.h>
#include <math.h>
#include <windows.h>
#define printf __mingw_printf

const double d = 384.4E3

int main() {

    double v1;
    double v2;
    int res;

    do {
        printf("Introduce la primera velocidad: " );
        res = scanf("%lf", &v1);
        printf("Introduce la segunda velocidad ") ;
        res = scanf("%lf", &v2);
        while (getchar()!= '\n');// limpiamos el buffer
        if (res==0)
            return 1;
    } while (res==0);

    printf("Velocidad: %f\n", v1);
    printf("Distancia: %f\n", v2);




return 0;
}
