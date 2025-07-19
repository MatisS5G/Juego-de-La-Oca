#ifndef RONDA_H
#define RONDA_H
#include "Turno.h"
#include "Tablero.h"
#include <vector>

class Ronda{
public:
    int NroRonda;
    vector<Turno*> turnos;
    Ronda(int n);
    void CargarTurno(Turno* t);
    bool JugarRonda(Tablero* tab, Dado* dado);
};

#endif // RONDA_H
