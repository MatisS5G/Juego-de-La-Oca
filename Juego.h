#ifndef JUEGO_H
#define JUEGO_H

#include "Ficha.h"
#include "Dado.h"
#include "Tablero.h"
#include "Ronda.h"

#include <vector>
#include <string>

using namespace std;


// =======================================
// Clase Juego
// Representa al Juego de la Oca:
// - nombre de la partida
// - dado y tablero utilizados en el juego
// - vector que almacena los jugadores
// Métodos:
//   Carga de valores iniciales para la partida
//   Ordenar turnos de los jugadores
//   Inicio y Fin de partida
// ========================================


class Juego{
protected:
    string NombrePartida;
    Dado* dadoOca;
    Tablero* tablero;
    vector<Ficha*> Jugadores;
public:
    // Constructor que inicializa el nombre de la partida y crea dado y tablero
    Juego();

    // Carga una partida existente desde archivo o configuración previa
    void CargarPartida();

    // Carga los jugadores para la partida actual
    void CargarJugadores();

    // Sortea el orden de los turnos para los jugadores
    void SortearOrdenTurnos();

    // Inicia el desarrollo de la partida
    void IniciarPartida();

    // Finaliza la partida, mostrando al ganador
    void FinalizarPartida(vector<Ficha*>::iterator ganador);

    // Destructor que borra el juego de la memoria, el dado y el tablero tambien
    ~Juego();
};

#endif // JUEGO_H
