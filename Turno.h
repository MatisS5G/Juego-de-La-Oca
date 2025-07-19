#ifndef TURNO_H
#define TURNO_H
#include "Ficha.h"
#include <vector>
#include "Tablero.h"

class Turno{
public:
    Ficha* jugador;
    bool jugado;
    // int turnosPerdidos;
    Turno(Ficha* jug);
    void PierdeTurnos(int t);
    void PuedeJugar();
    void JugarTurno(tablero* tab, Dado* dado);
};

#endif // TURNO_H
