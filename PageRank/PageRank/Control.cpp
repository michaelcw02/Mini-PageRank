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
			Nodo * nnodo = new Nodo(respuesta);
			registrarPagina(nnodo);
		}
	}
	while(activo);
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
