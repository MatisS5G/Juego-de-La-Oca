#ifndef FICHA_H
#define FICHA_H
#include <string>
#include "Dado.h"

using namespace std;

// ===============================
// Clase Ficha
// Representa a un jugador en el juego:
// - nombre del jugador
// - posición actual en el tablero
// - penalizaciones
// - turnos perdidos
// Métodos:
//   Getters de nombre, posición, turnos perdidos
//   Métodos para mover, penalizar o liberar al jugador
//   TirarDado(): lanza el dado y devuelve la cara superior
// ================================

class Ficha{
protected:
    string nombre_jugador;
    int posicion_tablero;
    bool Penalizado = false;
    int CantTurnosPerdidos = 0;
public:
    // Constructor: crea un jugador con su nombre
    Ficha(string n);

    // Devuelve el nombre del jugador
    string Get_nombre();

    // Devuelve la posición actual en el tablero
    int GetPosicion();

    // Devuelve la cantidad de turnos que perderá
    int GetTurnoPerdidos();

    // Asigna los turnos que perderá el jugador
    void PerderTurnos(int t);

    // Resta un turno perdido (cumple un turno de penalización)
    void CumplirTurno();

    // Mueve al jugador a una nueva posición en el tablero
    void MoverJugador(int nuevaPos);

    // Penaliza al jugador (ej. queda atrapado en el pozo)
    void Penalizar();

    // Libera al jugador de la penalización
    void Liberar();

    // Devuelve true si el jugador está penalizado, false si no
    bool Estado();

    // El jugador tira el dado y devuelve la cara superior obtenida
    int TirarDado(Dado* d);
};

#endif // FICHA_H
