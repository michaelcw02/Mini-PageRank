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

void Interfaz::mostrarPageRank(int x, int y){
	gotoXY(x, y++);	cout << "================================================= " << endl;
	gotoXY(x, y++);	cout << "||         Page ranking de cada pagina         ||" << endl;
	gotoXY(x, y++);	cout << "================================================= " << endl;
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

void Interfaz::plantillaPagina(int x, int y,string name,string paginas){
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|******************************************************************************|" << endl;
	gotoXY(x, y++);	cout << "|Usted esta en la pagina:                                                      |" << endl;
	gotoXY(x+26,y-1); cout<<name;
	gotoXY(x, y++);	cout << "|******************************************************************************|" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|Paginas a las que usted puede dirigirse:                                      |" << endl;
	mostrarListaPaginas(paginas, x+4, y);
	gotoXY(x, y++);	cout << "|";                                                     gotoXY(x+79, y);cout<<"|"<< endl;
	gotoXY(x, y++);	cout << "|";                                                     gotoXY(x+79, y);cout<<"|"<< endl;
	gotoXY(x, y++);	cout << "|Opciones:                                                                     |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|- Presione el numero de la pagina para hacer un click.                        |" << endl;
	gotoXY(x, y++);	cout << "|- Presione el numero de la pagina y seguido una 'a' para acceder a esta.      |" << endl;
	gotoXY(x, y++);	cout << "|- Para visitar una pagina nueva presione la letra N                           |" << endl;
	gotoXY(x, y++);	cout << "|- Digite z para salir                                                         |" << endl;
	gotoXY(x, y++);	cout << "|- Digite 'PR' para ver el page rank de cada pagina.                           |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|Opcion:                                                                       |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x+3,y-2);////Para el teclado
}

void Interfaz::mostrarListaPaginas(string listas, int x, int &y) {
	
	int xStart = x;
	string list = listas;
	gotoXY(x-4, y);	cout << "|"; gotoXY(x+75, y);cout<<"|"<< endl;
	for(int i = 0; i < listas.length(); i++){
		if(listas[i] != '\n'){
			gotoXY(x++,y);cout<<listas[i];
		}else{
			x = xStart;
			gotoXY(x,y++);
			gotoXY(x-4, y);	cout << "|"; gotoXY(x+75, y);cout<<"|"<< endl;
		}
	}
}

void Interfaz::mostrarOpcionNuevaPagina(int x,int y,string name) {
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|----------------------------------------------------------------------------|" << endl;
	gotoXY(x, y++);	cout << "|Usted esta en la pagina:                                                      |" << endl;
	gotoXY(x+26,y-1); cout<<name;
	gotoXY(x, y++);	cout << "|----------------------------------------------------------------------------|" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|Digite el nombre de la pagina que desea crear y visistar:                     |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |"<< endl;
	gotoXY(x, y++);	cout << "|             *****************************************************            |" << endl;
	gotoXY(x, y++);	cout << "|             |                                                   |            |" << endl;
	gotoXY(x, y++);	cout << "|             *****************************************************            |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(15,9); //Para que el teclado quede en la posicion de la cajita

}

void Interfaz::limpiarPantalla(){
	system("cls");
}

void Interfaz::paginaYaExistente(int x,int y){
	gotoXY(x,y);cout<<"La pagina que usted ha digitado ya existe."<<endl;
}



Interfaz::~Interfaz(void)
{
}
