#include "Nodo.h"

Nodo::Nodo(){
	nombre = " ";
	outbound = new list<Nodo*>();
	inbound;
}
Nodo::Nodo(string nombre) {
	this->nombre = nombre;
	outbound = new list<Nodo*>();
	inbound;
}

void Nodo::setNombre(string nombre) {
	this->nombre = nombre;
}
string Nodo::getNombre(){
	return nombre;
}

string Nodo::toString(){
	stringstream s;
	s<<"https//:"<<nombre<<endl;
	return s.str();
}


//VECINOS SALIENTES...
void Nodo::agregarNodo(Nodo * n){
	outbound->push_back(n);
}

bool Nodo::enviarClick(string nom) {
	list<Nodo*>::iterator outIterator = outbound->begin();
	while(outIterator != outbound->end()) {
		string nombre = (*outIterator)->getNombre();
		if(nombre == nom) {
			(*outIterator)->recibirClick(this);
			return true;	
		}
	}
	return false;
}

//VECINOS ENTRANTES...
void Nodo::agregarEntranda(Nodo * node) {
	inbound.insert(Map::value_type(node, 1));
}
void Nodo::recibirClick(Nodo * nom) {
	Map::iterator inIterator;
	inIterator = inbound.find(nom);
	if(inIterator != inbound.end())
		inIterator->second++;
}



Nodo::~Nodo(void){
	
	delete outbound;
}
