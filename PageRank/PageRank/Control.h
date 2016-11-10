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
	void agregarDesde(Nodo * n); ///Agrega un nodo a outbounds desde una pagina actual
	bool paginaExistente(string);
	string mostrarHistorial();
	string paginasRecientes();
	~Control(void);
};

