#pragma once
#include "Nodo.h"

const double D = 0.85;
class PageRanker {
public:
	PageRanker(void);
	
	static double pageRank(Nodo*, Nodo*);
	static double clicks(Nodo*);
	
	~PageRanker(void);
};

