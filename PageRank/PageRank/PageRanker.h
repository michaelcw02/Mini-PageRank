#pragma once
#include "Nodo.h"

//Universidad Nacional de Costa Rica
//		Estructura de Datos
//			Proyecto II
//Profesor: Santiago Caamaño Polini
//Estudiantes:	Andrey Arguedas Espinoza
//				Michael Chen Wang

const double D = 0.85;
class PageRanker {
public:
	PageRanker(void);
	
	static double pageRank(Nodo*, Nodo*);
	static double clicks(Nodo*);
	~PageRanker(void);
};

