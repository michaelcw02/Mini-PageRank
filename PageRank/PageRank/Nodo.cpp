#include "Nodo.h"

Nodo::Nodo(){
	nombre = " ";
	outbound = list<Nodo*>();
	vecinosEntrantes = Map<string, <int>, less<string>>();
}
Nodo::Nodo(string nombre) {
	this.nombre = nombre;
	outbound = list<Nodo*>();
	vecinosEntrantes = Map<string, <int>, less<string>>();
}

void Nodo::setNombre(string nombre) {
	this.nombre = nombre;
}
string Nodo::getNombre(){
	return nombre;
}

string Nodo::toString(){
	stringstream s;
	s<<"https//:"<<nombre<<endl;
	return s.str();
}

//ITERATORS...
iterator Nodo::getOutIterator() {
	return outbound.begin();
}
iterator Nodo::getInIterator() {
	return Map.begin();
}

//VECINOS SALIENTES...
void Nodo::agregarNodo(Nodo * n){
	outbound.push(n);
}
bool Nodo::enviarClick(string nom) {
	outIterator = outbound.begin();
	while(outIterator != outbound.end()) {
		string nombre = outIterator.getNombre();
		if(nombre === nom) {
			outIterator.recibirClick(nom);
			return true;	
		}
	}
	return false;
}

//VECINOS ENTRANTES...
void Nodo::agregarEntranda(string nom) {
	//inbound.insert(creaMap::value_type(17, 10.0));
}
void Nodo::recibirClick(string nom) {
	inIterator = inbound.find(nom);
	if(inIterator != inbound.end()) {
		inIterator->second++;
	}
}



Nodo::~Nodo(void){
	/////Investigar sobre el destructor de un map
}
