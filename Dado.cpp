#include "Dado.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//Metodo de carga para el tamanio del dado
void Dado::ElegirDado(){
    int TotCaras;
    cout<<"Ingrese la cantidad de caras del dado: ";
    cin>>TotCaras;
    for (int i=0;i<TotCaras;i++){
        this->caras.push_back(i+1);
    }
}

//Metodo para sacar cara superior del dado
int Dado::Lanzar(){
    int index = std::rand() % this->caras.size();
    return caras[index];
}
