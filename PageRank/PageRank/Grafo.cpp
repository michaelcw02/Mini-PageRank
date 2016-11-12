#include "Grafo.h"


Grafo::Grafo(void)
{
	nodos = list<Nodo*>();
}

Grafo::Grafo(ifstream & datos)
{
	int cantPaginas = 0;
	datos>>cantPaginas;
	string nombre;
	string auxiliar;
	string rel1;
	string rel2;
	for(int i = 0; i < cantPaginas; i++){
		datos>>nombre;
		Nodo * n = new Nodo(nombre);
		agregar(n);
	}
	datos>>nombre;
	if(nombre == "Relaciones:"){
		datos>>nombre;
		while(!datos.eof()){
			Nodo * nn = getPagina(nombre);
			datos>>auxiliar;
			if(auxiliar == "Entrantes:"){
				datos>>auxiliar;
				while(auxiliar != "Salientes:"){
					auxiliar.erase(auxiliar.begin());  //Quitar parentesis
					auxiliar.pop_back(); //Quitar parentesis
					int posSeparador = auxiliar.find(":");
					rel1 = auxiliar.substr(0,posSeparador);
					rel2 = auxiliar.substr(posSeparador+1,auxiliar.length()-1);
					nn->cargarEntrante(getPagina(rel1),stoi(rel2));
					datos>>auxiliar;
				}
				datos>>auxiliar;
				while(auxiliar != nn->getNombre() + "FINAL"){
					auxiliar.erase(auxiliar.begin());  //Quitar parentesis
					auxiliar.pop_back(); //Quitar parentesis
					int posSeparador = auxiliar.find(":");
					rel1 = auxiliar.substr(0,posSeparador);
					rel2 = auxiliar.substr(posSeparador+1,auxiliar.length()-1);
					nn->cargarSalida(getPagina(rel1),stoi(rel2));
					datos>>auxiliar;
				}
			}
			datos>>nombre;
		}
	}
}

void Grafo::actualizarPorRank(list<Nodo*> l){
	nodos = l;

}

void Grafo::agregar(Nodo * n){
	nodos.push_back(n);
}

int Grafo::cantidadNodos(){
	return nodos.size();
}

bool Grafo::existePgina(string nom){
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end()){
		if(nom == (*d++)->getNombre())
			return true;
	}
	return false;
}

void Grafo::setNoVisitados() {
	list<Nodo*>::iterator ite = nodos.begin();
	while (ite != nodos.end()) {
		(*ite)->setNoVisitados();
		ite++;
	}
}

Nodo * Grafo::getPagina(string nom){
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end()){
		if(nom == (*d)->getNombre())
			return (*d);
		else
			(d++);
	}
	return NULL;
}

Nodo* Grafo::getPaginaByNum(int num, Nodo* nodoActual) {
	list<Nodo*>::iterator ite = nodos.begin();
	int i = 0;
	while(ite != nodos.end()) {
		if(i == num-1)
			return (*ite);
		if((*ite) != nodoActual)
			i++;
		ite++;
	}
	return NULL;
}

void Grafo::agregarClickAPagina(int num, Nodo* nodoFuente) {
	Nodo* nodoDestino = getPaginaByNum(num, nodoFuente);
	nodoFuente->enviarClick(nodoDestino);
}

void Grafo::guardarGrafo(ofstream & guardar){
	list<Nodo*>::iterator d = nodos.begin();
	guardar<<cantidadNodos()<<endl;
	while(d != nodos.end()){
		guardar<<(*d)->getNombre()<<endl;
		d++;
	}
	guardar<<"Relaciones:"<<endl;
	d = nodos.begin();
	while(d != nodos.end()){
		(*d)->guardar(guardar);
		d++;
	}
}

list<Nodo*> Grafo::getNodos(){
	return nodos;
}

string Grafo::mostrarGrafo(){
	stringstream s;
	list<Nodo*>::iterator d = nodos.begin();
	int i = 1;
	while(d != nodos.end())
		s<<i++<<". "<<(*d++)->toString();
	return s.str();
}

string Grafo::mostrarGrafoSinPagActual(string nom){
	stringstream s;
	list<Nodo*>::iterator d = nodos.begin();
	int i = 1;
	while(d != nodos.end()){
		if((*d)->getNombre() != nom)
			s<<i++<<". "<<(*d++)->toString();
		else
			d++;
	}
	return s.str();
}

void Grafo::agregarAvisitados(Nodo * actual,Nodo * saliente){
	actual->agregarNodo(saliente);
}

void Grafo::agregarAentradas(Nodo * actual,Nodo * entrante){
	actual->agregarEntranda(entrante);
}

Grafo::~Grafo(void) {
	list<Nodo*>::iterator d = nodos.begin();
	while(d != nodos.end())
		delete(*d++);
}
