#include "Game.h"

/* TODO
* Memory management
* Handle incorrect input (std::cin)
*/

// These two defines are from Patrick. They fix the Windows 11 console bugs with which I have extensively dealt with in my first semester assignment.
#define SetCursorPosition(x, y) printf("\033[%d;%dH",(y), (x))
#define Cls() printf("\033[H\033[J")

Game::Game()
{
	Start();
}

void Game::Start()
{
	ShowTitleScreen();
	MonsterCreation();
	StartGameLoop();

	Cls();
}

void Game::ShowTitleScreen()
{
	std::string title =
		"  __  __                 _            _                          __ \n"
		" |  \\/  |               | |          | |                        / _|\n"
		" | \\  / | ___  _ __  ___| |_ ___ _ __| | ____ _ _ __ ___  _ __ | |_ \n"
		" | |\\/| |/ _ \\| '_ \\/ __| __/ _ \\ '__| |/ / _` | '_ ` _ \\| '_ \\|  _|\n"
		" | |  | | (_) | | | \\__ \\ ||  __/ |  |   < (_| | | | | | | |_) | |  \n"
		" |_|  |_|\\___/|_| |_|___/\\__\\___|_| _|_|\\_\\__,_|_| |_| |_| .__/|_|  \n"
		"           / ____(_)               | |     | |           | |        \n"
		"          | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __|_|        \n"
		"           \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|          \n"
		"           ____) | | | | | | | |_| | | (_| | || (_) | |             \n"
		"          |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|             \n";

	std::cout << title << std::endl;
}

void Game::StartGameLoop()
{
	CanTheyHurtEachother();
	WhoseTurnIsIt();
	DrawFightScene(0);
	Fight();
}

void Game::MonsterCreation()
{
	std::vector<Monster*> avaliableMonsters;

	avaliableMonsters.emplace_back(new Orc);
	avaliableMonsters.emplace_back(new Troll);
	avaliableMonsters.emplace_back(new Goblin);

	// 2 iterations to choose the 2 contenders
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Please choose your monster:\n" << std::endl;
		for (int j = 0; j < avaliableMonsters.size(); j++)
		{
			std::cout << j + 1 << ": " << typeid(*avaliableMonsters.at(j)).name() << std::endl;
		}

		while (1)
		{
			int chosenMonsterIndex = -1;
			std::cin >> chosenMonsterIndex;

			if (!(chosenMonsterIndex > 0 && chosenMonsterIndex <= avaliableMonsters.size()) || avaliableMonsters[chosenMonsterIndex - 1] == nullptr) continue;

			contenders[i] = avaliableMonsters[chosenMonsterIndex - 1];
			avaliableMonsters.erase(avaliableMonsters.begin() + chosenMonsterIndex - 1);

			Cls();

			std::string name;
			int health = 0;
			int attack = 0;
			int defense = 0;
			int speed = 0;

			CustomExtensions<std::string>::inputPromt("Name", &name, [&name] { return name.length() > 0; }, "Enter a name...");
			CustomExtensions<int>::inputPromt("Health", &health, [&health] { return health > 0; }, "The value should be greater than 0...");
			CustomExtensions<int>::inputPromt("Attack", &attack, [&attack] { return attack > 0; }, "The value should be greater than 0...");
			CustomExtensions<int>::inputPromt("Defense", &defense, [&defense] { return defense > 0; }, "The value should be greater than 0...");
			CustomExtensions<int>::inputPromt("Speed", &speed, [&speed] { return speed > 0; }, "The value should be greater than 0...");
			
			contenders[i]->Init(name, health, attack, defense, speed);

			Cls();

			std::cout << "You created: " << contenders[i]->printStats() << std::endl;

			break;
		}

		std::cout << "Press any key to continue..." << std::endl;
		system("pause");
	}

	contenders[0]->setOpponent(contenders[1]);
	contenders[1]->setOpponent(contenders[0]);

	Cls();

	std::cout << "THE CONTENDERS:\n" << contenders[0]->printStats() << '\n' << contenders[1]->printStats() << std::endl;
	std::cout << "Press any key to start the fight!" << std::endl;
	system("pause");
	
	Cls();
}

