#pragma once
#include "Grafo.h"
#include "Interfaz.h"
class Control
{
private:
	Grafo * graf;
public:
	Control(void);
	void iniciarBuscador();
	void registrarPagina(Nodo * n);
	string mostrarHistorial();
	string paginasRecientes();
	~Control(void);
};

