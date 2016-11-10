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
	list<Nodo*>  * outbound; //Lista para los nodos salientes
	typedef  map < Nodo*, int, less<string> > Map;
	Map  inbound;   ///Con solo esta linea ya esta creado, no hace falta ponerle mas

public:
	Nodo(void);
	Nodo(string);

	void setNombre(string);
	string getNombre();
	
	string toString();
	
	//VECINOS SALIENTES....
	void agregarNodo(Nodo*);
	bool enviarClick(string); //string = nombre del nodo...

	//VECINOS ENTRANTES....
	void agregarEntranda(Nodo*);
	void recibirClick(Nodo*);
	int getCantVecinos();
	int getCantClicks();

	~Nodo(void);
};

