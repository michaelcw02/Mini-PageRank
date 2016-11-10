#pragma once
#include "Nodo.h"
#include <Windows.h>

using namespace std;

class Interfaz
{
public:
	Interfaz(void);
	static void gotoXY(int, int);
	static void entornoPagina(int,int);
	static void mostrarBanner();
	static void mostrarPaginaActual(string);
	static void mostrarListaPaginas(list<Nodo*>);
	static void mostrarOpcionNuevaPagina();
	~Interfaz(void);
};

