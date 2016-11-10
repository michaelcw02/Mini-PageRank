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
	Nodo * getPagina(string);
	string mostrarHistorial();
	string paginasRecientes();
	void definirOpcion(string, Nodo *);
	void crearPaginaApartirDeActual(string,	Nodo*);
	void accederDesdePaginaActual(string,Nodo * ); //Se esta en una pagina y se quiere ir a otra 
	bool isDigit(string);
	bool isAcceder(string);
	~Control(void);
};

