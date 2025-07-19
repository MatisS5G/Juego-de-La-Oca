#ifndef TABLERO_H
#define TABLERO_H
#include "Casillas.h"

class tablero{
protected:
    vector<casilla*> casillas;
public:
    tablero();
    void SetTablero();
    casilla* FindCasilla(int numeroCasilla);
};

#endif // TABLERO_H
