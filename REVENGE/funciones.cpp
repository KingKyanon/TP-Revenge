#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void lanzardado12c (int RONDAS,int DADOS12, int mj [ ] [RONDAS+1] [DADOS12], int juego, int turno)
{
    for (int x = 0, x < DADOS12, x++)
    {
        mj [juego] [turno] [x] = 1 + rand () % 12;
    }
}

void lanzardado6c (int RONDAS, int DADOSMAX, int mj [ ] [RONDAS ] [DADOSMAX], int dados, int juego, int turno)
{
    for (int x = 0, x < dados, x++)
    {
        mj [juego] [turno] [x] = 1 + rand () % 6;
    }
}

bool verificador (char opciones2)
