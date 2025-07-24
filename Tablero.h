#ifndef TABLERO_H
#define TABLERO_H

#include "Casillas.h"
#include <vector>

using namespace std;


// ========================================================
// Clase Tablero
// Representa el tablero del Juego de la Oca:
// - casillas en forma de espiral
// Métodos:
//   Constructor y destructor para uso de memoria dinámica
//   Inicialización de casillas con valores por defecto
//   Búsqueda de casilla por su número
// ========================================================


class Tablero{
protected:
    vector<Casilla*> casillas;
public:
    Tablero();

    // Método que configura y setea todas las casillas del tablero
    void SetTablero();

    // Devuelve un puntero a la casilla cuyo número coincide con el recibido por parámetro
    Casilla* FindCasilla(int numeroCasilla);

    // Destructor para liberar memoria de las casillas creadas dinámicamente

};

#endif // TABLERO_H
