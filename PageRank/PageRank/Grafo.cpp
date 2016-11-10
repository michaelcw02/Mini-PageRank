#include "Grafo.h"


Grafo::Grafo(void)
{
	nodos = list<Nodo*>();
}

void Grafo::agregar(Nodo * n){
	nodos.push_back(n);
}

bool Grafo::existePgina(string nom){
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end()){
		if(nom == (*d++)->getNombre())
			return true;
	}
	return false;
}

Nodo * Grafo::getPagina(string nom){
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end()){
		if(nom == (*d)->getNombre())
			return (*d);
		else
			(d++);
	}
	return NULL;
}

Nodo* Grafo::getPaginaByNum(int num) {
	list<Nodo*>::iterator d = nodos.begin();
	for (int i = 1; i <= num && d != nodos.end(); i++, d++);
	return (d != nodos.end()) ? (*d) : NULL;
}

void Grafo::agregarClickAPagina(int num, Nodo* nodoFuente) {
	Nodo* nodoDestino = getPaginaByNum(num);
	nodoFuente->enviarClick(nodoDestino);
}

string Grafo::mostrarGrafo(){
	stringstream s;
	list<Nodo*>::iterator d = nodos.begin();
	int i = 1;
	while(d != nodos.end())
		s<<i++<<". "<<(*d++)->toString();
	return s.str();
}

void Grafo::agregarAvisitados(Nodo * actual,Nodo * saliente){
	actual->agregarNodo(saliente);
}

void Grafo::agregarAentradas(Nodo * actual,Nodo * entrante){
	actual->agregarEntranda(entrante);
}

Grafo::~Grafo(void)
{
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end())
		delete(*d++);
}
