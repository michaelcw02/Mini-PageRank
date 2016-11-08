#include "Control.h"


Control::Control(void)
{
	graf = new Grafo();
}

void Control::iniciarBuscador(){
	bool activo = true;
	Interfaz::mostrarBanner();
	cin.get();
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
