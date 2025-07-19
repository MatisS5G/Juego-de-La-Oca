#include "Juego.h"
#include <iostream>
#include "Ronda.h"
#include "Turno.h"
#include <algorithm>
#include <random>


//FALTA:
/*
 * Retroceder la cantidad de casillas correspondientes cuando se pasa de 63.
 * En la clase casilla, idear la forma en la que vuelve a tirar si cae en una casilla Oca
 * Terminar la funcion IniciarJuego(), creando una nueva ronda en caso de que se siga jugando
*/

//Creacion de la partida
Juego::Juego(string n){
    this->NombrePartida = n;
}

//Carga de las configuraciones por defecto de la partida
void Juego::CargarPartida(){
    this->dadoOca.ElegirDado();
    this->Tablero.SetTablero();
}

//Carga de los jugadores para la partida, maximo de 4 jugadores, con nombre y posicion inicial en 0
void Juego::CargarJugadores(){
    int TotJugadores;
    string nombreJ;
    cout<<"ingrese la cantidad de jugadores(1/2/3/4):";
    cin>>TotJugadores;
    for (int i=0;i<TotJugadores;i++){
        cout << "ingrese el nombre del jugador " << i+1 << ": ";
        cin >> nombreJ;
        Ficha* jug = new Ficha(nombreJ);
        this->Jugadores.push_back(jug);
    }
}

//Eleccion del orden de juego para los jugadores
void Juego::SortearOrdenTurnos(){
    //vector de numeros para comprobar repetidos
    std::vector<int> numeros;

    //vector para almacenar a los jugadorse y su numero elegido
    std::vector<std::pair<int,Ficha*>> jugadoresYnumeros;

    //Eleccion de numeros por los jugadores
    cout<<"=== Eleccion de numeros para el orden de juego ==="<<endl;
    for (Ficha* j : this->Jugadores){
        int num;
        cout << j->Get_nombre() << endl;
        cout << "Elige un numero entre 1 y 4: ";
        cin >> num;

        //validacion simple para evitar repetidos
        while ((std::find(numeros.begin(),numeros.end(),num)) != numeros.end()){
            cout << "Ese numero ya fue elegido. Elige otro: ";
            cin >> num;
        }

        numeros.push_back(num);
        jugadoresYnumeros.push_back({num,j});
    }

    //Mezcla de numeros
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(jugadoresYnumeros.begin(),jugadoresYnumeros.end(),g);

    //Actualizar el vector con el orden nuevo y mostrar el mismo
    std::vector<Ficha*> NuevoOrdenJug;
    cout << "=== Orden del juego ===" << endl;
    int orden = 1;
    for (auto par : jugadoresYnumeros){
        cout << orden << "." << par.second->Get_nombre() << endl;
        cout << "Numero elegido: " << par.first << endl;
        NuevoOrdenJug.push_back(par.second);
        orden++;
    }
    delete this->Jugadores;
    this->Jugadores = NuevoOrdenJug;
}

//Desarollo del juego
void Juego::IniciarPartida(){

}

//Aviso de finalizacion de partida
void Juego::FinalizarPartida(){

}
