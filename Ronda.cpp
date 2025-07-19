#include "Ronda.h"

Ronda::Ronda(int n){
    this->NroRonda = n;
}

void Ronda::CargarTurno(Turno *t){
    this->turnos.push_back(t);
}

void Ronda::JugarRonda(tablero* tab, Dado* dado){
    for (auto turno : this->turnos){
        turno.JugarTurno(tab,dado);
    }
}
