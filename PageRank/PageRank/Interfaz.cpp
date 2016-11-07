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
cout<<"######  ### ####### #     # #     # ####### #     # ### ######  #######"<<endl; 
cout<<"#     #  #  #       ##    # #     # #       ##    #  #  #     # #     #"<<endl;
cout<<"#     #  #  #       # #   # #     # #       # #   #  #  #     # #     #"<<endl; 
cout<<"######   #  #####   #  #  # #     # #####   #  #  #  #  #     # #     #"<<endl; 
cout<<"#     #  #  #       #   # #  #   #  #       #   # #  #  #     # #     #"<<endl; 
cout<<"#     #  #  #       #    ##   # #   #       #    ##  #  #     # #     #"<<endl;
cout<<"######  ### ####### #     #    #    ####### #     # ### ######  #######"<<endl; 
}


void Interfaz::entornoPagina(int x, int y, string header){
	cout<<"******************************************************************************"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"*                                                                            *"<<endl;
	cout<<"******************************************************************************"<<endl;
}

Interfaz::~Interfaz(void)
{
}
