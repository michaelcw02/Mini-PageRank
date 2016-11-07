#include "Nodo.h"

Nodo::Nodo(){
	nombre = " ";
	vecinos = list<Nodo*>();
}


string Nodo::getNombre(){
	return nombre;
}


void Nodo::agregar(Nodo * n){
	
}

string Nodo::toString(){
	stringstream s;
	s<<"https//:"<<nombre<<endl;
	return s.str();
}

Nodo::~Nodo(void){
	/////Investigar sobre el destructor de un map
}
