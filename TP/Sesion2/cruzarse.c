#include <stdio.h>
#include <math.h>
#include <windows.h>
#define printf __mingw_printf

const double d = 384.4E3;

int main()
{

    double v1;
    double v2;
    int res1;
    int res2;

    do {
        printf("Introduce la primera velocidad: " );
        res1 = scanf("%lf", &v1);
        printf("Introduce la segunda velocidad ") ;
        res2 = scanf("%lf", &v2);
        while (getchar()!= '\n');// limpiamos el buffer
        if (res1+res2==0)
            return 1;
    } while (res1+res2==0);

    printf("Velocidad1 es: %f\n", v1);
    printf("Velocidad2 es: %f\n", v2);

    double total = (d / v1+v2);

    printf("El tiempo que tarda en %g \n", total);

return 0;
}
