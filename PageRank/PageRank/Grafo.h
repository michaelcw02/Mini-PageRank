#pragma once
#include "Nodo.h"

//Universidad Nacional de Costa Rica
//		Estructura de Datos
//			Proyecto II
//Profesor: Santiago Caamaño Polini
//Estudiantes:	Andrey Arguedas Espinoza
//				Michael Chen Wang

class Grafo
{
private:
	list<Nodo*> nodos;
public:
	Grafo(void);
	Grafo(ifstream &);
	void agregar(Nodo*);
	bool existePgina(string);
	void setNoVisitados();
	int cantidadNodos();
	Nodo* getPagina(string);
	Nodo* getPaginaByNum(int, Nodo*);
	void agregarClickAPagina(int, Nodo*);
	void agregarAvisitados(Nodo*,Nodo*);
	void agregarAentradas(Nodo*,Nodo*);
	void guardarGrafo(ofstream &);
	string mostrarGrafoSinPagActual(string);
	list<Nodo*> getNodos();
	string mostrarGrafo();
	void actualizarPorRank(list<Nodo*>);
	~Grafo(void);
};

