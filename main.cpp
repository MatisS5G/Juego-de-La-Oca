#include <QCoreApplication>
#include "Juego.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Juego MiPartida;

    MiPartida.CargarPartida();

    MiPartida.CargarJugadores();

    MiPartida.SortearOrdenTurnos();

    MiPartida.IniciarPartida();

    return a.exec();
}
