#include "PageRanker.h"


PageRanker::PageRanker(void) {
}

//nodoAnterior: nodo que apunta
double PageRanker::pageRank(Nodo* nodo, Nodo* nodoAnterior) {
	double result = 0;
	
	Nodo* vecino = nodo->getPaginaInicio();
	
	if (vecino == NULL)
		result = (1-D);

	while(vecino != NULL) {
	
		if(vecino == nodoAnterior)
			result += (1-D);
		if(vecino != nodoAnterior)
			result += pageRank(vecino, nodo) / clicks(vecino);
		vecino = nodo->getPaginaSiguiente(vecino);

	}

	return (1-D) + D * result;
}

double PageRanker::clicks(Nodo* nodo) {
	return nodo->getCantClicks();
}

PageRanker::~PageRanker(void) {
}


