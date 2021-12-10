#include <iostream>
#include <cstdlib>
#include <string.h>

#include "funciones.h"
using namespace std;

void lanzardado12c (int DADOS12, int mj [ ] [6] [2], int juego, int turno)
{
    for (int x = 0; x < DADOS12; x++)
    {
        mj [juego] [turno] [x] = 1 + rand () % 12;
    }
}

void lanzardado6c (int mj [ ] [5] [11], int dadostock, int juego, int turno)
{
    for (int x = 0; x < dadostock; x++)
    {
        mj [juego] [turno] [x] = 1 + rand () % 6;
    }
}

int verificadadoapasar (int dadostockj, int dadoapasar, int Vdadosasumar [], int mj [ ] [5] [11], int juego, int turno, int valorobjetivoronda, int &cuentadados)
{
    int acu=0;
    cuentadados = 0;
    if (dadoapasar == 0)
    {
        return 6; // pasar el turno
    }
    if (dadoapasar > dadostockj)
    {
        cuentadados = 0;
        return 1; // pasar mensaje de que el valor ingresado era incorrecto y ya la cago
    }
    if (Vdadosasumar [dadoapasar] == 1)
    {
        cuentadados = 0;
        return 2; // pasar el mensaje de que ese valor ya lo habia ingresado y la cago
    }
    else
    {
        Vdadosasumar [dadoapasar-1] = 1;
    }
    for (int x=0; x < dadostockj; x++)
    {
        if (Vdadosasumar [x] == 1)
        {
           acu +=  mj [juego] [turno] [x];
           cuentadados++;
        }
    }
   if (acu > valorobjetivoronda)
   {
       cuentadados = 0;
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


bool validarnumero (char numeroavalidar [])
{
    for (int i=0; i < strlen(numeroavalidar); i++)
    {
        if (!(isdigit (numeroavalidar[i])))
        {
            return false;
        }
    }
    return true;
}
