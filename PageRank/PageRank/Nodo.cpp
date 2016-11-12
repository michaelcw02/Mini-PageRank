#include "Nodo.h"

Nodo::Nodo(){
	nombre = " ";
	mapIterator = outbound.begin();
}
Nodo::Nodo(string nombre) {
	this->nombre = nombre;
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
Nodo* Nodo::getPaginaNoVisitado() {
	MapBool::iterator ite = inbound.begin();
	while (ite != inbound.end()) {
		if (ite->second == false)
			return ite -> first;
		ite++;
	}
	return NULL;
}
void Nodo::setPaginaVisitado(Nodo* nodo) {
	MapBool::iterator ite = inbound.find(nodo);
	if(ite !=  inbound.end())
		ite->second = true;
}
void Nodo::setNoVisitados() {
	MapBool::iterator ite = inbound.begin();
	while (ite != inbound.end()) {
		ite->second = false;
		ite++;
	}
}

//VECINOS SALIENTES...
void Nodo::agregarNodo(Nodo * n){
	Map::iterator ite = outbound.find(n);
	if(ite != outbound.end())
		ite->second++;
	else
		outbound.insert(Map::value_type(n,0));
}

bool Nodo::enviarClick(string nom) {
	Map::iterator outIterator = outbound.begin();
	while(outIterator != outbound.end()) {
		string nombre = (*outIterator).first->getNombre();
		if(nombre == nom) {
			(*outIterator).second++;
			(*outIterator).first->recibirClick(this);
			return true;
		}
		outIterator++;
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

//VECINOS ENTRANTES...
void Nodo::agregarEntranda(Nodo * node) {
	inbound.insert(MapBool::value_type(node, false));
}
void Nodo::recibirClick(Nodo * nom) {
	agregarEntranda(nom);
}
int Nodo::getCantVecinos() {
	return outbound.size();
}

void Nodo::guardar(ofstream & guard){
	guard<<nombre<<endl;
	guard<<"Entrantes:"<<endl;
	MapBool::iterator it = inbound.begin();
	while(it != inbound.end()){
		guard<<"["+(it)->first->getNombre()+":";
		guard<<(it)->second;guard<<"]"<<endl;
		it++;
	}
	guard<<"Salientes:"<<endl;
	mapIterator = outbound.begin();
	while(mapIterator != outbound.end()){
		guard<<"["+(mapIterator)->first->getNombre()+":";
		guard<<(mapIterator)->second;guard<<"]"<<endl;
		mapIterator++;
	}
	guard<<nombre + "FINAL"<<endl;

}

void Nodo::cargarEntrante(Nodo*n ,int e){
	inbound.insert(MapBool::value_type(n, e));
}
	
void Nodo::cargarSalida(Nodo* n,int c){
	outbound.insert(Map::value_type(n,c));
}


int Nodo::getCantClicks() {
	mapIterator = outbound.begin();
	int cantClicks = 0;
	while(mapIterator != outbound.end())
		cantClicks += mapIterator++->second;
	return cantClicks;
}

bool Nodo::existeSaliente(Nodo * nodo){
	mapIterator = outbound.find(nodo);
	if(mapIterator != outbound.end())
		return true;
	return false;

	//mapIterator = outbound.begin();
	//while(mapIterator != outbound.end()){
	//	if(mapIterator->first->getNombre() == ne->getNombre())
	//		return true;
	//	mapIterator++;
	//}
	//return false;
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
