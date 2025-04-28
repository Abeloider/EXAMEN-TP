#include <stdio.h>
#include <math.h>
#include <windows.h>


#define printf __mingw_printf  // si ponemos printf entonces este lo que hace es sustituir por mingw que es mas compatible




const double d = 149.6E6; // variable global


int main()
{
// – Leer una velocidad desde teclado, en Km/h, y calcular e imprimir el tiempo de llegada
// al Sol en segundos, minutos, horas, días y años.


//– Calcular e imprimir el tiempo transcurrido, distinguiendo los años, días, horas, minutos
//y segundos.



//– Comprobar desbordamiento según el tipo elegido para representar el tiempo así como
//la velocidad de viaje.


    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    double v;
    int res;
    do {
        printf("Introduce velocidad en Km/h: ");
        res = scanf("%lf", &v); // lf = long float, & accede a la variable
        while (getchar()!= '\n');// limpiamos el buffer
        if (res!=1 || v<=0)
            printf("Formato numérico incorrecto\n");

    }while (res!=1 || v<=0);

    printf("Velocidad: %f\n", v); // lo imprimimos como f
    printf("Distancia: %f\n", d);

    long double horas =(long double)d/(long double)v;
    long double dias =(long double)horas/24; // 24 se convierte en double
    long double anos =(long double) dias/365;
    long double minutos =(long double)horas*60;
    long double segundos =(long double) minutos*60;

    printf("Segundos: %Lg\n", segundos);
     printf("minutos: %Lg\n", minutos);
      printf("horas: %Lg\n", horas);
       printf("dias: %Lg\n", dias);
        printf("anos: %Lg\n", anos);

    long double a,d,h,m,s;
    a = floorl (anos); // hacemos la parte entera para pasarlo a long doble
    d = floorl((anos - floorl (anos)) * 365) ;
    h = floorl((dias - floorl (dias)) * 24) ;
    m = floorl((minutos - floorl (minutos)) * 60) ;
    s = floorl((segundos - floorl (segundos)) * 60) ;


    printf("%Lg anos, %Lg dias, %Lg horas, %Lg minutos, %Lg segundos.\n ",a,d,h,m,s);
    // d=1; sale error ya que la de es una constante y esta no se puede modificar
return 0;

}
