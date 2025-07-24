#include "Ficha.h"

// ===============================
// Clase Ficha
// Representa a un jugador en el juego:
// - nombre del jugador
// - posición en el tablero
// - penalizaciones o turnos perdidos
// Métodos:
//   Getters de nombre, posición, turnos perdidos
//   Métodos para mover, penalizar o liberar al jugador
//   TirarDado(): lanza el dado y devuelve la cara superior
// ===============================


// Constructor: crea un jugador con su nombre y configura valores iniciales
Ficha::Ficha(string n){
    this->nombre_jugador = n;
    this->posicion_tablero = 1;     // Posición inicial en el tablero
    this->Penalizado = false;               // No esta penalizado al iniciar
    this->CantTurnosPerdidos = 0;   // No tiene turnos perdidos al iniciar
}


string Ficha::Get_nombre(){
    return this->nombre_jugador; // Devuelve el nombre de jugador
}


int Ficha::GetPosicion(){
    return this->posicion_tablero; // Devuelve la posicion actual en el tablero
}


int Ficha::GetTurnoPerdidos(){
    return this->CantTurnosPerdidos; // Devuelve la cantidad de turnos que el jugador tiene que perder
}


void Ficha::PerderTurnos(int t){
    this->CantTurnosPerdidos = t; // Asigan la cantidad de turnos que perderá
}


// Resta un turno perdido al jugador (simula cumplir un turno sin jugar)
void Ficha::CumplirTurno(){
    if (this->CantTurnosPerdidos > 0) this->CantTurnosPerdidos -= 1;
}


void Ficha::MoverJugador(int nuevaPos){
    this->posicion_tablero = nuevaPos; // Mueve al jugador a una nueva posicion en el tablero
}


void Ficha::Penalizar(){
    this->Penalizado = true; // Penaliza al jugador(ej: cae en el pozo)
}


void Ficha::Liberar(){
    this->Penalizado = false; //Libera al jugador de la penalización
}


bool Ficha::Estado(){
    return this->Penalizado; // Devuelve true si el jugador está penalizado, false si no lo está
}

// Permite que el jugador tire el dado y devuelve la cara superior obtenida
int Ficha::TirarDado(Dado* d){
    int CaraSuperior = d->Lanzar();
    return CaraSuperior;
}
