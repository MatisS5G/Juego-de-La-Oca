#ifndef JUEGO_H
#define JUEGO_H
#include "Ficha.h"
#include "Dado.h"
#include "Tablero.h"
#include <vector>
#include <string>
#include "Ronda.h"

class Juego{
protected:
    string NombrePartida;
    Dado* dadoOca;
    tablero Tablero;
    vector<Ficha*> Jugadores;
public:
    Juego(string n);
    void CargarPartida();
    void CargarJugadores();
    void SortearOrdenTurnos();
    void IniciarPartida();
    void FinalizarPartida();
};

#endif // JUEGO_H
