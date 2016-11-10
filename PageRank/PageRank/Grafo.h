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
	Nodo* getPagina(string);
	Nodo* getPaginaByNum(int);
	void agregarClickAPagina(int, Nodo*);
	void agregarAvisitados(Nodo*,Nodo*);
	void agregarAentradas(Nodo*,Nodo*);
	string mostrarGrafo();
	~Grafo(void);
};

