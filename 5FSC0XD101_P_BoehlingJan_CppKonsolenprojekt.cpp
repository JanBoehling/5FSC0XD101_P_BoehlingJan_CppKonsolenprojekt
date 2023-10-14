#include "Game.h"

/* This project needs to encompas:
* Klassen & OOP
* Pointer & Objekte
* Memory Management
* Fange unzulässigen User-Input ab
*/

int main()
{
	while (1)
	{
		auto game = new Game();
		delete game;
	}

    return 0;
}
