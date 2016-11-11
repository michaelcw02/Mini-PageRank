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

Nodo* Grafo::getPaginaByNum(int num, Nodo* nodoActual) {
	list<Nodo*>::iterator d = nodos.begin();
	for(int i = 0; i < num; i++, d++) {
		if ((*d) == nodoActual)
			d++;
		if(i == num -1 && d != nodos.end())
			return (*d);
	}
	return NULL;
}

void Grafo::agregarClickAPagina(int num, Nodo* nodoFuente) {
	Nodo* nodoDestino = getPaginaByNum(num, nodoFuente);
	nodoFuente->enviarClick(nodoDestino);
}

list<Nodo*> Grafo::getNodos(){
	return nodos;
}

string Grafo::mostrarGrafo(){
	stringstream s;
	list<Nodo*>::iterator d = nodos.begin();
	int i = 1;
	while(d != nodos.end())
		s<<i++<<". "<<(*d++)->toString();
	return s.str();
}

string Grafo::mostrarGrafoSinPagActual(string nom){
	stringstream s;
	list<Nodo*>::iterator d = nodos.begin();
	int i = 1;
	while(d != nodos.end()){
		if((*d)->getNombre() != nom)
			s<<i++<<". "<<(*d++)->toString();
		else
			d++;
	}
	return s.str();
}

void Grafo::agregarAvisitados(Nodo * actual,Nodo * saliente){
	actual->agregarNodo(saliente);
}

void Grafo::agregarAentradas(Nodo * actual,Nodo * entrante){
	actual->agregarEntranda(entrante);
}

Grafo::~Grafo(void) {
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end())
		delete(*d++);
}
