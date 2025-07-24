#ifndef RONDA_H
#define RONDA_H

#include "Turno.h"
#include "Tablero.h"
#include "Dado.h"

#include <vector>

using namespace std;

// ===============================================
// Clase Ronda
// Representa una ronda completa en el Juego de La Oca
// - número de la ronda actual
// - turnos de la ronda
// Métodos:
//   Constructor y destructor
//   Carga de un turno al vector
//   Desarrolo de la ronda
//   Incrementa el número de la ronda en 1
// ===============================================

class Ronda{
public:
    int NroRonda;
    vector<Turno*> turnos;
    Ronda();

    // Método para crear la ronda inicial
    void CrearRonda();

    // Agrega un turno al vector de turnos
    void CargarTurno(Turno* t);

    // Ejecuta todos los turnos de la ronda
    // Devuelve false si alguien gano la partida (la ronda se corta), true si nadie gano(la ronda se sigue desarollando)
    bool JugarRonda(Tablero* tab, Dado* dado);

    // Incrementa el numero de la ronda en 1 simulando que pasa a la siguiente si la anterior se completó
    void PasarRonda();
};
#endif // RONDA_H
