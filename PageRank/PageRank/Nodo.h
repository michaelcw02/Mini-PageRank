#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <fstream>

using namespace std;

class Nodo{
private:
	string nombre;
	typedef  map < Nodo*, int, less<Nodo*> > Map;
	typedef  map < Nodo*, bool, less<Nodo*> > MapBool;
	Map  outbound;   
	MapBool inbound;
	Map::iterator mapIterator;
public:
	
	Nodo(void);
	Nodo(string);

	void setNombre(string);
	string getNombre();
	
	string toString();

	//Get iterador
	Nodo* getPaginaInicio();
	Nodo* getPaginaSiguiente(Nodo*);
	Nodo* getPaginaNoVisitado();
	void setPaginaVisitado(Nodo*);
	void setNoVisitados();
	//VECINOS SALIENTES....
	void agregarNodo(Nodo*);
	bool enviarClick(string); 
	bool existeSaliente(Nodo*);
	bool enviarClick(Nodo*);


	//VECINOS ENTRANTES....
	void agregarEntranda(Nodo*);
	void recibirClick(Nodo*);
	int getCantVecinos();
	bool existeEntrante(Nodo*);

	int getCantClicks();
	void guardar(ofstream&);
	void cargarEntrante(Nodo*,int);
	void cargarSalida(Nodo*,int);

	~Nodo(void);
};

