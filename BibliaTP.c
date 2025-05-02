#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/** I M P O R T A N T E **/
/*Antes de empezar no compileis esto porque no va a funcionar logicamente, tambien cabe recalcar que yo tambien soy un estudiante y me equivoco m�s
que los profesores as� que probar antes del examen que funcionan todas las funciones aqui puestas, que aun que sean copias de examenes y diapositivas
pueden dar errores al fluctuar con los ejercicios, en caso de que eso pase mi recomendacion es preguntar en el examen y rezar a que os den pista o, la
m�s realista buscar en las diapositivas algo que se parezca a lo que pide el enunciado, aqu� �nicamente est�n aquellas funciones que me he encontrado
en examenes y las que veo que m�s suelen aparecer. No obstante pueden sorprendernos con cosas distintas, en ese caso me reitero, mirar las diapositivas.
Dicho esto, espero que este archivo os ayude en el examen*/



/**POSIBLES FUNCIONES PARA EL EJERCICIO 1**/
/*Por lo visto en los examenes simulacros que hemos hecho, el primer ejercicio se basa en la definici�n
de un vector din�mico, voy a poner las distintas maneras en las que nos lo puede pedir:*/

/**Como array de enteros**/
/*Este es el t�pico, un vector de enteros que realize una operaci�n y que,
al realizarla la retorne al final de la funci�n, la parte est�tica es la de asignar memoria, el bucle y
la retornada de v, las partes que deben ser modificadas ser�n las siguientes marcadas en el siguiente ejemplo.
Ultilizar� el siguiente enunciado:
Una funci�n que recibe como par�metro un entero mayor o igual que 2 y devuelve un vector
de enteros d�nde: a_1 = 1 ; a_2 = 3 ; a_n = n*((a_n-1)-(a_n-2)) para todo n>2*/

int *vectorEnteros(int n)               //Definici�n de la funci�n, siempre es as�, excepto que puede variar dependiendo del tipo que le demos (ej: int o double)
{
    int *v = malloc(sizeof(int)*n);     //Asignaci�n de memoria, siempre es as� excepto el tama�o, que puede variar dependiendo del tipo que le demos (ej: int o double)
    v[0] = 1;                           //Esto es parte del ejercicio, son posiciones de array estaticas, que siempre van a tener esos valores
    v[1] = 3;                           //Esto es parte del ejercicio, son posiciones de array estaticas, que siempre van a tener esos valores
    for(int i=2; i<n; i++)              //Definici�n del bucle, siempre es as�, lo unico que puede cambiar es desde donde empieza la i
    {
        v[i] = (i+1)*(v[i-1]-v[i-2]);   //Nuestra  operaci�n, siempre cambia dependiendo del ejercicio, el caso est� en fijarse bien en lo que se pide
    }
    return v;                           // El ejercicio nos pide que retornemos un array, siempre es as�
}

/**Como array de reales (double and floats)**/
/*Este es b�sicamente igual que el anterior pero cambiando la parte de los enteros por double's, tener en cuenta
que con los reales, en el bucle for ahora en una de las condiciones deber� ser i <= n en vez de i < n
Voy a usar de ejemplo lo siguiente:
Una funci�n que recibe como un par�metro un entero mayor o igual que 1 yu devuelve un vector
de reales donde, a_1=(i-1)/i. Por ejemplo, si llamamos a esta funci�n con un valor 5 devolver�a un vector
con los elementos 0, 0.5, 0.67, 0.75, 0.8*/

double *vectorReales(int n)             //Definici�n de la funci�n, siempre es as�, excepto que puede variar dependiendo del tipo que le demos (ej: int o double)
{
    int *v = malloc(sizeof(double)*n);      //Asignaci�n de memoria, siempre es as� excepto el tama�o, que puede variar dependiendo del tipo que le demos (ej: int o double)
    v[0] = 1;                               //Esto es parte del ejercicio, son posiciones de array estaticas, que siempre van a tener esos valores
    v[1] = 3;                               //Esto es parte del ejercicio, son posiciones de array estaticas, que siempre van a tener esos valores
    for(int i=2; i<=n; i++)                 //Definici�n del bucle, siempre es as�, lo unico que puede cambiar es desde donde empieza la i
    {
        v[i-1] = (double)(i-1.0)/(double)i; //Nuestra  operaci�n, siempre cambia dependiendo del ejercicio, el caso est� en fijarse bien en lo que se pide
    }
    return v;                               // El ejercicio nos pide que retornemos un array, siempre es as�
}









