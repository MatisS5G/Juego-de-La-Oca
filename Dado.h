#ifndef DADO_H
#define DADO_H
#include <vector>

class Dado{
protected:
    vector<int> caras;
public:
    Dado();
    void ElegirDado();
    int Lanzar();
};

#endif // DADO_H
