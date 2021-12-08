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

void lanzardado6c (int RONDAS, int DADOSMAX, int mj [ ] [RONDAS ] [DADOSMAX], int dadostock, int juego, int turno)
{
    for (int x = 0, x < dadostock, x++)
    {
        mj [juego] [turno] [x] = 1 + rand () % 6;
    }
}

int verificadadoapasar (int dadostockj, int dadoapasar, int Vdadosasumar [], int RONDAS, int DADOSMAX, int mj [ ] [RONDAS ] [DADOSMAX], int juego, int turno, int valorobjetivoronda)
{
    int acu=0
    if (dadoapasar > dadostockj)
    {
        return 1; // pasar mensaje de que el valor ingresado era incorrecto y ya la cago
    }
    if (Vdadosasumar [dadoapasar] == 1)
    {
        return 2; // pasar el mensaje de que ese valor ya lo habia ingresado y la cago
    }
    else
    {
        Vdadosasumar [dadoapasar] = 1;
    }
    for (int x=0, x < dadostockj, x++)
    {
        if (Vdadosasumar [x] == 1)
        {
           acu +=  mj [juego] [turno] [x];
           if (acu > valorobjetivoronda)
           {
               return 3; // pasar el mensaje de que se paso y la cago
           }
           else
           {
               if (acu == valorobjetivoronda)
               {
                   return 5; // pasar el mensaje de que llego al VALOR OBJETIVO
               }
               else
               {
                   return 4; // pasar el mensaje que todavia no llego al VALOR OBJETIVO
               }
           }
        }
    }
}
