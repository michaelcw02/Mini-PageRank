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
	list<Nodo*> vecinos;
	typedef multimap<string,int, less<string>>creaMap;
	creaMap vecinos;
public:
	Nodo(void);
	string getNombre();;
	string toString();
	void agregar(Nodo *);
	~Nodo(void);
};

