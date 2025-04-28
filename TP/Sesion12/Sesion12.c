#include "ABB.h"
#include <stdio.h>
#include <string.h>
#define STRING_LONG 100

int main()
{
    int n;
    ABB a = ABBCrea();
    printf("Tamanyo arbol a: ");
    scanf("%d",&n);
    int dato;
    for (int i=0;i<n;i++)
    {
        printf("Elemento: ");
        scanf("%d",&dato);
        ABBInserta(&a,dato);
    }
    char s[STRING_LONG] = "";
    ABBToString(s,a);
    printf(" Conjunto a: %s\n",s);

    ABB b = ABBCrea();
    printf("Tamanyo arbol b: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Elemento: ");
        scanf("%d",&dato);
        ABBInserta(&b,dato);
    }

    strcpy(s,"");
    printf(" Conjunto b: %s\n",ABBToString(s,b));

    ABB uni = ABBUnion(a,b);
    strcpy(s,"");
    printf(" Union a y b: %s\n",ABBToString(s,uni));

    ABB inter = ABBInterseccion(a,b);
    strcpy(s,"");
    printf(" Interseccion: %s\n",ABBToString(s,inter));

    ABB dif = ABBDiferencia(a,b);
    strcpy(s,"");
    printf(" Diferencia:  %s\n",ABBToString(s,dif));

    ABBLibera(a);
    ABBLibera(b);
    ABBLibera(uni);
    ABBLibera(inter);
    ABBLibera(dif);

    return 0;
}

