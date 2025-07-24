#include "Dado.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ===============================================================
// Clase Dado
// Métodos:
//  ElegirDado(): define la cantidad de caras del dado
//  Lanzar(): devuelve un numero aleatorio de las caras(cara superior)
// ===============================================================


Dado::Dado(){

}

void Dado::ElegirDado(){

    int TotCaras;
    cout<<"Ingrese la cantidad de caras del dado: ";
    cin>>TotCaras;

    // Carga las caras del dado con valores consecutivos(1 a TotCaras)
    for (int i=0;i<TotCaras;i++){
        this->caras.push_back(i+1);
    }
}
int Dado::Lanzar(){
    // Inicia la semilla de aleatoriedad (solo si no se hizo antes)
    static bool seeded = false;
    if (!seeded){
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    // Genera un indice aleatorio dentro del rango de caras
    int index = std::rand() % this->caras.size();

    // Devuelve el valor de la cara correspondiente
    return this->caras[index];
}
