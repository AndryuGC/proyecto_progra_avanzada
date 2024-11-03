#pragma once
class Casilla
{
public:
	bool esEscalera;
	bool esSerpiente;
	int casillaDestino;

	struct Node
	{
		int numero;
		bool esEscalera;
		bool esSerpiente;
		int casillaDestino;
		Node* siguienteCasilla;
	};

	Node* head;
	Casilla();
	void agregarCasilla(int numero);
	~Casilla();
};




