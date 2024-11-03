#include "Jugador.h"

Jugador::Jugador() : nombre(""), posicion(0){}
Jugador::Jugador(string nombre, int posicionInicial) : nombre(nombre), posicion(posicionInicial) {}

void Jugador::actualizarPosicion(int movimiento){
    posicion = posicion + movimiento;
}

Jugador::~Jugador(){}