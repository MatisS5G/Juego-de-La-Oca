#ifndef FICHA_H
#define FICHA_H
#include <string>
#include "Dado.h"

class Ficha{
protected:
    string nombre_jugador;
    int posicion_tablero;
    bool Penalizado;
    int CantTurnosPerdidos = 0;
public:
    Ficha(string n);
    string Get_nombre();
    int GetPosicion();
    int GetTurnoPerdidos();
    void PerderTurnos(int t);
    void CumplirTurno();
    void MoverJugador(int nuevaPos);
    void Penalizar();
    void Liberar();
    bool Penalizado();
    int TirarDado(Dado* d);
};

#endif // FICHA_H
