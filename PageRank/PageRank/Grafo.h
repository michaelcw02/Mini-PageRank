#pragma once
#include "Nodo.h"
class Grafo
{
private:
	list<Nodo*> nodos;
public:
	Grafo(void);
	void agregar(Nodo*);
	bool existePgina(string);
	void setNoVisitados();
	Nodo* getPagina(string);
	Nodo* getPaginaByNum(int, Nodo*);
	void agregarClickAPagina(int, Nodo*);
	void agregarAvisitados(Nodo*,Nodo*);
	void agregarAentradas(Nodo*,Nodo*);
	string mostrarGrafoSinPagActual(string);
	list<Nodo*> getNodos();
	string mostrarGrafo();
	~Grafo(void);
};

