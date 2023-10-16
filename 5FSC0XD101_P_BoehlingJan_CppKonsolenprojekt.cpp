#define ever (;;)
#include "Game.h"

int main()
{
	for ever
	{
		auto game = new Game();
		delete game;
		game = nullptr;
	}

    return 0;
}
