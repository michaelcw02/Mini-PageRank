#include "Interfaz.h"


Interfaz::Interfaz(void) {

}

void Interfaz::gotoXY(int x, int y) {
	COORD position = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, position);
}

void Interfaz::mostrarBanner(){
	system("color A");

	int x = 15, y = 5;
	
	system("cls");
	gotoXY(x, y++);	cout << "================================================= " << endl;
	gotoXY(x, y++);	cout << "||     Universidad Nacional de Costa Rica      ||" << endl;
	gotoXY(x, y++);	cout << "||         Bienvenido al Mini-PageRank         ||" << endl;
	gotoXY(x, y++);	cout << "||                                             ||" << endl;
	gotoXY(x, y++);	cout << "||Desarrolladores:                             ||" << endl;
	gotoXY(x, y++);	cout << "||                                             ||" << endl;
	gotoXY(x, y++);	cout << "||         Andrey Arguedas Espinoza            ||" << endl;
	gotoXY(x, y++);	cout << "||         Michael Chen Wang                   ||" << endl;
	gotoXY(x, y++);	cout << "||                                             ||" << endl;
	gotoXY(x, y++);	cout << "================================================= " << endl;

	gotoXY(x-14, y+4);	cout << "Digite ENTER para comenzar..." << endl;
	cin.get();

}


void Interfaz::entornoPagina(int x, int y){

	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                  Digite la pagina hacia la que desea dirigirse               |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|             *****************************************************            |" << endl;
	gotoXY(x, y++);	cout << "|             |                                                   |            |" << endl;
	gotoXY(x, y++);	cout << "|             *****************************************************            |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|    Presione ENTER para acceder.                      Presione 0 para salir.  |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(15,7); //Para que el teclado quede en la posicion de la cajita
}

void Interfaz::mostrarPaginaActual(string pagina) {
	int x = 25, y = 7;
	gotoXY(x, y++); cout << "Estas en la pagina: " << pagina << endl;
}

void Interfaz::plantillaPagina(int x,int y,string name){
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|******************************************************************************|" << endl;
	gotoXY(x, y++);	cout << "|Te encuentras en la pagina:                                                   |" << endl;
	gotoXY(x, y++);	cout << "|******************************************************************************|" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|             *****************************************************            |" << endl;
	gotoXY(x, y++);	cout << "|             |                                                   |            |" << endl;
	gotoXY(x, y++);	cout << "|             *****************************************************            |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|    Presione ENTER para acceder.                      Presione 0 para salir.  |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void Interfaz::mostrarListaPaginas(list<Nodo*> listas) {
	int x = 30, y = 9;

	gotoXY(x, y++); cout<< "Lista de pagina(s): " << endl;
	list<Nodo*>::iterator it = listas.begin();
	int i = 0;
	while ( it != listas.end()){
		gotoXY(x, y++); cout << ++i << " : " << (*it)->getNombre() << ".";
	}

	x = 25;	y++;

	gotoXY(x, y++); cout << "Para ingresar a una de las paginas, ingrese el numero correspondiente" << endl; 
	gotoXY(x, y++); cout << "Presione 'T' para ingresar una pagina nueva para esta pagina" << endl;	
	gotoXY(x, y++); cout << "Presione 'N' para ingresar una pagina desligada a esta" << endl; 
 
}

void Interfaz::mostrarOpcionNuevaPagina() {

	int x = 25, y = 7;
	gotoXY(x, y++); cout << "Ingrese el nombre de la pagina nueva: "<< endl;
	gotoXY(x+4, y+2);

}

Interfaz::~Interfaz(void)
{
}
