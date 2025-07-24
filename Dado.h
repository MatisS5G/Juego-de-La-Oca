#ifndef DADO_H
#define DADO_H
#include <vector>
using namespace std;
// ===============================================================
// Clase Dado
// Representa un dado en el juego:
// - numeros de sus caras
// Métodos:
//  ElegirDado(): define la cantidad de caras del dado
//  Lanzar(): devuelve un numero aleatorio de las caras(cara superior)
// ===============================================================

class Dado{
protected:
    vector<int> caras;
public:
    Dado();
    void ElegirDado();
    int Lanzar();
};

#endif // DADO_H
