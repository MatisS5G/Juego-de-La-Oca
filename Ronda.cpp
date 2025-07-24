#include "Ronda.h"
#include "Tablero.h"
#include "Dado.h"


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

Ronda::Ronda(){

}

void Ronda::CrearRonda(){
    this->NroRonda = 0;
}

// Agrega un turno dentro del vector de los mismos
void Ronda::CargarTurno(Turno* t){
    this->turnos.push_back(t);
}


// Recorre todos los turnos de la ronda y los juega
// Devuelve false si alguien gana la partida (no continúa la ronda)
// Devuelve true si nadie gana (continúa la ronda y el juego)
bool Ronda::JugarRonda(Tablero* tab, Dado* dado){
    for (auto it=turnos.begin();it!=turnos.end();it++){

        //juega el turno actual
        (*it)->JugarTurno(tab,dado);

        //comprueba si el jugador que termino su turno gano la partida (casilla 63)
        if ((*it)->jugador->GetPosicion() == 63) return false;
    }

    // Si se recorrieron todos los turnos y nadie gano, retorna true
    return true;
}


void Ronda::PasarRonda(){
    this->NroRonda += 1; // Avanza a la siguiente ronda
}
