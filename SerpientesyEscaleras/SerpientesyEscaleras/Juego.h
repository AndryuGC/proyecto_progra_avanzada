#pragma once
#include "Jugador.h"
#include "Tablero.h"
#include <iostream>
#include <string>
using namespace std;

class Juego
{
public:	
    Jugador jugadores[16];
    int totalJugadores;
    Tablero* tablero;
    int auxTurno;


    Juego(int casillasUsuario, string nombreJugadores[], int totalJugadores);
    void iniciarJuego();
    void turnoJugador();
    void lanzarDado();

};

