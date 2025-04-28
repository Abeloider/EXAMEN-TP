#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){

    printf("Hola, como te llamas? ");
    char nombre[100]; // caracteres
    scanf("%s", nombre); // s es string si fuera numero entonces seria d, f, lf


    printf("Encantado de conocerte %s.\n" , nombre);
    printf("Estoy pensando en un numero del 1 al 10.\n");
    printf("A ver si lo averiguas...\n");
    srand (time(NULL));
    int miNumero; // [a,b] = a + rand()%(b-a+1) // puede sailr en el examen
    int numero = 1 + rand()%10;
    int nIntentos;

    do {
        printf("El numero es: ");
        scanf ("%d", &miNumero) ;
        while (getchar()!= '\n'); // limpia el buffer para que la consola no se cierre
        if (numero<miNumero) {
            scanf("El nuemero es menor.\n");
        }else if (numero>miNumero) {
            scanf("El nuemero es mayor.\n");
            }
            nIntentos ++;
        }while (numero!=miNumero);

    printf("Lo has averiguado en %d intentos.\n", nIntentos);

    printf("Pulsa una tecla para continuar ");
    getchar();


    return 0;
}
