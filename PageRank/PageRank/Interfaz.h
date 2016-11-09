#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Interfaz
{
public:
	Interfaz(void);
	static void gotoXY(int, int);
	static void entornoPagina(int,int,string);
	static void mostrarBanner();
	static void mostrarPaginaActual(string);
	static void mostrarListaPaginas(string[]);
	static void mostrarOpcionNuevaPagina();
	~Interfaz(void);
};

