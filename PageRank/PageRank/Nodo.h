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
	list<Nodo*> outbound;
	typedef multimap < string, int, less<string> > Map;
	Map inbound;
	list<Nodo*>::iterator outIterator;
	Map iterator inIterator;

public:
	Nodo(void);
	Nodo(string);

	void setNombre(string);
	string getNombre();
	
	string toString();

	//ITERATORS...
	iterator getOutIterator();
	iterator getInIterator();
	
	//VECINOS SALIENTES....
	void agregarNodo(Nodo*);
	bool enviarClick(string); //string = nombre del nodo...

	//VECINOS ENTRANTES....
	void agregarEntranda(string nom);
	void recibirClick(string);
	int getCantVecinos();
	int getCantClicks();

	~Nodo(void);
};

