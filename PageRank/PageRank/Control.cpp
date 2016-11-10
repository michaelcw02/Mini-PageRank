#include "Control.h"


Control::Control(void) {
	graf = new Grafo();
}

void Control::iniciarBuscador(){
	bool activo = true;
	string respuesta = " ";
	Nodo* nodoActual;
	Interfaz::mostrarBanner();
	do{
		Interfaz::limpiarPantalla();
		Interfaz::entornoPagina(0,0);
		cin>>respuesta;
		activo = (respuesta == "0") ? false : true;
		Interfaz::limpiarPantalla();
		if(activo){
			nodoActual = getPagina(respuesta);
			if(nodoActual){
				Interfaz::plantillaPagina(0, 0, nodoActual->toString(), graf->mostrarGrafo());
			}
			else{
				Nodo * nnodo = new Nodo(respuesta);
				registrarPagina(nnodo);
				Interfaz::plantillaPagina(0, 0, nnodo->toString(), graf->mostrarGrafo());
			}
			cin>>respuesta;
						
		}
	}
	while(activo);
	cin.get();
}


void Control::definirOpcion(string opcion) {
	
	if(opcion == "N" || opcion == "n");
		//se va a crearPagina();
	if(isDigit(opcion));
		//hace click
	if(isAcceder(opcion)); 
		//entra a pagina..

}
bool Control::isDigit(string opcion) {
	for(int i = 0; i < opcion.length(); i++) {
		if (opcion[i] < '0' || opcion[i] > '9')
			return false;
	}
	return true;
}

bool Control::isAcceder(string opcion) {
	string opc;
	for(int i = 0; i < opcion.length()-1; i++)
		opc.push_back(opcion[i]);
	bool isNumber = isDigit(opc);
	if(isNumber)
		if (opcion[opcion.length()-1] == 'a' || opcion[opcion.length()-1] == 'A')
			return true;
	return false;
}

bool Control::paginaExistente(string nom){
	return graf->existePgina(nom);
}

Nodo * Control::getPagina(string nom){
	return graf->getPagina(nom);
}

void Control::registrarPagina(Nodo * n){
	graf->agregar(n);
}

string Control::mostrarHistorial(){
	stringstream s;
	s<<graf->mostrarGrafo()<<endl;
	return s.str();
}
	
string Control::paginasRecientes(){
	stringstream s;
	s<<graf->mostrarGrafo()<<endl;
	return s.str();
}

Control::~Control(void)
{
	delete graf;
}
