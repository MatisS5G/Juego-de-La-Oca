#include <iostream>
#include <algorithm>
#include <random>

#include "Juego.h"
#include "Ronda.h"
#include "Turno.h"
#include "Tablero.h"
#include "Dado.h"
#include "Ficha.h"
#include "Casillas.h"

using namespace std;

//FALTA:
/*
 * Terminar la funcion FinalizarPartida().
 * Agregar la funcion de los mensajes y ver que tan viable es implementarla de la forma que pense.
 * Terminar de documentar todo, ver como se documenta bien a forma de teoria.
*/

// Constructor de Juego: inicializa el nombre de la partida
Juego::Juego(){
    string n;
    cout << "Ingrese el Nombre de la Partida: ";
    cin >> n;
    cout << endl;
    this->NombrePartida = n;
    this->dadoOca = new Dado();
    this->tablero = new Tablero();
}

// Destructor de Juego: elimina todas las entidades dinamicas
Juego::~Juego(){
    delete dadoOca;
    delete tablero;
    for (auto j : this->Jugadores) delete j;
}

// Carga de las configuraciones por defecto del juego(dado y tablero)
void Juego::CargarPartida(){
    this->dadoOca->ElegirDado();
    this->tablero->SetTablero();
    cout << "Carga defecto" << endl;
}

// Carga de los jugadores de la partida con su nombre y posicion inicial
void Juego::CargarJugadores(){
    int TotJugadores;
    string nombreJ;
    cout<<"ingrese la cantidad de jugadores(1/2/3/4):";
    cin>>TotJugadores;
    for (int i=0;i<TotJugadores;i++){
        cout << "ingrese el nombre del jugador " << i+1 << ": ";
        cin >> nombreJ;
        Ficha* jug = new Ficha(nombreJ); //Crea un nuevo jugador
        this->Jugadores.push_back(jug); //Lo agrega al vector de jugadores
    }
}



// Sortea el orden de turnos de los jugadores tirando el dado
void Juego::SortearOrdenTurnos(){

    // Vector para almacenar a los jugadores y su numero
    std::vector<std::pair<int,Ficha*>> Tiradas;
    bool repetido;

    cout << endl << "=== Tiraremos el dado para el orden de juego ===" << endl << endl;

    for (Ficha* j : this->Jugadores){
        // Los jugadores tiran el dado
        int num;
        cout << j->Get_nombre() << " -Tire el dado: ";
        num = j->TirarDado(this->dadoOca);
        cout << "..." << " _Saco el mumero: " << num << endl;

        // Verifica si ese numero ya salió
        do{
            repetido = false;
            for (auto t : Tiradas){
                if (t.first == num){
                    repetido = true;
                    break;
                }
            }
            if (repetido){
                cout << "El numero ya salio, vuelva a tirar-" << endl;
                num = j->TirarDado(this->dadoOca);
                cout << "El jugador " << j->Get_nombre() << " saco el mumero: " << num << endl;
            }
        }while (repetido);

        // Almacena al jugador y el número que tiró
        Tiradas.push_back({num,j});
    }

    // Ordena de mayor a menor segun el numero tirado
    std::sort(Tiradas.begin(),Tiradas.end(),[](auto& a, auto& b){
        return a.first > b.first;
    });

    // Crea un nuevo vector con el orden correcto
    std::vector<Ficha*> NuevoOrdenJug;
    cout << endl << "=== Orden del juego ===" << endl;
    int orden = 1;
    for (auto par : Tiradas){
        cout << orden << "." << par.second->Get_nombre() << endl;
        cout << "Numero elegido: " << par.first << endl;
        NuevoOrdenJug.push_back(par.second);
        orden++;
    }

    cout << endl << endl;

    // Remplaza al vector de jugadores con el nuevo orden
    this->Jugadores = NuevoOrdenJug;
}

// Inicia la partida y ejecuta el ciclo de rondas hasta que alguien gane
void Juego::IniciarPartida(){
    // Crea la ronda actual
    Ronda* RondaActual = new Ronda;
    RondaActual->CrearRonda(); cout << endl << "Se crea la ronda" << endl;

    // Carga los turnos de la primer ronda
    for (auto j : this->Jugadores){
        Turno* NuevoTurno = new Turno(j);
        RondaActual->CargarTurno(NuevoTurno);
        cout << endl << "Se carga un turno" << endl;
    }

    // Ciclo principal del juego
    bool SeguirRonda = true;
    while (SeguirRonda){
        RondaActual->PasarRonda(); // Avanza a la siguiente ronda
        cout << "Se está jugando la ronda Nro " << RondaActual->NroRonda << endl;
        SeguirRonda = RondaActual->JugarRonda(this->tablero,this->dadoOca); // Devuelve false si alguien gana

        if (RondaActual->NroRonda == 100) SeguirRonda = false;
    }

    // Busca al jugador que gano la partida (posicion 63).
    auto Ganador =
        find_if(Jugadores.begin(),Jugadores.end(),[](Ficha* j){
            return (j->GetPosicion() == 63);
        });

    if (Ganador != Jugadores.end()) FinalizarPartida(Ganador); // Llama a FinalizarPartida con el ganador

    delete RondaActual; // Libera la memoria de la ronda creada
}

// Muestra un mensaje con el nombre de jugador que ganó la partida
void Juego::FinalizarPartida(vector<Ficha*>::iterator ganador){
    if (ganador == this->Jugadores.end()){
        cout << "nadie gano" << endl;
    }else{
        cout << "El ganador de la partida es " << (*ganador)->Get_nombre() << endl;
    }
}
