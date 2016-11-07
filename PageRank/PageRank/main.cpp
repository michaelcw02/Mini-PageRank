#include "Control.h"

int main(){
	Control * c = new Control();
	c->iniciarBuscador();
	delete c;
	return 0;
}