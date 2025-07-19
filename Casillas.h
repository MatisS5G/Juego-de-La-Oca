#ifndef CASILLAS_H
#define CASILLAS_H
#include <string>
#include "Ficha.h"

//Clase abstracta de las casillas
class casilla{
protected:
    int numeroCas;
    string nombreCas;
public:
    casilla(int n, string nom);
    virtual aplicarRegla(Ficha* jugador) = 0;
    int GetNumeroC(){
        return this->nombreCas;
    }
};

//Definicion de cada casilla heredando de casilla
class normal : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        cout << jugador->Get_nombre() << "Cae en casilla normal" << endl;
    }
};

class Oca : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        int nuevaPosicion = (jugador->GetPosicion() + 9);
        if (nuevaPosicion <= 63){
            jugador->MoverJugador(nuevaPosicion);
        }
        //FALTA VOLVER A TIRAR
    }
};

class puente : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        jugador->MoverJugador(12);
    }
};

class posada : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        //PIERDE UN TURNO
        jugador->PerderTurnos(1);
        jugador->Penalizar();
    }
};

class pozo : protected casilla{
public:
    Ficha* JugadorAtrapado = NULL;
    pozo();
    void aplicarRegla(Ficha* jugador) override{
        //NO PUEDE MOVERSE HASTA QUE OTRO JUGADOR CAIGA EN LA MISMA
        jugador->Atrapar();
        if (this->JugadorAtrapado == NULL){
            this->JugadorAtrapado = jugador;
        }else{
            this->JugadorAtrapado->Liberar();
            this->JugadorAtrapado = jugador;
        }
    }
};

class laberinto : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        jugador->MoverJugador(30);
    }
};

class carcel : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        //PIERDE DOS TURNOS
        jugador->PerderTurnos(2);
        jugador->Penalizar();
    }
};

class calavera : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        jugador->MoverJugador(1);
    }
};

class JardinDeLaOca : protected casilla{
    void aplicarRegla(Ficha* jugador) override{
        cout << jugador->Get_nombre() << "Ah ganado la partida" << endl;
    }
};

#endif // CASILLAS_H
