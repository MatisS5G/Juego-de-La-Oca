#include "Turno.h"

Turno::Turno(Ficha *jug){
    this->jugador = jug;
}

void Turno::JugarTurno(tablero *tab, Dado* dado){
    //compruebo si se puede jugar el turno o no
    if (!this->jugador->Penalizado()){
    //El jugador tira el dado
    int caraSuperior = this->jugador->TirarDado(dado);

    //El jugador se mueve a la posicion correspondiente
    this->jugador->MoverJugador(caraSuperior);

    //busco la casilla en donde se encuentra el jugador y aplico la regla de la misma
    casilla* casAux = tab->FindCasilla( this->jugador->GetPosicion() );
    casAux->aplicarRegla(this->jugador);

    }else{
        if (jugador->GetTurnoPerdidos() > 0) jugador->CumplirTurno();//funcion para restar turnos;
    }
}
