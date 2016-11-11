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
	MapBool::iterator ite = inbound.begin();
	return (ite != inbound.end()) ? ite->first : NULL;
}
Nodo* Nodo::getPaginaSiguiente(Nodo* nodo) {
	MapBool::iterator ite = inbound.find(nodo);
	(ite != inbound.end()) ? ite++ : ite = inbound.end();
	return (ite != inbound.end()) ? ite->first : NULL;
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
bool Nodo::enviarClick(Nodo* nodo) {
	Map::iterator outIterator;
	outIterator = outbound.find(nodo);
	if(outIterator != outbound.end()) {
		(*outIterator).second++;
		(*outIterator).first->recibirClick(this);
		return true;
	}
	return false;
}

bool Nodo::recibirClick(string nom){
	/*Map::iterator inIterator = inbound.begin();
	while(inIterator != inbound.end()) {
		string nombre = (*inIterator).first->getNombre();
		if(nombre == nom) {
			(*inIterator).second++;
			//(*outIterator).first->recibirClick(this);
			return true;	
		}
	}
	return false;*/
	return true;
}

//VECINOS ENTRANTES...
void Nodo::agregarEntranda(Nodo * node) {
	inbound.insert(Map::value_type(node, 1));
}
void Nodo::recibirClick(Nodo * nom) {
	/*Map::iterator inIterator;
	inIterator = inbound.find(nom);
	if(inIterator != inbound.end())
		inIterator->second++;*/
}


int Nodo::getCantClicks() {
	mapIterator = outbound.begin();
	int cantClicks = 0;
	while(mapIterator != outbound.end())
		cantClicks += mapIterator++->second;
	return cantClicks;
}

bool Nodo::existeSaliente(Nodo * ne){
	mapIterator = outbound.begin();
	while(mapIterator != outbound.end()){
		if(mapIterator->first->getNombre() == ne->getNombre())
			return true;
		mapIterator++;
	}
	return false;
}

bool Nodo::existeEntrante(Nodo * ne){
	MapBool::iterator mapB = inbound.begin();
	while(mapB != inbound.end()){
		if(mapB->first->getNombre() == ne->getNombre())
			return true;
		mapB++;
	}
	return false;
}


Nodo::~Nodo(void){
	
}
