#pragma once
#include <iostream>
#include <string>
using namespace std;
class Jugador
{
public:
    string nombre;
    int posicion;

    Jugador();
    Jugador(string nombre, int posicionInicial);
    ~Jugador();

    void actualizarPosicion(int movimiento);
};

