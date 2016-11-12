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
	cout<<nodoActual->toString();

	if(!nodoActual)
		activo = false;

	while(activo) {
		mostrarPaginaActualYLista(nodoActual->toString(), nodoActual->getNombre());
		cin>>respuesta;
		if(respuesta == "Z" || respuesta == "z")
			activo = false;
		nodoActual = desarrollarOpcion(respuesta, nodoActual);
	}
	guardar();
}

Nodo* Control::procesoInicial() {
	string respuesta = " ";
	Nodo* nodoActual = NULL;

	Interfaz::mostrarBanner();
	
	mostrarListaPaginas();
	cin>>respuesta;
	if(respuesta == "O" || respuesta == "o") {
		Interfaz::entornoPagina(ANCHO, ALTO);
		cin>>respuesta;
		if (respuesta != "0") {
			nodoActual = registrarPaginaNueva(respuesta);
		} else
			nodoActual = NULL;
	}
	if(isAcceder(respuesta)) {
		nodoActual = graf->getPagina(respuesta);
	}
	return nodoActual;
}

Nodo* Control::desarrollarOpcion(string respuesta, Nodo* nodoActual) {
	Nodo* nodo = NULL;

	if(isDigit(respuesta)) {
		int opc = stoi(respuesta);
		nodo = graf->getPaginaByNum(opc, nodoActual);
		darClick(nodo, nodoActual);
		nodo = nodoActual;
	}
	if(isAcceder(respuesta)) {
		respuesta.pop_back(); //Para quitar la a
		int opc = stoi(respuesta);
		nodo = graf->getPaginaByNum(opc, nodoActual);
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
	stringstream s;
	string result;
	list<Nodo*> paginas = getNodos();
	list<Nodo*>::iterator ite = paginas.begin();
	while(ite != paginas.end()) {
		s << " " << (*ite)->getNombre( )<< " ------> " << PageRanker::pageRank((*ite), NULL) << endl;
		ite++;
		graf->setNoVisitados(); 
	}
	Interfaz::limpiarPantalla();
	Interfaz::mostrarPageRank(35, 5, s.str());
}
//
//void Control::desarrollarOpcion(string opcion, Nodo * act, string &r) {
//	Nodo* nodo;
//	string respuesta;
//	//OPCION PAGE RANK
//	if(opcion == "PR" || opcion == "pr") {
//		list<Nodo*> listita = getNodos();
//		Interfaz::limpiarPantalla();
//		Interfaz::mostrarPageRank(10,0);
//		list<Nodo*>::iterator ite = listita.begin();
//		while(ite != listita.end()) {
//			cout<<(*ite)->getNombre()<<" ------> "<<PageRanker::pageRank((*ite), NULL)<<endl;ite++;graf->setNoVisitados(); 
//		}
//		r = " ";
//		cout<<"Digite ENTER para volver a la pagina anterior."<<endl;
//		system("pause");
//	}
//	//OPCION NUEVA PAGINA A PARTIR DE LA PAGINA ACTUAL
//	if(opcion == "N" || opcion == "n"){
//		Interfaz::limpiarPantalla();
//		Interfaz::mostrarOpcionNuevaPagina(ANCHO, ALTO, act->toString());
//		cin>>respuesta;
//		r = respuesta;
//		nodo = graf->getPagina(respuesta);
//		if (!nodo)
//			crearPaginaApartirDeActual(respuesta, act);
//		else
//			darClick(nodo, act);
//	}
//	//OPCION DAR CLICK A PAGINA
//	if(isDigit(opcion)) {
//		int opc = stoi(opcion);
//		nodo = graf->getPaginaByNum(opc, act);
//		darClick(nodo, act);
//		r = " ";
//	}
//	//OPCION DAR CLICK Y ACCEDER A PAGINA
//	if(isAcceder(opcion)){
//		opcion.pop_back(); //Para quitar la a
//		int opc = stoi(opcion);
//		nodo = graf->getPaginaByNum(opc, act);
//		darClick(nodo,act);
//		r = " ";
//	}
//}

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
		if(nodoFuturo->existeEntrante(actual)){
			nodoFuturo->recibirClick(actual->getNombre());
		}else{
			nodoFuturo->agregarEntranda(actual);
			nodoFuturo->recibirClick(actual->getNombre());
		}
		if(actual->existeSaliente(nodoFuturo)){
			actual->enviarClick(nodoFuturo->getNombre());
		}else{
			actual->agregarNodo(nodoFuturo);
			actual->enviarClick(nodoFuturo->getNombre());
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
	for(int i = 0; i < opcion.length()-1; i++)
		opc.push_back(opcion[i]);
	bool isNumber = isDigit(opc);
	if(isNumber)
		if (opcion[opcion.length()-1] == 'a' || opcion[opcion.length()-1] == 'A')
			return true;
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
	graf = new Grafo(entrada);
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
void Control::mostrarPaginaActualYLista(string pagina, string respuesta) {
	Interfaz::limpiarPantalla();
	Interfaz::plantillaPagina(ANCHO, ALTO, pagina, graf->mostrarGrafoSinPagActual(respuesta));
}
Control::~Control(void)
{
	delete graf;
}
