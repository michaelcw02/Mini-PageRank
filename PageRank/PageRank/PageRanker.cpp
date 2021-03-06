#include "PageRanker.h"


PageRanker::PageRanker(void) {
}

//nodoAnterior: nodo que apunta
double PageRanker::pageRank(Nodo* nodo, Nodo* nodoAnterior) {
	double result = 0;
	
	Nodo* vecino = nodo->getPaginaNoVisitado();
	string nombre = nodo->getNombre();
	if (vecino == NULL)
		result = 0;

	while(vecino != NULL) {
	
		nodo->setPaginaVisitado(vecino);
		if(vecino == nodoAnterior)
			result += (1-D);
		if(vecino != nodoAnterior)
			result += pageRank(vecino, nodo) / clicks(vecino);
		vecino = nodo->getPaginaNoVisitado();

	}

	return (1-D) + D * result;
}

double PageRanker::clicks(Nodo* nodo) {
	return nodo->getCantClicks();
}

PageRanker::~PageRanker(void) {
}


