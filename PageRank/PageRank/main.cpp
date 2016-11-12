#include "Control.h"
#include "Windows.h"

int main(){

	HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1000, 500, TRUE);

	
	Control * c = new Control();
	c->iniciarBuscador();
	delete c;
	return 0;
}