#pragma once
#include "Nodo.h"
class Grafo
{
private:
	list<Nodo*> nodos;
public:
	Grafo(void);
	void agregar(Nodo*);
	string mostrarGrafo();
	~Grafo(void);
};

