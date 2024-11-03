#pragma once
#include "Casilla.h"
class Tablero
{
public:
	int totalCasilla;
	Casilla* casillaInicial;
	Tablero(int CasillasUsuario);
	void generarCasillasEscalerasSerpientes(int maxCasillas);
	bool casillaEnUso(int posicion);
	~Tablero();
};

