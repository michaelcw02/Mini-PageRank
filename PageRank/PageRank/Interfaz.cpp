#include "Interfaz.h"


Interfaz::Interfaz(void)
{
}

void Interfaz::gotoXY(int x, int y) {
	COORD position = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, position);
}

void Interfaz::mostrarBanner(){
	system("color A");

	int x = 30, y = 8;
	
	clearScreen();
	gotoXY(x, y++);	cout << "================================================= " << endl;
	gotoXY(x, y++);	cout << "||		Universidad Nacional de Costa Rica		||" << endl;
	gotoXY(x, y++);	cout << "||			Bienvenido al Mini-PageRank			||" << endl;
	gotoXY(x, y++);	cout << "||												||" << endl;
	gotoXY(x, y++);	cout << "||			Desarrolladores:					||" << endl;
	gotoXY(x, y++);	cout << "||                                  			||" << endl;
	gotoXY(x, y++);	cout << "||				Andrey Arguedas Espinoza		||" << endl;
	gotoXY(x, y++);	cout << "||				Michael Chen Wang				||" << endl;
	gotoXY(x, y++);	cout << "||												||" << endl;
	gotoXY(x, y++);	cout << "================================================= " << endl;
	cin.get();

}


void Interfaz::entornoPagina(int x, int y, string header){

	int x = 20, y = 5;

	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "|																				|" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

}

void Interfaz::mostrarPaginaActual(string pagina) {
	int x = 25, y = 7;
	gotoXY(x, y++); cout << "Estas en la pagina: " << pagina << endl;
}

void Interfaz::mostrarListaPaginas(string[] array) {
	int x = 30, y = 9;

	gotoXY(x, y++); cout<< "Lista de pagina(s): " << endl;
	for (int i = 0; i < array.size(); i++) {
		gotoXY(x, y++); cout << i+1 << ". " << array[i] << ".";
	}

	x = 25;	y++;

	gotoXY(x, y++); cout << "Para ingresar a una de las paginas, ingrese el numero correspondiente" << endl; 
	gotoXY(x, y++); cout << "Presione 'T' para ingresar una pagina nueva para esta pagina" << endl;	
	gotoXY(x, ++y++); cout << "Presione 'N' para ingresar una pagina desligada a esta" << endl; 
 
}

Interfaz::~Interfaz(void)
{
}
