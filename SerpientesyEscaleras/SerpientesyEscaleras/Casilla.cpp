#include "Casilla.h"
Casilla::Casilla() : esEscalera(false), esSerpiente(false), casillaDestino(-1), head(nullptr) {}
void Casilla::agregarCasilla(int numero) {
    Node* nuevaCasilla = new Node();
    nuevaCasilla->numero = numero;
    nuevaCasilla->siguienteCasilla = nullptr;

    if(head == nullptr){
        head = nuevaCasilla;
    }else{
        Node* aux = head;
        while(aux->siguienteCasilla != nullptr){
            aux = aux->siguienteCasilla;
        }
        aux->siguienteCasilla = nuevaCasilla;
    }
}

Casilla::~Casilla(){
    Node* aux = head;
    while(aux){
        Node* siguiente = aux->siguienteCasilla;
        delete aux;
        aux = siguiente;
    }
}