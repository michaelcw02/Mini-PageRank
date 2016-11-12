#include "Control.h"

Control::Control(void) {
	graf = new Grafo();
	recuperarDatos();
}

void Control::iniciarBuscador(){
	bool activo = true;
	string respuesta = " ";
	Nodo* nodoActual = NULL;
	string pagFutura = " ";

	nodoActual = procesoInicial();

	if(!nodoActual)
		activo = false;
	
	Nodo* nodoAux;
	while(activo) {
		nodoAux = nodoActual;
		mostrarPaginaActualYLista(nodoActual->toString(), nodoActual->getNombre(), nodoActual->getCantClicks(), nodoActual->getCantVecinos());
		cin>>respuesta;
		if(respuesta == "Z" || respuesta == "z")
			activo = false;
		nodoActual = desarrollarOpcion(respuesta, nodoActual);
		if(!nodoActual)
			nodoActual = nodoAux;
	}
	guardar();
}

Nodo* Control::procesoInicial() {
	bool activo;
	string respuesta = " ";
	Nodo* nodoActual = NULL;

	Interfaz::mostrarBanner();

	do {
		activo = true;
		graf->actualizarPorRank(obtenerRank());
		mostrarListaPaginas();
		cin>>respuesta;
		if(respuesta == "O" || respuesta == "o") {
			Interfaz::entornoPagina(ANCHO, ALTO);
			cin>>respuesta;
			if (respuesta != "0") {
				nodoActual = registrarPaginaNueva(respuesta);
			} else
				nodoActual = NULL;
			activo = false;
		}
		if(isAcceder(respuesta)) {
			respuesta.pop_back(); //Para quitar la a
			int opc = stoi(respuesta);
			nodoActual = graf->getPaginaByNum(opc, nodoActual);
			if(nodoActual)
				activo = false;
			else
				activo = true;
		}
		if(isDigit(respuesta)) {
			int opc = stoi(respuesta);
			nodoActual = graf->getPaginaByNum(opc, nodoActual);
			if(nodoActual)
				activo = false;
			else
				activo = true;
		}
		if(respuesta == "PR" || respuesta == "pr") {
			pageRank();
			activo = true;
		}
		if(respuesta == "Z" || respuesta == "z"){activo = false;}
	} while(activo);

	return nodoActual;
}

Nodo* Control::desarrollarOpcion(string respuesta, Nodo* nodoActual) {
	Nodo* nodo = NULL;

	if(isDigit(respuesta)) {
		int opc = stoi(respuesta);
		nodo = graf->getPaginaByNum(opc, nodoActual);
		if(nodo)
			darClick(nodo, nodoActual);
		nodo = nodoActual;
	}
	if(isAcceder(respuesta)) {
		respuesta.pop_back(); //Para quitar la a
		int opc = stoi(respuesta);
		nodo = graf->getPaginaByNum(opc, nodoActual);
		if(nodo)
			darClick(nodo, nodoActual);
	}
	if(respuesta == "PR" || respuesta == "pr") {
		pageRank();
		nodo = nodoActual;
	}
	if(respuesta == "N" || respuesta == "n") {
		Interfaz::limpiarPantalla();
		Interfaz::mostrarOpcionNuevaPagina(ANCHO, ALTO, nodoActual->toString());
		cin>>respuesta;
		nodo = graf->getPagina(respuesta);
		if (!nodo) {
			crearPaginaApartirDeActual(respuesta, nodoActual);
			nodo = graf->getPagina(respuesta);
		}
		else
			darClick(nodo, nodoActual);
	}
	if(respuesta == "O" || respuesta == "o") {
		Interfaz::limpiarPantalla();
		Interfaz::entornoPagina(ANCHO, ALTO);
		cin>>respuesta;
		if (respuesta != "0")
			nodo = registrarPaginaNueva(respuesta);
	}

	return nodo;
}

void Control::pageRank() {
	Interfaz::limpiarPantalla();
	stringstream s;
	typedef  multimap < double, Nodo*, std::less<double>> Mapr; 
	Mapr ranking;
	list<Nodo*> paginas = getNodos();
	list<Nodo*> paginasOrdenadas = list<Nodo*>();
	list<Nodo*>::iterator ite = paginas.begin();

	while(ite != paginas.end()) {
		ranking.insert(Mapr::value_type(PageRanker::pageRank(*ite,NULL), *ite));
		ite++;
		graf->setNoVisitados(); 
	}

	Mapr::iterator r = ranking.end();
	r--;
	while(r != ranking.begin()){
		s << " " << (r)->second->getNombre() << " ------> " << r->first << endl;
		paginasOrdenadas.push_back(r->second);
		r--;
	}
	s << " " << (r)->second->getNombre() << " ------> " << r->first << endl;
	paginasOrdenadas.push_back(r->second);
	Interfaz::limpiarPantalla();
	Interfaz::mostrarPageRank(35, 5, s.str());
}

