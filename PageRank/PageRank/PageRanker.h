#pragma once
#include "Nodo.h"

const double D = 0.85;
class PageRanker {
public:
	PageRanker(void);
	
	double pageRank(Nodo*, Nodo*);
	double clicks(Nodo*);
	
	~PageRanker(void);
};

