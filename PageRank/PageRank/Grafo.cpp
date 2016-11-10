#include "Grafo.h"


Grafo::Grafo(void)
{
	nodos = list<Nodo*>();
}

void Grafo::agregar(Nodo * n){
	nodos.push_back(n);
}


string Grafo::mostrarGrafo(){
	stringstream s;
	list<Nodo*>::iterator d = nodos.begin();
	int i = 1;
	while(d != nodos.end())
		s<<i++<<". "<<(*d++)->toString();
	return s.str();
}

Grafo::~Grafo(void)
{
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end())
		delete(*d);
}
