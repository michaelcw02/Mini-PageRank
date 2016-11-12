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

	int x = 35, y = 5;
	
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

	gotoXY(x-8, y+4);	cout << "Digite ENTER para comenzar..." << endl;
	system("pause>nul");

}

void Interfaz::mostrarPageRank(int x, int y, string resultados){
	
	gotoXY(x, y++);	cout << "================================================= " << endl;
	gotoXY(x, y++);	cout << "||         Page ranking de cada pagina         ||" << endl;
	gotoXY(x, y++);	cout << "================================================= " << endl;
	x = x + 4;
	y++;	
	int auxX = x;
	int j = 1;
	gotoXY(x-2, y); cout<<j++<<". ";
	for(int i = 0; i < resultados.length(); i++){
		if(resultados[i] != '\n'){
			gotoXY(x++,y);	cout<<resultados[i];
		}else{
			x = auxX;
			y++;
			if(i != resultados.length() -1) {
			gotoXY(x-2, y); cout<<j++<<". ";
			}
		}
	}
	gotoXY(x-4, y+4);	cout << "Digite ENTER para seguir..." << endl;
	system("pause>nul");

}


void Interfaz::entornoPagina(int x, int y){

	int auxY = y;
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
	gotoXY(x + 15, auxY + 7); //Para que el teclado quede en la posicion de la cajita
}

void Interfaz::mostrarPaginaActual(string pagina) {
	int x = 25, y = 7;
	gotoXY(x, y++); cout << "Estas en la pagina: " << pagina << endl;
}
void Interfaz::plantillaPaginaInicio(int x, int y, string paginas){
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	mostrarListaPaginas(paginas, x+4, y);
	gotoXY(x, y++);	cout << "|";                                                     gotoXY(x+79, y);cout<<"|"<< endl;
	gotoXY(x, y++);	cout << "|";                                                     gotoXY(x+79, y);cout<<"|"<< endl;
	gotoXY(x, y++);	cout << "|Opciones:                                                                     |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|-Presione el numero de la pagina seguido de una 'a' para acceder a ella. '1a' |" << endl;
	gotoXY(x, y++);	cout << "|-Para acceder a una pagina nueva, presione la letra 'O'                       |" << endl;
	gotoXY(x, y++);	cout << "|-Digite 'PR' para ver el page rank de cada pagina.                            |" << endl;
	gotoXY(x, y++);	cout << "|-Digite 'Z' para salir                                                        |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|Opcion:                                                                       |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x+3,y-2);////Para el teclado
}

void Interfaz::plantillaPagina(int x, int y,string name,string paginas){
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|******************************************************************************|" << endl;
	gotoXY(x, y++);	cout << "|Usted se encuentra en:                                                        |" << endl;
	gotoXY(x+24,y-1); cout<<name;
	gotoXY(x, y++);	cout << "|******************************************************************************|" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	mostrarListaPaginas(paginas, x+4, y);
	gotoXY(x, y++);	cout << "|";                                                     gotoXY(x+79, y);cout<<"|"<< endl;
	gotoXY(x, y++);	cout << "|";                                                     gotoXY(x+79, y);cout<<"|"<< endl;
	gotoXY(x, y++);	cout << "|Opciones:                                                                     |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|-Presione el numero de la pagina para hacer un click.                         |" << endl;
	gotoXY(x, y++);	cout << "|-Presione el numero de la pagina seguido de una 'a' para acceder a ella. '1a' |" << endl;
	gotoXY(x, y++);	cout << "|-Para acceder a una pagina nueva a partir de esta, presione la letra 'N'      |" << endl;
	gotoXY(x, y++);	cout << "|-Para acceder a una pagina nueva no relacionada a esta, presione la letra 'O' |" << endl;
	gotoXY(x, y++);	cout << "|-Digite 'PR' para ver el page rank de cada pagina.                            |" << endl;
	gotoXY(x, y++);	cout << "|-Digite 'Z' para salir.                                                       |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "|Opcion:                                                                       |" << endl;
	gotoXY(x, y++);	cout << "|                                                                              |" << endl;
	gotoXY(x, y++);	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gotoXY(x+3,y-2);////Para el teclado
}

void Interfaz::mostrarListaPaginas(string listas, int x, int &y) {
	
	int xStart = x;
	string list = listas;
	gotoXY(x-4, y++);cout << "|Paginas a las que usted puede dirigirse:                                      |" << endl;
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

void Interfaz::mostrarOpcionNuevaPagina(int x, int y, string name) {
	int auxY = y;
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
	gotoXY(x + 15, auxY + 9); //Para que el teclado quede en la posicion de la cajita

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
