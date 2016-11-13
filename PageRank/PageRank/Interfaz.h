#pragma once
#include "Nodo.h"
#include <Windows.h>

//Universidad Nacional de Costa Rica
//		Estructura de Datos
//			Proyecto II
//Profesor: Santiago Caamaño Polini
//Estudiantes:	Andrey Arguedas Espinoza
//				Michael Chen Wang

using namespace std;

class Interfaz
{
private:
	
public:
	Interfaz(void);
	static void gotoXY(int, int);
	static void entornoPagina(int,int);
	static void plantillaPaginaInicio(int, int, string);
	static void plantillaPagina(int, int, string, string);
	static void mostrarBanner();
	static void mostrarPaginaActual(string);
	static void mostrarListaPaginas(string, int, int&);
	static void mostrarOpcionNuevaPagina(int,int,string);
	static void paginaYaExistente(int,int);
	static void mostrarPageRank(int, int, string);
	static void mostrarCantClicks(string, int, int);
	static void limpiarPantalla();
	~Interfaz(void);
};