list<Nodo*> Control::obtenerRank(){
	typedef  multimap < double, Nodo*, std::less<double>> Mapr; 
	Mapr ranking;
	list<Nodo*> paginas = getNodos();
	list<Nodo*> paginasOrdenadas = list<Nodo*>();
	list<Nodo*>::iterator ite = paginas.begin();
	while(ite != paginas.end()) {
		ranking.insert(Mapr::value_type(PageRanker::pageRank(*ite,NULL),*ite));
		ite++;
		graf->setNoVisitados(); 
	}
	Mapr::iterator r = ranking.end();
	if(r != ranking.begin()){
		r--;
		while(r != ranking.begin()){
			paginasOrdenadas.push_back(r->second);
			r--;
		}
	paginasOrdenadas.push_back(r->second);
	}
	return paginasOrdenadas;
}


void Control::crearPaginaApartirDeActual(string np, Nodo * actual){
	Nodo * nnodo = new Nodo(np);
	actual->agregarNodo(nnodo); //Lo agregamos a los salientes
	nnodo->agregarEntranda(actual);
	registrarPagina(nnodo);
}

list<Nodo*> Control::getNodos(){
	return graf->getNodos();
}

void Control::darClick(Nodo* nodoFuturo, Nodo * actual){ /////Checkear esto 
	if(nodoFuturo){
		if(actual->existeSaliente(nodoFuturo)){
			actual->enviarClick(nodoFuturo->getNombre());
		}else{
			actual->agregarNodo(nodoFuturo);
		}
	}
}


bool Control::isDigit(string opcion) {
	for(int i = 0; i < opcion.length(); i++) {
		if (opcion[i] < '0' || opcion[i] > '9')
			return false;
	}
	return true;
}

bool Control::isAcceder(string opcion) {
	string opc;
	if(opcion.length() > 1) {
		for(int i = 0; i < opcion.length()-1; i++)
			opc.push_back(opcion[i]);
		bool isNumber = isDigit(opc);
		if(isNumber)
			if (opcion[opcion.length()-1] == 'a' || opcion[opcion.length()-1] == 'A')
				return true;
	}
	return false;
}

bool Control::paginaExistente(string nom){
	return graf->existePgina(nom);
}

Nodo * Control::getPagina(string nom){
	return graf->getPagina(nom);
}

void Control::registrarPagina(Nodo * n){
	graf->agregar(n);
}

string Control::mostrarHistorial(){
	stringstream s;
	s<<graf->mostrarGrafo()<<endl;
	return s.str();
}
	
string Control::paginasRecientes(){
	stringstream s;
	s<<graf->mostrarGrafo()<<endl;
	return s.str();
}

void Control::guardar(){
	ofstream salida("PageRank.txt");
	graf->guardarGrafo(salida);
	salida.close();
}

void Control::recuperarDatos(){
	ifstream entrada("PageRank.txt");
	if(entrada.is_open()){
		graf = new Grafo(entrada);
	}
	entrada.close();
}

Nodo* Control::registrarPaginaNueva(string pagina) {
	Nodo* nodo = NULL;
	if(!getPagina(pagina) && pagina != " "){ //El respuesta != " " es para no crear nodos de las opciones disponibles
		nodo = new Nodo(pagina);
		registrarPagina(nodo);
	} else {
		if(pagina != " ")
			nodo = getPagina(pagina);
	}
	return nodo;
}

void Control::mostrarListaPaginas() {
	Interfaz::limpiarPantalla();
	Interfaz::plantillaPaginaInicio(ANCHO, ALTO, graf->mostrarGrafo());
}

void Control::mostrarPaginaActualYLista(string pagina, string respuesta, int clicksEnt, int paginasEnt) {
	graf->actualizarPorRank(obtenerRank());
	Interfaz::limpiarPantalla();
	Interfaz::mostrarCantClicks(pagina, clicksEnt, paginasEnt);
	Interfaz::plantillaPagina(ANCHO, ALTO, pagina, graf->mostrarGrafoSinPagActual(respuesta));
}

Control::~Control(void)
{
	delete graf;
}
