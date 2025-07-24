#ifndef CASILLAS_H
#define CASILLAS_H

#include <string>
#include <iostream>

#include "Ficha.h"

using namespace std;

// Clase abstracta que representa una casilla del tablero
class Casilla{
protected:
    int numeroCas;      // Número de la casilla
    string nombreCas;   // Nombre de la casilla
public:
    // Constructor que inicializa nombre y número de la casilla
    Casilla(int n, string nom){
        this->numeroCas = n;
        this->nombreCas = nom;
    }


    // Método abstracto que aplica la regla correspondiente a la casilla
    virtual void aplicarRegla(Ficha* jugador) = 0;

    // Indica si la casilla es una Oca (falso por defecto)
    virtual bool esOca() {return false;}

    // Devuelve el numero de la casilla
    int GetNumeroC(){
        return this->numeroCas;
    }

    // Devuelve el nombre de la casilla
    string GetNombre() {
        return this->nombreCas;
    }

    ~Casilla(){}
};


// Casilla Normal: No tiene ningun efecto especial
class normal : public Casilla{
public:
    normal(int n) : Casilla(n,"Normal"){}
    void aplicarRegla(Ficha* jugador) override{
        cout << jugador->Get_nombre() << "Cae en casilla normal" << endl; // Muestra mensaje cuando un jugador cae en ella
    }
};


// Casilla Oca: avanza a la siguiente Oca y vuelve a tirar
class Oca : public Casilla{
public:
    Oca(int n) : Casilla(n,"Oca"){}
    void aplicarRegla(Ficha* jugador) override{
        cout << jugador->Get_nombre() << "cae en casilla Oca" << endl;
        // Si no es la última Oca (pos 54), avanza 9 posiciones
        if (this->GetNumeroC() != 54){
            int nuevaPosicion = (jugador->GetPosicion() + 9);
            jugador->MoverJugador(nuevaPosicion);
        }else{
            cout << "El jugador cayo en la ultima Oca, por lo que solo vuelve a tirar." << endl;
        }
    }

    // Sobrescribe la función para indicar que esta casilla es una Oca
    bool esOca() override {return true;}
};


// Casilla Puente: Mueve al jugador a la casilla 12
class puente : public Casilla{
public:
    puente(int n) : Casilla(n,"Puente"){}
    void aplicarRegla(Ficha* jugador) override{
        jugador->MoverJugador(12);
    }
};


// Casilla posada: El jugador pierde un turno y queda penalizado
class posada : public Casilla{
public:
    posada(int n) : Casilla(n,"Posada"){}
    void aplicarRegla(Ficha* jugador) override{
        jugador->PerderTurnos(1);
        jugador->Penalizar();
    }
};


// Casilla Pozo: atrapa al jugador hastaq que otro caiga en la misma casilla
class pozo : public Casilla{
private:
    Ficha* JugadorAtrapado = nullptr; // Jugador actualmente atrapado
public:
    pozo(int n) : Casilla(n,"Pozo"){}
    void aplicarRegla(Ficha* jugador) override{
        cout << jugador->Get_nombre() << " cae en casilla Pozo" << endl;
        jugador->Penalizar();
        if (this->JugadorAtrapado == nullptr){
            this->JugadorAtrapado = jugador;
            cout << jugador->Get_nombre() << " queda atrapado en el pozo" << endl;
        }else{
            cout << JugadorAtrapado->Get_nombre() << " queda liberado del Pozo" << endl;
            this->JugadorAtrapado->Liberar();
            this->JugadorAtrapado = jugador;
            cout << jugador->Get_nombre() << " queda atrapado en el pozo" << endl;
        }
    }
};


// Casilla Laberinto: Mueve al jugador a la casilla 30
class laberinto : public Casilla{
public:
    laberinto(int n) : Casilla(n,"Laberinto"){}
    void aplicarRegla(Ficha* jugador) override{
        //cout indicando lo que pasa
        jugador->MoverJugador(30);
    }
};


// Casilla Cárcel: El jugador pierde dos turnos y queda penalizado
class carcel : public Casilla{
public:
    carcel(int n) : Casilla(n,"Carcel"){}
    void aplicarRegla(Ficha* jugador) override{
        //cout indicando lo que pasa
        jugador->PerderTurnos(2);
        jugador->Penalizar();
    }
};


// Casilla Calavera: El jugador vuelve al inicio (casilla 1)
class calavera : public Casilla{
public:
    calavera(int n) : Casilla(n,"Calavera"){}
    void aplicarRegla(Ficha* jugador) override{
        // cout indicando lo que pasa
        jugador->MoverJugador(1);
    }
};


// Casilla Jardín de la Oca: El jugador gana la partida
class JardinDeLaOca : public Casilla{
public:
    JardinDeLaOca(int n) : Casilla(n,"Jardin de La Oca"){}
    void aplicarRegla(Ficha* jugador) override{
        cout << jugador->Get_nombre() << "Ah ganado la partida" << endl;
    }
};

#endif // CASILLAS_H
