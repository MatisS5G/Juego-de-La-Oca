#include "Ficha.h"

//Constructor para crear un jugador
Ficha::Ficha(string n){
    this->nombre_jugador = n;
    this->posicion_tablero = 1; //inicia en la posicion inicial del tablero
    this->Penalizado = false;
    this->CantTurnosPerdidos = 0;
}

//Devuelve el nombre de jugador
string Ficha::Get_nombre(){
    return this->nombre_jugador;
}

//Devuelve la posicion en el tablero del jugador
int Ficha::GetPosicion(){
    return this->posicion_tablero;
}

//Devuelve la cantidad de turnos que pierde el jugador a futuro
int Ficha::GetTurnoPerdidos(){
    return this->CantTurnosPerdidos;
}

void Ficha::PerderTurnos(int t){
    this->CantTurnosPerdidos = t;
}

//El jugador pasa un turno sin jugar
void Ficha::CumplirTurno(){
    this->CantTurnosPerdidos -= 1;
}

//Mueve al jugador a otra posicion en el tablero
void Ficha::MoverJugador(int nuevaPos){
    this->posicion_tablero = nuevaPos;
}

//Atrapa al jugador en el pozo
void Ficha::Penalizar(){
    this->Penalizado = true;
}

//Libera al jugador del pozo
void Ficha::Liberar(){
    this->Penalizado = false;
}

bool Ficha::Penalizado(){
    return this->Penalizado;
}

//Metodo para que el jugador sea responsable de tirar el dado
int Ficha::TirarDado(Dado* d){
    int CaraSuperior = d->Lanzar();
    return CaraSuperior;
}
