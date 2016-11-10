#pragma once
#include "Nodo.h"
#include <Windows.h>

using namespace std;

class Interfaz
{
private:
	
public:
	Interfaz(void);
	static void gotoXY(int, int);
	static void entornoPagina(int,int);
	static void plantillaPagina(int, int, string, string);
	static void mostrarBanner();
	static void mostrarPaginaActual(string);
	static void mostrarListaPaginas(string,int,int);
	static void mostrarOpcionNuevaPagina();
	static void limpiarPantalla();
	~Interfaz(void);
};

