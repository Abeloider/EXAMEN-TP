#ifndef BOMBO_H_INCLUDED
#define BOMBO_H_INCLUDED

extern int error;
typedef struct BomboRep * Bombo;
// Construye y devuelve un bombo vac�o que puede contener un
// m�ximo de max bolas. Si max<2 devuelve NULL y asigna
// error=1.
Bombo BomboCrea(int x);
// Inserta una bola en el bombo b.
// Si el bombo b est� lleno devuelve -1 y asigna error=2,
// en caso contrario devuelve 0.
int BomboInserta(Bombo b, int bola);
// Libera el bombo b.
void BomboLibera(Bombo b);
// Extrae y devuelve una bola del bombo b.
// Si el bombo b est� vac�o devuelve -1 y asigna error=3.
int BomboExtrae(Bombo b);
// Devuelve 1 si el bombo b est� vac�o y 0 en caso contrario.
int BomboVacia(Bombo b);
// Devuelve el mensaje de error asociado a un c�digo de error
// del bombo b.
char * BomboMensajeError(int codigoError);


#endif // BOMBO_H_INCLUDED
