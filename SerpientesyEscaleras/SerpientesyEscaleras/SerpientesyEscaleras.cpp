// SerpientesyEscaleras.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Casilla.h"
#include "Juego.h"
#include "Jugador.h"
#include "Tablero.h"
#include <cstdlib>
#include <random>
#include <string>
#include <iostream> 

using namespace std;
int main()
{
    random_device rd;  // Obtener una semilla aleatoria
    mt19937 gen(rd());  // Inicializar el generador
    uniform_real_distribution<> disa(0.0, 5.0); // Distribución uniforme entre 0 y 5

    int posicionCasilla = rand() % 24; // numero entre 0 y el numero de casillas
	int filaActual = posicionCasilla / 6;
	int cantidadFilas = 24/ 6;

    int fila = 2;
    int posFilaInicial = fila * 6;
	int posFilaFinal = posFilaInicial + 5;

    int posicionEscalera = posFilaInicial + disa(gen);
	int diferencia = posFilaFinal - posicionEscalera;

    int diferenciaDebug = diferencia + 1;
    int posMax = 24 - posicionEscalera;

    uniform_real_distribution<> dist(diferencia + 1, (24 - posicionEscalera)); // Distribución uniforme entre 0 y 5+
    int numeroGenerado = dist(gen);
	int destinoEscalera = posicionEscalera + numeroGenerado;
    
    string nombresJugadores[] = { "Alice", "Bob", "Carlos" };
    int totalJugadores = 3; // Cantidad de nombres en el arreglo
    Juego* objJuego = new Juego(30, nombresJugadores, totalJugadores);
    objJuego->lanzarDado();

	cout << "Prueba Escaleras" << endl;
	cout << posFilaInicial << " posFilaInicial" << endl;
	cout << posFilaFinal << " posFilaFinal" << endl;
	cout << posicionEscalera << " posEscalera" << endl;
	cout << diferencia << " Diferencia" << endl;
    cout << destinoEscalera << " Destino Escalera" << endl;

    cout << numeroGenerado << " Numero generado" << endl;

    cout << diferenciaDebug << " Diferencia Debug" << endl;
    cout << posMax << " Fin" << endl;
}


