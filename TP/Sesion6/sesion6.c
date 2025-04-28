#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <windows.h>

int escribir_fichero(const char * nombre) {
    FILE * f = fopen(nombre,"w"); // ab<rimos y escribimos
    if (f==NULL)
        return -1;
    char c;
    do {
        //c=getchar();
        c = getc(stdin);
        if (c != EOF) //  if (!feof(stdin)) //
            putc(c,f);
    }
    while(c != EOF);
    fclose(f);
    return 0;
}

int caracteres_fichero(const char * nombre) {
    FILE * f = fopen(nombre,"r"); // abrimos y escribimos
    if (f==NULL)
        return -1;
    char c;
    int cont =0;
    do {
        c = getc(f);
        if (!feof(f) && c!='\n') // no contamos los espacios
            cont++;
    }
    while(!feof(f));
    fclose(f);
    return cont;
}

int palabra_fichero(const char * nombre) {
    FILE * f = fopen(nombre,"r");
    if (f==NULL)
        return -1;
    int cont;
    char palabra [100];
    do {
        fscanf(f,"%s", palabra);
        cont++;
    } while(!feof(f));
    fclose(f);
    return cont;
}


int main () {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    int m;

    char nombre[] = "texto.txt";
    printf("Introduce un texto (RETURN ^z RETURN para terminar): \n");

    if (escribir_fichero(nombre)!=0) {
        fprintf(stderr, "No se puede abrir el archivo %s\n", nombre);
    }
    system("pause");


    int n_car = caracteres_fichero(nombre);
    if (n_car != -1) {
        printf("El número de caracteres en el archivo es: %d\n", n_car);
    }

    int n_pal = palabra_fichero(nombre) ;
    if (n_pal != -1) {
        printf("El número de palabras es: %d\n", n_pal);
    }


    if (escribir_fichero(nombre)==-1) {
        fprintf(stderr, "No se puede abrir el archivo %s\n", nombre);
        fprintf(stderr, "Error número %i\n", errno);
        fprintf(stderr, "Descripción: %s\n", strerror(errno));
    }
return 0;
}
