#include "Nodo.h"

Nodo::Nodo(){
	nombre = " ";
	outbound;
	inbound;
	mapIterator = outbound.begin();
}
Nodo::Nodo(string nombre) {
	this->nombre = nombre;
	outbound;
	inbound;
	mapIterator = outbound.begin();
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

//GET ITERATORS....
Nodo* Nodo::getPaginaInicio() {
	mapIterator = outbound.begin();
	return mapIterator->first;
}
Nodo* Nodo::getPaginaActual(){
	return mapIterator->first;
}
Nodo* Nodo::getPaginaSiguiente(Nodo* nodo) {
	mapIterator = outbound.find(nodo);
	return mapIterator->first;
}

//VECINOS SALIENTES...
void Nodo::agregarNodo(Nodo * n){
	outbound.insert(Map::value_type(n,1));
}

bool Nodo::enviarClick(string nom) {
	Map::iterator outIterator = outbound.begin();
	while(outIterator != outbound.end()) {
		string nombre = (*outIterator).first->getNombre();
		if(nombre == nom) {
			(*outIterator).second++;
			(*outIterator).first->recibirClick(this->getNombre());
			return true;
		}
	}
	return false;
}

bool Nodo::recibirClick(string nom){
	Map::iterator inIterator = inbound.begin();
	while(inIterator != inbound.end()) {
		string nombre = (*inIterator).first->getNombre();
		if(nombre == nom) {
			(*inIterator).second++;
			//(*outIterator).first->recibirClick(this);
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
	
}
