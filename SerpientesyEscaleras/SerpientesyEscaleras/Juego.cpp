#include "Juego.h"
#include "Jugador.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

Juego::Juego(int casillasUsuario, string nombreJugadores[], int totalJugadores) : totalJugadores(totalJugadores), auxTurno(0){
    tablero = new Tablero(casillasUsuario);
    for(int i = 0; i < totalJugadores; i++){
        jugadores[i] = Jugador(nombreJugadores[i], 0);
    }
}
void Juego::iniciarJuego(){
    //Método
}
void Juego::turnoJugador(){
    //Método de turno
}
void Juego::lanzarDado(){
    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<> lanzamientodado(1, 6);

    int resultadoDado = lanzamientodado(gen);
    cout << "Resultado del Dado Lanzado: " << resultadoDado << endl;
}