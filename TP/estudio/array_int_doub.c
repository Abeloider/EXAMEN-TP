#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**Como array de enteros**/
/*Este es el t�pico, un vector de enteros que realize una operaci�n y que,
al realizarla la retorne al final de la funci�n, la parte est�tica es la de asignar memoria, el bucle y
la retornada de v, las partes que deben ser modificadas ser�n las siguientes marcadas en el siguiente ejemplo.
Ultilizar� el siguiente enunciado:
Una función que recibe como parámetro un entero mayor o igual que 2 y devuelve un vector
de enteros dónde: a_1 = 1 ; a_2 = 3 ; a_n = n*((a_n-1)-(a_n-2)) para todo n>2*/

int *vector_enteros (int n) {
    int *v = malloc(sizeof(int)*n);
    v[0] = 1;
    v[1] = 3;
    for (int i = 2; i < n; i++) {
        v[i] = i * ((v[i-1])-(v[i-2]))
    }
    return v;
}
/*
Voy a usar de ejemplo lo siguiente:
Una funci�n que recibe como un par�metro un entero mayor o igual que 1 yu devuelve un vector
de reales donde, a_1=(i-1)/i. Por ejemplo, si llamamos a esta funci�n con un valor 5 devolver�a un vector
con los elementos 0, 0.5, 0.67, 0.75, 0.8*/
double *vector_reales(int n) {
    int *v = malloc(sizeof(double)*n); // se utiiliza para selecianar el tamaño de memoria
    v[0] =1;
    for (int i=2; i>=n;i++) {
        v[i] = (double)(i-1.0)/(double)i;
    }
    free(v);
    return 0;
}

/**POSIBLES FUNCIONES PARA EL EJERCICIO 2**/
/*Reitero, como hemos visto en los simulacros, en el segundo ejercicio SIEMPRE se pide definir un
tipo estructura enlazada, esta s� que no varia pr�cticamente nada en su sint�xis. Se puede directamente
copiar y pegar de las diapositivas*/

typedef struct Nodo * NodoPtr;          //Esta es la propia estructura que usaremos para referirnos al struct, no var�a
struct Nodo                             //El tipo estructura creado, no var�a
{
    int elem;                        //Esto es del tipo que es la estructura, var�a en el tipo de datos que te puedan pedir (ej: double o int)
    struct Nodo * sig;                  //Esto es el apuntador a nuestra siguiente estructura, no var�a
};



/**POSIBLES FUNCIONES PARA EL EJERCICIO 3**/
/*Esta funci�n por lo general te pide usar el ejercicio anterior, a lo que me refiero es que usemos una estructura enlazada
para representar algo u ordenar ese algo*/
/*En los simulacros esta funci�n s� que puede variar un poco dependiendo de lo que se pida, aqu� voy a poner los tipos
vistos en simulacros y diapositivas*/
/**Que te pidan una estructura que represente un vector en el MISMO ORDEN**/
/*Esta es sencilla, en su mayoria ser� un copy paste, por no decir entera
Usar� el siguiente ejemplo:
Una funci�n que recibe como par�metro un vector de enteros y un entero que indica el n�mero de elementos
del vector, y devuelve una estructura enlazada de enteros que contiene los elementos del vector del mismo orden.
Por ejemplo, si llamamos a esta funci�n con el vector obtenido en el apartado 1, devolver�a una estructura con los elementos 1,3,6,12,30*/


NodoPtr vector_enteros(int * v, int n){ // vector de enteros

    NodoPtr e = malloc(sizeof(struct Nodo));   //Cabecera de estructura, no var�a
    NodoPtr aux = e;                           //Apuntador auxiliar, no var�a


    for (int i=0; i<=n; i++) {
        aux -> sig = malloc(sizeof(struct Nodo));
        aux -> sig -> elem = v[i];
        aux = aux -> sig;
    }

}


/**Que te pidan una estructura que represente un vector en ORDEN CONTRARIO**/
/*Es pr�cticamente igual que la anterior, solo que esta lo que hace es ponerlo en orden contrario,
vamos a usar el mismo ejercicio de ejemplo anterior:*/



NodoPtr VectorEnteros(int *v,int n)     //Declaramos un tipo estructura y le pasamos por par�metros un array de enteros y un entero, no var�a
{
    NodoPtr e = malloc(sizeof(struct Nodo));     //Cabecera de estructura, no var�a
    NodoPtr aux = e;                             //Apuntador auxiliar, no var�a
    for(int i = n-1; i>=0; i--)                  //Condiciones del bucle, puede variar dependiando si nos lo piden en el orden act�al o en el orden contrario (lo veremos desp�es)
    {
        aux->sig = malloc(sizeof(struct Nodo));  //Asignamos el tama�o al nodo siguiente (vag�n que enganchemos, le proporcionamos un espacio)
        aux->sig->elem = v[i];                   //Accedemos dentro de la estructura al elemento y le asignamos un espacio del array(metemos equipaje/pasajeros al vag�n)
        aux = aux->sig;                          //Ahora aux apuntar� al siguiente nodo que creemos y as� iterativamente se repiten estos pasos hasta llenar el tama�o proporcionado en "n"
    }
    aux->sig = NULL; // cuando ya no hayan mas iteraciones entoncens estee sera igual al nulo
    return e;
}


/**Que te pidan una estructura que represente un vector en ORDEN MENOR A MAYOR o MAYOR A MENOR**/
/*Esta cambia un poco, vamos a ver donde, usaremos el mismo ejemplo de antes:*/

NodoPtr VectorEnterosOrdenado(int *v,int n)      //Declaramos un tipo estructura y le pasamos por par�metros un array de enteros y un entero, no var�a
{
    NodoPtr e = malloc(sizeof(struct Nodo));     //Cabecera de estructura, no var�a
    e->sig = NULL;                               //En este caso esto cambia hemos puesto lo que solemos poner al final en el principio, nuestra cabecera apuntar� a NULL
    for(int i = 0; i<0; i++)                     //Condiciones del bucle, puede variar dependiando si nos lo piden en el orden act�al o en el orden contrario (lo veremos desp�es)
    {
        NodoPtr p = e;
        while((p->sig!=NULL)&&(p->sig->elem<v[i])) //En el caso de ordenar de menor a mayor, podemos cambiar esta condici�n para que sea al contrario, simplemente con cambiar el "p->sig->elem<v[i]" por "p->sig->elem>v[i]"
            p = p->sig;
        NodoPtr nueva = malloc(sizeof(struct EstructuraRep));
        nueva->elem = v[i];
        nueva->sig = p->sig;
        p->sig = nueva;
    }
    return e;
}

/**POSIBLES FUNCIONES PARA EL EJERCICIO 4**/
/*En el ejercicio 4 suele pedir suprimir o insertar elementos en la lista, vamos a ver esto con m�s detalle
porque son bastantes casos.*/

/**Caso en el que se pide eliminar un elemento con una condici�n especial**/
/*Esto suele pedirlo, es una condicion que mezcla dos de las diapositivas, puede ser eliminado el elemento
tanto por el principio como por el final. Vamos a analizar los casos*/
/**Elemento eliminado por el principio**/
/*Es combinar un bucle while de busqueda con la eliminaci�n de estructuras por el principio, esta �ltima se encuentra en las diapositivas,
usaremos el mismo ejemplo que en los anteriores*/







