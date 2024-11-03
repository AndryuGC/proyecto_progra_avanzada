#include "Tablero.h"
#include "Casilla.h"
#include <cstdlib>
#include <random>
#include <string>
#include <iostream> 
using namespace std;

Tablero::Tablero(int CasillasUsuario) : totalCasilla(CasillasUsuario), casillaInicial(nullptr) {
	casillaInicial = new Casilla();

	for (int i = 0; i < totalCasilla; i++) {
		casillaInicial->agregarCasilla(i);
	}
	int maxCasillas = totalCasilla * 0.25;
}

void Tablero::generarCasillasEscalerasSerpientes(int maxCasillas) {
    int numEscaleras = 0;
	int numSerpientes = 0;

	random_device rd;  // Obtener una semilla aleatoria
	mt19937 gen(rd());  // Inicializar el generador

	while(numEscaleras + numSerpientes < maxCasillas){
		int cantidadFilas = totalCasilla / 6;
		for(int fila = 0; fila < cantidadFilas; fila++){ 
			int escalerasEnFila = 0;
			int serpientesEnFila = 0;
			int posFilaInicial = fila * 6;
			int posFilaFinal = posFilaInicial + 5;

			while((escalerasEnFila + serpientesEnFila) <= 3){ //escalera
				int posicionEscalera = posFilaInicial + (rand() % 6);

				if(!casillaEnUso(posicionEscalera)){
					int diferencia = posFilaFinal - posicionEscalera;
    				uniform_real_distribution<> dis(diferencia + 1, ((totalCasilla - 1) - posicionEscalera)); // Distribución uniforme entre 0 y 5
					int destinoEscalera = posicionEscalera + dis(gen);

					if(!casillaEnUso(destinoEscalera)){
						Casilla::Node* auxiliar = casillaInicial->head;
						for(int i = 1; i < posicionEscalera; i++){
							if(auxiliar->siguienteCasilla != nullptr){
								auxiliar = auxiliar->siguienteCasilla;
							}
						}
						auxiliar->esEscalera = true;
						auxiliar->casillaDestino = destinoEscalera;
						numEscaleras++;
						escalerasEnFila++;
					}
				}
			}
			//Agregar código para insertar serpientes
		}
	}
}

bool Tablero::casillaEnUso(int posicion){
	if(posicion < 0 || posicion > totalCasilla){
		return false;
	}
	Casilla::Node* aux = casillaInicial->head;
	for(int i = 1; i < posicion; i++){
		if(aux->siguienteCasilla != nullptr){
			aux = aux->siguienteCasilla;
		} else{
			return false;
		}
	}
	return aux->esEscalera || aux->esSerpiente;
}

Tablero::~Tablero(){
    //Destructor
}
