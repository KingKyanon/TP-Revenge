#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    ///Variables y constantes
    int opciones = 0, JUEGOSALM=5  DADOSMAX=11, RONDAS=5, DADOS12=2, contadorjuego=-1, contadorturno = 0, dadostockj1 = 0, dadostockj2 = 0,valorobjetivoronda = 0;
    char opciones2;
    bool verificador=false, verificadornombre=false;
    int MtiradasD6J1 [JUEGOSALM][RONDAS][DADOSMAX] = { };   // para almacenar las tiradas de 6 caras del Jugador 1
    int MtiradasD6J2 [JUEGOSALM][RONDAS][DADOSMAX]= { };   // para almacenar las tiradas de 6 caras del Jugador 2
    int MtiradasD12 [JUEGOSALM][RONDAS+1][DADOS12]= { };   // para almacenar las tiradas para definir quien inicia y las del valor objetivo
    int VpuntajeJ1 [JUEGOSALM]= { };                       // para almacenar los puntajes finales del Jugador 1
    int VpuntajeJ2 [JUEGOSALM] = { };                       // para almacenar los puntajes finales del Jugador 2
    int Vdadosasumar [DADOSMAX] = { };                   // para almacenar los dados que va ingresando para pasar
    string nombre1, nombre2, Vjugador1[JUEGOSALM], Vjugador2[JUEGOSALM] ;
    // TODO: poner la semilla del randomizador
    // TODO: ver como usar la libreria conio.h para cambiar colores de las fuentes y el fondo
    while (opciones != 4)
    {
        verificador = false;
        opciones = 0;
        cout << "###############################" << endl;
        cout << "Seleccione que desea realizar: " << end << "1 - Jugar" << endl << "2 - Estadisticas" << endl << "3 - Creditos" << endl << "4- Salir" << endl << "Seleccion: ";
        while (verificador == false)
        {
            cin >> opciones;
            if (opciones>= 1 && opciones <=4 )
            {
                verificador = true;
            }
            else
            {
                cout << "La opcion ingresada no es correcta, ingresela nuevamente (recuerde que solo puede seleccionar del 1 al 4): ";
            }
        }
        ///menu con las opciones
       switch (opciones)
       {
            //1- Jugar
           case 1:
            // aumentar contador de juego, o volver al mas bajo
            contadorjuego++;
            if (contadorjuego > 4 )
            {
                contadorjuego = 0;
            }
            // ingresar nombre de los jugadores
            verificadornombre == false;
            while (verificadornombre == false)
            {
                cout << "###############################" << endl;
                cout << "Ingrese el primer nombre: ";
                cin >> nombre1;
                cout << endl << "Ingrese el segundo nombre: ";
                cin >> nombre2;
                cout << endl << endl << "Los nombres ingresados fueron: " << nombre1 << " y " << nombre2 << ". Son correctos? (S/N): ";
                verificador = false;
                while (verificador == false)
                {
                    cin opciones2;
                  if (opciones2 == 's' || opciones2 == 'S')
                  {
                      verificador = true;
                      verificadornombre = true;
                  }
                  else
                  {
                       if (opciones2 == 'n' || opciones2 = 'N')
                      {
                          verificador = true;
                          verificadornombre = false;
                      }
                      else
                      {
                          cout << "La opcion ingresada no es correcta, ingresela nuevamente (recuerde que solo puede seleccionar S o N): ";
                      }
                  }
                }
            }
            // definir el orden en que jugaran
            cout << endl << "--------------------------------------------------------------";
            cout << endl << "ahora se definira el orden en que jugaran" << endl;
            do
            {
                cout << endl << "Presione enter para continuar";
                getchar();
                contadorturno = 0;
                verificador = false;
                lanzardado12c (RONDAS, DADOS12, MtiradasD12, contadorjuego, contadorturno);
                cout << "------------";
                cout << endl << nombre1 << " obtuvo un: " << MtiradasD12 [contadorjuego][contadorturno][0];
                cout << endl << nombre2 << " obtuvo un: " << MtiradasD12 [contadorjuego][contadorturno][1];
                cout << "------------";
                if (MtiradasD12 [contadorjuego][contadorturno][0] != MtiradasD12 [contadorjuego][contadorturno][1])
                {
                   verificador = true;
                }
                else
                {
                    cout << endl << "parece que hubo un empate, deberan tirar nuevamente"
                }
            }
            while (verificador == false);
            if (MtiradasD12 [contadorjuego][contadorturno][0] > MtiradasD12 [contadorjuego][contadorturno][1])
            {
                Vjugador1 [contadorjuego] = nombre1;
                Vjugador2 [contadorjuego] = nombre2;
            }
            else
            {
                Vjugador1 [contadorjuego] = nombre2;
                Vjugador2 [contadorjuego] = nombre1;
            }
            /// repartir dados stock, poner contador de turnos en 1
            dadostockj1 = dadostockj2 = 6;
            contadorturno++
            cout << endl << "################ AHORA COMIENZA EL JUEGO ################";
            /// REPETIR 5 VECES
            for (int i=0, i<RONDAS, i++)
            {
                // mostrar numero de ronda, nombre de quien esta jugando, puntaje acumulado de ambos, cantidad Dados de Stock de ambos
                cout << endl << "-- -- -- -- -- -- -- -- -- --";
                cout << endl << "Ronda N°: " << contadorturno << endl;
                cout << Vjugador1 [contadorjuego] << " - puntaje: " << VpuntajeJ1 [contadorjuego] << " - Dados de Stock: " << dadostockj1;
                cout << Vjugador2 [contadorjuego] << " - puntaje: " << VpuntajeJ2 [contadorjuego] << " - Dados de Stock: " << dadostockj2;
                cout << endl << "-- -- -- -- -- -- -- -- -- --";
                // obtener el Valor Objetivo de la ronda haciendo que el Jugador 1 lance 2D12
                cout << endl << Vjugador1 [contadorjuego] << " por favor tira los dados de 12 caras para determinar el valor objetivo de esta ronda";
                cout << endl << "Presione enter para continuar";
                getchar();
                system ("cls");
                lanzardado12c (RONDAS, DADOS12, MtiradasD12, contadorjuego, contadorturno);
                // agregar o actualizar a lo que se muestra el Valor Objetivo
                valorobjetivoronda = MtiradasD12 [contadorjuego] [contadorturno] [0] + MtiradasD12 [contadorjuego] [contadorturno] [1]
                cout << endl << "-- -- -- -- -- -- -- -- -- --";
                cout << endl << "Ronda N°: " << contadorturno << endl;
                cout << Vjugador1 [contadorjuego] << " - puntaje: " << VpuntajeJ1 [contadorjuego] << " - Dados de Stock: " << dadostockj1;
                cout << Vjugador2 [contadorjuego] << " - puntaje: " << VpuntajeJ2 [contadorjuego] << " - Dados de Stock: " << dadostockj2;
                cout << endl << "salieron : " << MtiradasD12 [contadorjuego] [contadorturno] [0] << " y " << MtiradasD12 [contadorjuego] [contadorturno] [1] << " / VALOR OBJETIVO: " << valorobjetivoronda;
                cout << endl << "-- -- -- -- -- -- -- -- -- --";
                // lanzar Dados de Stock del Jugador 1
                cout << endl << endl << "Por favor, " << Vjugador1 [contadorjuego] << " lanza tus dados de stock";
                cout << endl << "Presione enter para continuar";
                getchar();
                lanzardado6c (RONDAS, DADOSMAX, MtiradasD6J1, dadostockj1, contadorjuego, contadorturno);
                // mostrar valores de los dados
                cout << endl << "resultados: ";
                for (int x=0, x<dadostockj1, x++)
                {
                    cout << endl << "dado N° " << x+1 << ": " << MtiradasD6J1 [contadorjuego] [contadorturno] [x];
                    Vdadosasumar [x] = 0;
                }
                /// Dar chance al Jugador 1 que verifique si puede sumar el Valor Objetivo
                cout << endl << "------";
                cout << endl << "selecciona que dados utilizaras para llegar al VALOR OBJETIVO, deberas seleccionar de a 1 dado a la vez. Presiona 0 para terminar o pasar" << endl <<"------";
                for (int y=0, y<dadostockj1, y++)
                {
                    cout << endl << "ingrese el numero de dador a sumar: ";
                    verificador = false;
                    while (verificador == false)
                    {
                      cin >> dadoapasar;
                       if (isdigit (dadoapasar) == 1)
                        {
                           verificador = true;
                        }
                        else
                        {
                            cout << endl << "No parecia necesario aclararlo, pero solo puede ingresar numeros. Intentelo nuevamente";
                        }
                    }
                    switch (verificadadoapasar(dadostockj1, dadoapasar, Vdadosasumar, RONDAS, DADOSMAX, MtiradasD6J1, contadorjuego, contadorturno, valorobjetivoronda) )
                    {
                    case 1:
                        cout << endl << "no deberias haber ingresado un numero de dado mayor a la cantidad de dados que tenias. PERDISTE EL TURNO";
                        y = dadostockj1;
                        for (int r=0, r<dadostockj1, r++)
                        {
                            Vdadosasumar [r] = 0
                        }
                    break;
                    case 2:
                        cout << endl << "no deberias haber ingresado un numero de dado que ya habias utilizado. PERDISTE EL TURNO";
                        y = dadostockj1;
                        for (int r=0, r<dadostockj1, r++)
                        {
                            Vdadosasumar [r] = 0
                        }
                    break;
                    case 3:
                        cout << endl << "superaste el Valor Objetivo. PERDISTE EL TURNO";
                        y = dadostockj1;
                        for (int r=0, r<dadostockj1, r++)
                        {
                            Vdadosasumar [r] = 0;
                        }
                    break;
                    case 4:
                        cout << endl << "Todavia no llegaste al Valor Objetivo";
                    break;
                    case 5:
                        cout << endl << "Llegaste al Valor Objetivo";
                        y = dadostockj1;
                    break;
                    }
                }

                    ///SI - calcular puntaje
                    ///SI - sumar puntaje
                    ///SI - enviar Dados Elejidos al jugador 2
                    ///SI - verificar si el Jugador 1 todavia tiene dados, en caso contrario sumar 10.000 puntos y terminar el juego
                    ///NO - en caso que el Jugador 2 tenga 2 o mas dados, el jugador 1 recibira un Dado de Stock del jugador 2
                /// actualizar puntaje acumulado del Jugador 1 y cantidad de Dados de Stock de ambos jugadores
                /// lanzar Dados de Stock del Jugador 2
                /// mostrar valores de los dados
                /// Dar chance al Jugador 2 que verifique si puede sumar el Valor Objetivo
                    ///SI - calcular puntaje
                    ///SI - sumar puntaje
                    ///SI - enviar Dados Elejidos al jugador 1
                    ///SI - verificar si el Jugador 2 todavia tiene dados, en caso contrario sumar 10.000 puntos y terminar el juego
                    ///NO - en caso que el Jugador 1 tenga 2 o mas dados, el jugador 2 recibira un Dado de Stock del jugador 1
                /// actualizar puntaje acumulado del Jugador 1 y cantidad de Dados de Stock de ambos jugadores
                /// aumentar contador de ronda
            }
            /// FIN REPETICION
            break;
            ///2- Mostrar estadisticas
            case 2:
            ///recorrer y mostrar las matrices donde guardamos los puntajes y las tiradas de cada partida
            break;
            //3- Creditos
            case 3:
                cout << "############################################" << endl;
                cout << "Tecnicatura Universitaria en Programacion UTN gral. pacheco" << endl << "Laboratorio de Comnputacion 1, ciclo 2021, segundo cuatrimestre" << endl << "INTEGRANTES DEL GURPO 9:" << endl << "Aguilera, Orlando / Legajo 25411" << endl << "Bianco Sausto, Alejandro J / Legajo 25648" << endl << "Callegari, Sebastian / Legajo 24163" << endl << "Rojas, Julieta / Legajo 21608" << endl;
                cout << "############################################" << endl;
            break;
        //4- Salir
            case 4:
                cout << "###############################" << endl;
                verificador = false;
                cout << "Esta seguro que desea salir?, si sale perdera todas las estadisticas almacenadas" << endl <<" (S/N): " << endl;
                while (verificador == false)
                {
                  cin opciones2;
                  if (opciones2 == 's' || opciones2 == 'S')
                  {
                      return 0;
                  }
                  else
                  {
                      if (opciones2 == 'n' || opciones2 = 'N')
                      {
                          verificador = true;
                      }
                      else
                      {
                          cout << "La opcion ingresada no es correcta, ingresela nuevamente (recuerde que solo puede seleccionar S o N): ";
                      }

                  }
                }
            break;
       }

    }
    return 0;
}
