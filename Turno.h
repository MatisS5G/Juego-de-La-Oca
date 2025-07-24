#ifndef TURNO_H
#define TURNO_H
#include "Ficha.h"
#include "Dado.h"
#include "Tablero.h"

#include <vector>

using namespace std;

// ========================================
// Clase Turno
// Representa un turno en el Juego de la Oca:
// - conoce al jugador que juega el turno
// Métodos:
//   Constructor y destructor
//   Desarrolo del turno
// ========================================


class Turno{
public:
    // Puntero al jugador que realiza el turno
    Ficha* jugador;

    // Constructor que recibe un jugador para inicializar el turno
    Turno(Ficha* jug);

    // Ejecuta el turno donde el jugar tira el dado y se mueve en el tablero
    void JugarTurno(Tablero* tab, Dado* dado);

    // Destructor para imlementar memoria dinámica
    ~Turno();
};

#endif // TURNO_H
