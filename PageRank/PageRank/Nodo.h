#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>

using namespace std;

class Nodo{
private:
	string nombre;
	typedef  map < Nodo*, int, less<Nodo*> > Map;
	Map  outbound;   ///Con solo esta linea ya esta creado, no hace falta ponerle mas
	Map inbound;
	Map::iterator mapIterator;
public:
	
	Nodo(void);
	Nodo(string);

	void setNombre(string);
	string getNombre();
	
	string toString();

	//Get iterador
	Nodo* getPaginaInicio();
	Nodo* getPaginaActual();
	Nodo* getPaginaSiguiente(Nodo*);
	
	//VECINOS SALIENTES....
	void agregarNodo(Nodo*);
	bool enviarClick(string); //string = nombre del nodo...
	bool existeSaliente(Nodo*);

	//VECINOS ENTRANTES....
	void agregarEntranda(Nodo*);
	void recibirClick(Nodo*);
	bool recibirClick(string);
	int getCantVecinos();
	bool existeEntrante(Nodo*);

	int getCantClicks();

	~Nodo(void);
};

