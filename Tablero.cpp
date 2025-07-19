#include "Tablero.h"

//Metodo para cargar todas las casillas del tablero
void tablero::SetTablero(){
    int TotalCasillas = 63;
    for (int i=0;i<TotalCasillas;i++){
        if (i == 8 ||i == 17 ||i == 26 ||i == 35 ||i == 44 ||i == 53) {
            casillas.push_back(new Oca(i));
        }else if (i == 5){
            casillas.push_back(new puente(i));
        }else if (i == 18){
            casillas.push_back(new posada(i));
        }else if (i == 30){
            casillas.push_back(new pozo(i));
        }else if (i == 41){
            casillas.push_back(new laberinto(i));
        }else if (i == 55){
            casillas.push_back(new carcel(i));
        }else if (i == 57){
            casillas.push_back(new calavera(i));
        }else if (i == 62){
            casillas.push_back(new JardinDeLaOca(i));
        }else{
            casillas.push_back(new normal(i));
        }
    }
}

casilla* tablero::FindCasilla(int numeroCasilla){
    return __find_if(this->casillas.begin(),this->casillas.end(),[numeroCasilla](const casilla& c){
    return  numeroCasilla == c.GetNumeroC();
    });
}
