#include "Turno.h"
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


// Constructor: Recibe un puntero a la ficha que le corresponde el turno
Turno::Turno(Ficha* jug){
    this->jugador = jug;
}


// Método en el cual se juega el turno
// - si el jugador no esta penalizado tira el Dado y se mueve
// - aplica al jugador la regla de la casilla donde cae
void Turno::JugarTurno(Tablero* tab, Dado* dado){
    Casilla* casAux = nullptr;

    do{

        if (!(this->jugador->Estado())){

            int NuevaPosicion = this->jugador->GetPosicion();
            NuevaPosicion += this->jugador->TirarDado(dado);

            // Verifica si excede el limite del tablero, y retrocede la cantidad que se pasa
            if (NuevaPosicion > 63){
                int retroceder = NuevaPosicion - 63;
                NuevaPosicion = 63 - retroceder;
            }

            this->jugador->MoverJugador(NuevaPosicion);

            casAux = tab->FindCasilla( this->jugador->GetPosicion() );
            casAux->aplicarRegla(this->jugador);

        }else{

            // Si esta penalizado por perder turnos, solo se le resta uno (simulando que paso un turno sin jugar)
            if (jugador->GetTurnoPerdidos() > 0) jugador->CumplirTurno();//funcion para restar turnos;
            cout << endl << "El jugador " << jugador->Get_nombre() << " se encuentra penalizado" << endl;
        }

    }while(casAux != nullptr && casAux->esOca()); // Si la casilla es Oca tiene que volver a tirar
}
