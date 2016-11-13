#pragma once
#include "Grafo.h"
#include "PageRanker.h"
#include "Interfaz.h"

//Universidad Nacional de Costa Rica
//		Estructura de Datos
//			Proyecto II
//Profesor: Santiago Caamaño Polini
//Estudiantes:	Andrey Arguedas Espinoza
//				Michael Chen Wang


static const int ALTO = 2;
static const int ANCHO = 20;
static const string NONE = "-NINGUNO-";

class Control
{
private:
	Grafo * graf;
public:
	Control(void);
	void iniciarBuscador();
	Nodo* procesoInicial();
	void registrarPagina(Nodo * n);
	void agregarDesde(Nodo * n); ///Agrega un nodo a outbounds desde una pagina actual
	bool paginaExistente(string);
	list<Nodo*> getNodos();
	Nodo * getPagina(string);
	string mostrarHistorial();
	string paginasRecientes();
	void guardar();
	void recuperarDatos();
	Nodo* desarrollarOpcion(string, Nodo*);
	void pageRank();
	list<Nodo*> obtenerRank();
	void desarrollarOpcion(string, Nodo *,string&);
	void crearPaginaApartirDeActual(string,	Nodo*);
	void darClick (Nodo*, Nodo *); //Se esta en una pagina y se quiere ir a otra 
	bool isDigit(string);
	bool isAcceder(string);
	Nodo* registrarPaginaNueva(string);
	void mostrarListaPaginas();
	void mostrarPaginaActualYLista(string, string, int, int);
	void propiedadesConsola();

	~Control(void);
};

