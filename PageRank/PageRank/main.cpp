#include "Control.h"


int main(){
	Control * c = new Control();
	c->propiedadesConsola(); //Para que la consola crezca automaticamente
	c->iniciarBuscador();
	delete c;
	return 0;
}