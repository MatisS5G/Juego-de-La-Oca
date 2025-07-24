#include "Tablero.h"
#include "Casillas.h"

#include <vector>
#include <algorithm>

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

Tablero::Tablero(){

}

// Método que crea y carga todas las casillas del tablero
void Tablero::SetTablero(){
    int TotalCasillas = 63;

    for (int i=1;i<=TotalCasillas;i++){
        // Casillas de Oca
        if (i == 9 ||i == 18 ||i == 27 ||i == 36 ||i == 45 ||i == 54) {
            casillas.push_back(new Oca(i));

        // Casilla Puente
        }else if (i == 6){
            casillas.push_back(new puente(i));

        // Casilla Posada
        }else if (i == 19){
            casillas.push_back(new posada(i));

        // Casilla Pozo
        }else if (i == 31){
            casillas.push_back(new pozo(i));

        // Casilla Laberinto
        }else if (i == 42){
            casillas.push_back(new laberinto(i));

        // Casilla Carcel
        }else if (i == 56){
            casillas.push_back(new carcel(i));

        // Casilla Calavera
        }else if (i == 58){
            casillas.push_back(new calavera(i));

        // Casilla Jardin de la Oca
        }else if (i == 63){
            casillas.push_back(new JardinDeLaOca(i));

        // Casilla Normal
        }else{
            casillas.push_back(new normal(i));
        }
    }
}


// Método que busca y devuelve un puntero a la casilla con el número pasado por parámetro
Casilla* Tablero::FindCasilla(int numeroCasilla){

    auto it = find_if(this->casillas.begin(),this->casillas.end(),[numeroCasilla](Casilla* c){
    return  numeroCasilla == c->GetNumeroC();
    });

    // Si encuentra la casilla devuelve su puntero, si no retorna un puntero nulo
    if (it != this->casillas.end()) return *it;
    return nullptr;
}
