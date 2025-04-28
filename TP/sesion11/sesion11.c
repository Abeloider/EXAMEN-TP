#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRING_SIZE 100


// leer requerimiento para n>=1
int sumatorio (int n) {
    if (n==1)
        return 1;
    return sumatorio(n-1)+n;
}

int suma_digitos(int n) {
    if (n<10)
        return n;
    return suma_digitos(n/10)+n%10;
    }

int longitud(char * s) {
    if (s[0]==0) // s[0] == 0 // *s == 0
        return 0;
    return longitud(s+1)+1;
}


void piramide (char *s) {
    if (s[0]!=0) {
        piramide(s+1);
        printf("%s\n",s);
    }
}


void piramide_invertido(char *s) {
    if (s[0]!=0) {
        printf("%s\n",s);
        piramide(s+1);

    }
}

int palindromo_aux(char * s, int i, int j){
    if (i>=j) { // yirnr 0 o 1
        return 1;
        return (s[i]==s[j] && palindromo_aux(s,i+1,j-1));

    }
}


int palindromo(char * s){

        return palindromo_aux(s,0,longitud(s)-1);

}

char * copia(char *s1, const char * s2) {
    s1[0]=s2[0];
    if (s2[0]!=0) {
        copia(s1+1, s2+1);
    }
     return s1;
}

void sustituye(char * s, char a, char b) {
    if (s[0]==0) {
        }
        if (s[0]==a && s[0]==b )
            sustituye(s+1,a,b)
    }





int main () {
    int n=5;
    if (n>=1)
    printf ("Pon el tamaño de n: %d\n", sumatorio(n));

    n=1324;
    if (n>=1)
    printf ("Pon el tamaño de n: %d\n", suma_digitos(n));

    char s[STRING_SIZE];
    printf("Introduce cadenas: ") ;
    scanf("%s",s);
    printf ("Pon el tamaño de n: %d\n", longitud(s));

    piramide(s);
    piramide_invertido(s);


    if (palindromo(s))
        printf("Es palindromo. \n" );
    else
        printf("No es palindromo. \n" );

        char s1[STRING_SIZE] ;
        copia(s1,s);
        printf("%s\n", s1);

        //printf("%s\n",copia (s1,s));

    return 0;
}
