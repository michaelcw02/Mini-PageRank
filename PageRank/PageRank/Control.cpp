#include "Control.h"


Control::Control(void)
{
	graf = new Grafo();
}

void Control::iniciarBuscador(){
	bool activo = true;
	string respuesta = " ";
	Interfaz::mostrarBanner();
	do{
		Interfaz::entornoPagina(0,0);
		cin>>respuesta;
		activo = (respuesta == "0")?false:true;
		if(activo){
			if(getPagina(respuesta)){
				Interfaz::limpiarPantalla();
				Interfaz::plantillaPagina(0,0,respuesta,graf->mostrarGrafo());
				system("pause");
				Interfaz::limpiarPantalla();
			}
			else{
				Nodo * nnodo = new Nodo(respuesta);
				registrarPagina(nnodo);
				Interfaz::limpiarPantalla();
				Interfaz::plantillaPagina(0,0,respuesta,graf->mostrarGrafo());
				system("pause");
			}
		}
	}
	while(activo);
	cin.get();
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