/**POSIBLES FUNCIONES PARA EL EJERCICIO 2**/
/*Reitero, como hemos visto en los simulacros, en el segundo ejercicio SIEMPRE se pide definir un
tipo estructura enlazada, esta s� que no varia pr�cticamente nada en su sint�xis. Se puede directamente
copiar y pegar de las diapositivas*/
typedef struct Nodo * NodoPtr;          //Esta es la propia estructura que usaremos para referirnos al struct, no var�a
struct Nodo                             //El tipo estructura creado, no var�a
{
    int elem;                           //Esto es del tipo que es la estructura, var�a en el tipo de datos que te puedan pedir (ej: double o int)
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

NodoPtr VectorEnteros(int *v,int n)     //Declaramos un tipo estructura y le pasamos por par�metros un array de enteros y un entero, no var�a
{
    NodoPtr e = malloc(sizeof(struct Nodo));   //Cabecera de estructura, no var�a
    NodoPtr aux = e;                           //Apuntador auxiliar, no var�a
    for(int i = 0; i<n; i++)                   //Condiciones del bucle, puede variar dependiando si nos lo piden en el orden act�al o en el orden contrario (lo veremos desp�es)
    {
        aux->sig = malloc(sizeof(struct Nodo));  //Asignamos el tama�o al nodo siguiente (vag�n que enganchemos, le proporcionamos un espacio)
        aux->sig->elem = v[i];                   //Accedemos dentro de la estructura al elemento y le asignamos un espacio del array(metemos equipaje/pasajeros al vag�n)
        aux = aux->sig;                          //Ahora nx apuntar� al siguiente nodo que creemos y as� iterativamente se repiten estos pasos hasta llenar el tama�o proporcionado en "n"
    }
    aux->sig = NULL;
    return e;
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
    aux->sig = NULL;
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
void SuprimePrimerPar(NodoPtr p)                          //Declaramos el procedimiento con un par�metro p tipo nodo
{
    /*El while har� la busqueda mientras que el elemento siguiente no apunte a NULL, porque significar� que hemos llegado
    al final de la lista, y tambi�n buscar� obviamente mientras que nuestro elemento siguiente al dividirse entre 2 el residuo no d� 0*/
    /**Esto es parte de la busqueda del elemento con la condici�n concreta**/
    while((p->sig!=NULL) && (p->sig->elem%2!=0))    //Busqueda con las condiciones antes mencionadas)
    {
        p = p->sig;                                 //Mientras no ocurra lo anterior avanzamos en la cadena
    }
    /**Esta parte es la que est� en las diapositivas, m�s a delante pondr� este caso aislado**/
    NodoPtr eliminado = p->sig; // guardamos el elemento a eliminar
    p->sig = eliminado->sig; // lo eliminamo de la lista 
    free(eliminado); // liberanos la memoria ocupada por el elemento eliminado
}

/**Elemento eliminado por el final**/
/*Esto ser� lo mismo que antes, combinaremos el de las diapositivas con el de b�squeda especial, este tambien est� asociado al ejemplo de los pares*/
void suprime_ultimo_par(NodoPtr e)
{
    NodoPtr p = NULL; //inicializamos el puntero a NULL, porque no sabemos si hay pares o no
    while(e->sig!=NULL)
    {
        if (e->sig->elem%2==0) // comprobamos is el siguiente elemento es par
            p = e; // guardamos el puntero al elemento anterior
        e = e->sig // avanzamos en la lista
    }
    if (p!=NULL)
    { // eliminamo por el final
        NodoPtr borrar = p->sig;
        p->sig = borrar->sig;
        free(borrar);
    }
}

// suprime_los negativos
void suprimir_negativos(Estructura e)
{
    Estructura aux = e;
    while(aux->sig != NULL){
        if(aux->sig->elem < 0){ // en el caso de que positivo seria >= 0
            Estructura eliminado = aux->sig;
            aux->sig = eliminado->sig;
            free(eliminado);
        } else {
            aux = aux->sig;  // Avanzar solo si no se elimin�
        }
    }
}


/**Vamos ahora a las eliminaciones de elementos en s�, son las siguientes:**/
/*Estas no tienen mucha vuelta, son lo que son*/
/**Elemento eliminado por el principio**/
void suprime_primero(NodoPtr l)
{
    NodoPtr eliminado = l->sig;
    l->sig = eliminado->sig;
    free(eliminado);
}

/**Elemento eliminado por el final**/
void suprime_ultimo(NodoPtr l)
{
    NodoPtr p = l;
    while (p->sig->sig != NULL)
        p = p->sig;
    free(p->sig);
    p->sig = NULL;
}
/**Supresi�n de la primera ocurrencia de un elemento predeterminado en
una estructura ordenada crecientemente**/
/*Esta la a�ado directamente de las diapositivas, por si acaso, bajo mi opini�n podr�a caer en un ejercicio tipo 4
esta no tiene ningun ejemplo asociado*/
{
    NodoPtr p = l;
    while ((p->sig != NULL) && (p->sig->elem < dato))
        p = p->sig;
// Se suprime s�lo si se ha encontrado
    if ((p->sig != NULL) && (p->sig->elem == dato))
    {
        NodoPtr eliminado = p->sig;
        p->sig = eliminado->sig;
        free(eliminado);
    }
}
/**Supresi�n de todas las ocurrencias de un elemento predeterminado**/
/*Esta directamente elimina todos los elementos concretos que indiquemos en las
condiciones de los bucles, tampoco tiene ningun ejemplo asociado*/
void suprime_todos(NodoPtr l, Elemento dato)
{
    NodoPtr p = l;
    while (p->sig != NULL)
    {
        if (p->sig->elem == dato)
        {
            NodoPtr eliminado = p->sig;
            p->sig = eliminado->sig;
            free(eliminado);
        }
        else
        {
            p = p->sig;
        }
    }
}


/**IMPORTANTE**/ /*En el tipo de ejercicio 4 puede que hayan m�s funciones, pero dudo que vaya a pedirlas, si eso ocurre mirad las diapositivas,
si no est�n en la parte de los apuntes seguramente est�n en los ejercicios, o si no intentad, a partir del enunciado combinar algunas como ocurre
con las otras dos*/











/**TIPOS DE FUNCIONES PARA EL EJERCICIO 5**/
/*En principio este ejercicio es est�tico, lo que hace es imprimir por pantalla la estructura que hemos creado*/
void imprime(NodoPtr l)
{
    l = l->sig; // eliminanos la cabecera de la lista ya que no querermos imprimirla 
    while (l != NULL) //  mientra que no llegemos alfinal de la lista 
    {
        printf("%d\n", l->elem); // implimimos el elemento de la lista 
        l = l->sig; // avanzamos al siguiente elemento de la lista 
    }
}







/**TIPOS DE FUNCIONES PARA EL EJERCICIO 6**/
/*Este es como el anterior, lo �nico que hace es liberar la memoria de la estructura*/
void libera(NodoPtr l)
{ // simplemeente liberamos la memoria de la lista 
    while (l!=NULL)
    {
        NodoPtr p = l;
        l = l->sig;
        free(p); 
    }
}







/**TIPOS DE FUNCIONES PARA EL EJERCICIO 7**/
/*Este tambi�n es m�s o menos sencillo, por lo general nos pide definir un tipo �rbol,
puede pedirnos tanto binario c�mo general, vamos a ver los tipos*/
/**Para crear un �rbol general**/


// typedef int ELemento; //Esto es lo que se suele poner, pero puede variar dependiendo del tipo de datos que nos pidan, por ejemplo si nos piden operadores, en ese caso se suele poner char *s

struct Nodo
{
    Elemento elem;                                  //Esta parte puede cambiar si, por ejemplo te piden operadores, en ese caso creas un char *s
    struct Nodo * hijoIzquierdo, * hermanoDerecho;
};
typedef struct Nodo * ArbolGeneral;

/**Para crear un �rbol binario**/
/*Son pr�cticamente id�nticos*/
struct Nodo
{
    Elemento elem;                                  //Esta parte puede cambiar si, por ejemplo te piden operadores, en ese caso creas un char *s
    struct Nodo * hijoIzquierdo, * hijoDerecho;
};
typedef struct Nodo * ArbolBinario;

/**Esta es la que sirve para operadores**/
/*Mencionada anteriormente y sacada tambien de diapositivas*/
typedef struct ArbolRep * Arbol;
struct ArbolRep
{
    char * str;
    Arbol izq, der;
};












/**TIPOS DE FUNCIONES PARA EL EJERCICIO 8**/
/*Por lo general, en este tipo nos van a pedir utilizar el �rbol binario, como por ejemplo indicar el n�mero
de operadores o numero de operandos, por poner dos ejemplos, vamos a ver los tipos m�s comunes:*/
/**Contar el n�mero de operadores**/
/*Lo que hace es buscar en los �RBOLES BINARIOS un*/
int operadores(Arbol a)
{
    if (a == NULL) return 0; //Caso base, si no hay nada en el arbol no hay operadores
        return 0;
    if (a->izq==NULL)  //Caso base, si no hay nada en el arbol izuqierdo no hay operadores
        return 0;
    return 1+operadores(a->izq)+operadores(a->der);
}

/**Que represente los valores de los operadores y los operandos**/
/*Este lo hizo la profesora en un ejemplo de examen concreto, pero no est� mal verlo aqu�, se debe
tener cuidado a la hora de definir nombres en el examen*/
int operadoresYoperandos(ArbolBinario a)
{
    /*Caso base*/
    if (a==NULL) return 0;
    /*Caso recursivo*/
    return 1+operadoresYoperandos(a->izq)+operadoresYoperandos(a->der);
}

/**Calcular lo que se introduce por los par�metros del �rbol binario**/
/*Este tipo lo que hace es sacar por pantalla el resultado de las operaciones que el
usuario elija, si no se entiende bien as� nada m�s ver el codigo se entiende muy bien*/
double ExpresionValor(Arbol a)
{
    double v = 0;
    if (a->izq==NULL)
        v = atof(a->str);
    else switch(a->str[0])
        {
        case '+':
            v = ExpresionValor(a->izq)+ExpresionValor(a->der);
            break;
        case '-':
            v = ExpresionValor(a->izq)-ExpresionValor(a->der);
            break;
        case '*':
            v = ExpresionValor(a->izq)*ExpresionValor(a->der);
            break;
        case '/':
            v = ExpresionValor(a->izq)/ExpresionValor(a->der);
        }
    return v;
}

/**Imprimir por pantalla el �rbol binario**/
/*Este est� sacado de otro ejemplo de examen, por lo que lo mismo, cuidado a la hora de los nombres y definiciones que teng�is en el examen*/
void imprime(Arbol a)// 'a' es un puntero al nodo actual que se está procesando.
{
    if (a != NULL) // Solo hacemos algo si el nodo actual existe (no es un puntero nulo).
    {
        if (a->izq == NULL)
            printf("%s",a->str); // imprimimos el operador
        else
        {
            printf("("); // 
            imprime(a->izq); // imprimimos el subárbol izquierdo
            printf("%s",a->str); // imprimimos el operador
            imprime(a->der); // impimimos el subárbol derecho
            printf(")");
        }
    }
}








/**IMPORTANTE**/ /*De momento no he visto m�s tipos en los que te pueda pedir cosas en el ejercicio 8, no obstante seguramente nos pida otra cosa, en ese
caso, o se reza, o se intenta buscar en las diapositivas algo que cuadre, aunque a este punto del examen seguramente est�is aprobad�simos si lo
anterior lo llevais al pelo asi q no importa mucho, eso s�, mi recomendaci�n es buscar cosas en las diapositvas, que no se pierde nada*/

/**TIPOS DE FUNCIONES PARA EL EJERCICIO 9**/
/*Por lo que he visto en todos los examenes de a�os pasados, en el ejercicio 9 suele pedir liberar el �rbol*/
/**Liberaci�n de un �rbol binario**/
void libera(ArbolBinario a) // postorden
{
    if (a == NULL) return; // caso base, si no hay nada que liberar no se hace nada
    libera(a->hijoIzquierdo); // liberamos el hijo izquierdo
    libera(a->hijoDerecho); // liberamos el hijo derecho
    free(a); // liberamos el nodo actual
}

/**Liberaci�n de un �rbol general**/
/*Se parecen pero en el caso del �rbol general los hijos izquierdos cambian un poco*/
void libera(ArbolGeneral a)
{
    if (a == NULL) return; // caso base, si no hay nada que liberar no se hace nada
    libera(a->hijoIzquierdo); // liberamos el hijo izquierdo
    libera(a->hermanoDerecho); // liberamos el hermano derecho
    free(a); // liberamos el nodo actual
}














/**POSIBLES FUNCIONES PARA EL EJERCICIO 11**/
/*Lo pongo antes del main porque hay que definir la funcion crea�rbol fuera, pero no es m�s que eso, crear el �rbol*/
/**La que crea �rboles binarios**/
ArbolBinario crea_arbol(Elemento elem)
{
    ArbolBinario nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = elem;
    nuevo->hijoIzquierdo = NULL;
    nuevo->hijoDerecho = NULL;
    return nuevo;
}

/**La que crea �rboles generales**/
ArbolGeneral crea_arbol(Elemento elem)
{
    ArbolGeneral nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = elem;
    nuevo->hijoIzquierdo = NULL;
    nuevo->hermanoDerecho = NULL;
    return nuevo;
}
/*Ahora las pondr� en el main, lo mismo de siempre, estas son las que he visto y en examenes, puede ser que nos la l�e y ponga otra cosa
en ese caso mirar las diapositivas y rezar, tambien recomendaci�n de mirar las pr�cticas de �rboles que puede ser que salven culos*/











/**EJERCICIO 10**/
/*Es literalmente crear el main para que probeis que todo funciona, mi recomendaci�n es ir creandolo conforme se avanza en los ejercicios
para saber que est� yendo todo bien y asi matais dos pajaros de un tiro, lo q si voy a meter es lo que siempre suele estar en el main*/
int main()
{
    SetConsoleCP(1252);              //Para poder usar caracteres espa�oles y otros...
    SetConsoleOutputCP(1252);       //Para poder usar caracteres espa�oles y otros...
    int n = 5;
    //Funci�n del ejercicio 1
    int * v = vector(n);
    //Comprobaci�n de que funciona el ejercicio 1
    for(int i=0; i<n; i++)
    {
        printf("El numero guardado en la posici�n %d es: %d\n",i+1, v[i]);
    
    printf("\n");

    //Ejercicio 2
    NodoPtr e = VectorEnteros(v,n);
    //Ejercicio 3
    SuprimePrimerPar(e);
    //Ejercicio 4(imprime los ejercicios 2 y 3)
    imprime(e);
    printf("\n");
    //Liberaci�n de las memorias
    free(v);
    //Esta liberaci�n es el ejercicio 5
    libera(e);

    /**EJERCICIO 11**/
    /*Llamada a �rboles binarios*/
    ArbolBinario raiz = crea_arbol(0);
    raiz->hijoIzquierdo = crea_arbol(1);
    raiz->hijoDerecho = crea_arbol(2);

    /*Llamada a �rboles generales*/ 
    ArbolGeneral raiz = crea_arbol(0);
    raiz->hijoIzquierdo = crea_arbol(1);
    raiz->hijoIzquierdo->hermanoDerecho = crea_arbol(2);


    // Crear un árbol binario con 7 nodos:
    //        10
    //       /  \
    //      5    15
    //     / \    \
    //    3   7    20
    //   /
    //  1

    // Crear nodos
    ArbolBinario raiz = crea_nodo(10);
    raiz->hijoIzquierdo = crea_nodo(5);
    raiz->hijoDerecho = crea_nodo(15);
    
    raiz->hijoIzquierdo->hijoIzquierdo = crea_nodo(3);
    raiz->hijoIzquierdo->hijoDerecho = crea_nodo(7);
    
    raiz->hijoDerecho->hijoDerecho = crea_nodo(20);
    
    raiz->hijoIzquierdo->hijoIzquierdo->hijoIzquierdo = crea_nodo(1);

    // Recorrer para verificar
    printf("Recorrido preorden (binario): ");
    preorden(raiz); // Salida: 10 5 3 1 7 15 20

    libera_arbol(raiz);
    return 0;



    /* en el caso de imprimir el arbol binario mano a mano 
    Arbol ab = crea_arbol();
    int b;
    printf("Conteo de numeros mayores que: ");
    scanf("%d", &b);
    printf("Numeros mayores que %d en el arbol: %d", b, mayores(ab, b));
    */

    return 0;
}
