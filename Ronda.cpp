#include "Ronda.h"

//Crea la ronda inicial
Ronda::Ronda(int n){
    this->NroRonda = n;
}

//Carga un turno dentro del vector
void Ronda::CargarTurno(Turno *t){
    this->turnos.push_back(t);
}

//Recorre todos los turnos de esa ronda para jugarlos
bool Ronda::JugarRonda(tablero* tab, Dado* dado){
    for (auto it=turnos.begin();it!=turnos.end();it++){

        //juega el turno
        turno.JugarTurno(tab,dado);

        //comprueba si el jugador que termino su turno gano la partida
        //en este caso devuelve false significando que no se pudo terminar la ronda pq gano un jugador
        if (it->jugador->GetPosicion() == 63) return false;
    }
    //por defecto devuelve true, significando que termino la ronda en caso de recorrer todos los turnos
    return true;
}
