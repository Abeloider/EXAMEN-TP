#include "bombo.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM_B1 100000
#define TAM_B2 1807

int main() {

    int numero = 25340;

    Bombo b1 = BomboCrea(TAM_B1);
    Bombo b2 = BomboCrea(TAM_B2);
    for(int i=0; i<TAM_B1;i++) {
        BomboInserta(b1,i);
    }
        BomboInserta(b2,4000000);
        BomboInserta(b2,1250000);
        BomboInserta(b2,500000);
        BomboInserta(b2,200000);
        BomboInserta(b2,200000);

		srand(time(NULL));

        for(int i=0; i<8; i++){
            BomboInserta(b2,60000);
        }
         for(int i=0; i<1794; i++){
            BomboInserta(b2,1000);
        }
        typedef struct {
            int numero;
            int premio;
        }numero_premio;

        numero_premio sorteo[TAM_B2];


        for (int i = 0; i < TAM_B2; i++) {
            sorteo[i].numero = BomboExtrae(b1);
            sorteo[i].premio = BomboExtrae(b2);
        }

        BomboLibera(b1);
        BomboLibera(b2);

        FILE * fichero= fopen("premios.txt", "w");
        for(int i=0; i<TAM_B2; i++)
        {
            fprintf(fichero, "Numero: %d Premio %d\n",sorteo[i].numero, sorteo[i].premio);

        }

        fclose(fichero);
        printf("%d", numero);
		int i =0;
		int encontrado=0;
		while(i<TAM_B1 && !encontrado) {
			if (numero == sorteo [i].numero)
				encontrado = 1;
			i++;
		}
		if (encontrado) {
			printf(" Premio: %d\n", sorteo[i-1].premio);

		} else {
			printf(" Boleto no premiado.\n" );
		}

    // ponemos un blucle para encontrar el premio de 40000000

        int j = 0;
        printf("Números premiados:\n");
        while (j < TAM_B2) {
            if (sorteo[j].premio == 4000000) { // Si el premio es mayor que 0
                printf("Número: %d, Premio: %d\n", sorteo[j].numero, sorteo[j].premio);
        }
        j++;
    }

    return 0;


}


