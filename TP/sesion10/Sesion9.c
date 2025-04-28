#include "Cola.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define N 5

/**

 \file sesion9.c
\mainpage aplicacion que simiula lagestioin de paciente en un hospital
*/

/**
\brief programma principal:
consta de 2 fases
Fase 1: los pacientes cogen cita
Fase 2: se simula aleatoriamente las gestion de todos los pacientes
*/

int main()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    Elemento paciente;
    int especialidad;
    char especialidades[N][17] = {"Medicina general", "Pediatría", "Reumatología", "Medicina interna", "Enfermería"};
    Cola * consultorio = malloc(sizeof(Cola)*N);
    for (int i=0; i<N; i++)
        consultorio[i] = crea();
    int pacientes = 0;
    do
    {
        printf("Introduce especialidad (1 a 5): ");
        scanf("%d",&especialidad);
        if (especialidad!=0)
        {
            printf("Introduce nombre: ");
            scanf("%s",paciente.nombre);
            printf("Introduce DNI: ");
            scanf("%s",paciente.DNI);
            inserta(consultorio[especialidad-1],paciente);
            pacientes++;
        }
    }
    while(especialidad!=0);
    srand(time(NULL));
    while (pacientes>0)
    {
        int cola_aleatoria = rand()%N;
        while (vacia(consultorio[cola_aleatoria]))
            cola_aleatoria = (cola_aleatoria+1)%N;
        paciente = recupera(consultorio[cola_aleatoria]);
        printf("%s %s Consulta %d %s\n", paciente.nombre,paciente.DNI,cola_aleatoria+1,especialidades[cola_aleatoria]);
        suprime(consultorio[cola_aleatoria]);
        pacientes--;
    }
    for (int i=0; i<N; i++)
        libera(consultorio[i]);
    free(consultorio);
    return 0;
}