void Game::Fight()
{
	//auto delay = std::chrono::milliseconds(fightDelay);
	//std::this_thread::sleep_for(delay);

	Cls();

	roundCount++;
	int damage = whoseTurn->doAttack();

	if (whoseTurn->getOpponent()->getHealth() <= 0.f)
	{
		Cls();
		
		std::cout << whoseTurn->getName() << " won!\n" << std::endl;
		std::cout << "This fight took " << roundCount << " rounds.\n" << std::endl;
		
		std::cout << "Press any key to return to the menu." << std::endl;
		system("pause");

		return;
	}
	else
	{
		DrawFightScene(damage);
		WhoseTurnIsIt();
	}

	Fight();
}

void Game::DrawFightScene(int damage)
{
	Cls();

	auto card1 = contenders[0]->getMonsterCard();
	auto card2 = contenders[1]->getMonsterCard();
	int height = Monster::getMonsterCardHeight();

	for (int i = 0; i < height; i++)
	{
		std::cout << card1[i] << "\t\t\t" << card2[i] << std::endl;
	}
	std::cout << std::endl;

	ShowHealthBar(contenders[0]->getHealth(), contenders[0]->getBaseHealth());
	std::cout << "\t\t\t";
	ShowHealthBar(contenders[1]->getHealth(), contenders[1]->getBaseHealth());
	std::cout << std::endl;
	DrawDamageIndicator(damage);

	system("pause");
}

void Game::WhoseTurnIsIt()
{
	if (whoseTurn == nullptr)
	{
		if (contenders[0]->getSpeed() == contenders[1]->getSpeed())
		{
			srand(time(NULL));
			whoseTurn = contenders[rand()%2];
		}
		else if (contenders[0]->getSpeed() > contenders[1]->getSpeed())
		{
			whoseTurn = contenders[0];
		}
		else whoseTurn = contenders[1];

		std::cout << whoseTurn->getName() << " was faster! It attacks first.\n\n" << std::endl;

		std::cout << "Press any key to continue..." << std::endl;
		system("pause");
		Cls();
	}
	else
	{
		whoseTurn = whoseTurn == contenders[0] ? contenders[1] : contenders[0];
	}
}

void Game::CanTheyHurtEachother()
{
	if (!(contenders[0]->calculateDamage() == 0.f && contenders[1]->calculateDamage() == 0.f)) return;

	Cls();
	std::cout << "One or both monster are unable to do damage!" << std::endl;
	std::cout << "Tip: The attack of one monster should be higher than the defense of the other.\n" << std::endl;
	std::cout << "Press any key to return to the main menu..." << std::endl;
	system("pause");
	Cls();
	Start();
}

void Game::ShowHealthBar(float health, float baseHealth)
{
	auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int redTextColor = 12;
	const int whiteTextColor = 7;
	
	int size = Monster::getMonsterCardWidth() - 2;
	char* healthbar = (char*)malloc(size);

	for (int i = 0; i < size; i++)
	{
		healthbar[i] = ' ';
	}

	float percent = (health / baseHealth) * size;

	for (int i = 0; i < percent; i++)
	{
		healthbar[i] = '#';
	}
	
	std::cout << "{";
	SetConsoleTextAttribute(hConsole, redTextColor);
	for (int i = 0; i < size; i++)
	{
		std::cout << healthbar[i];
	}
	SetConsoleTextAttribute(hConsole, whiteTextColor);
	std::cout << "}";
}

void Game::DrawDamageIndicator(int damage)
{
	if (damage != 0)
	{
		POINT currentCursorPos;
		GetCursorPos(&currentCursorPos);
		int cursorHeight = currentCursorPos.y;

		if (whoseTurn != nullptr && whoseTurn == contenders[1])
		{
			// Sets cursor position underneath the left card
			//SetCursorPosition(0, cursorHeight + 1);
		}
		else if (whoseTurn != nullptr && whoseTurn == contenders[0])
		{
			// Sets cursor position underneath the right card
			SetCursorPosition(Monster::getMonsterCardWidth(), cursorHeight + 1);
			std::cout << "\t\t\t";
		}

		if (whoseTurn != nullptr)
		{
			std::cout
				<< "-"
				<< damage
				<< "HP!"
				<< "\t"
				<< whoseTurn->getOpponent()->getName()
				<< " still has "
				<< whoseTurn->getOpponent()->getHealth()
				<< " HP."
				<< std::endl;
		}
	}
	else std::cout << std::endl;
	std::cout << "\n" << std::endl;
}
