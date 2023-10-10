#include "Game.h"

Game::Game()
{
	system("pause");
	auto a = new Orc;
	a->Init("", 1, 1, 1, 1);

	auto b = new Troll;
	b->Init("", 1, 1, 1, 1);

	auto aCard = a->getMonsterCard();
	auto bCard = b->getMonsterCard();
	
	for (int i = 0; i < Monster::getMonsterCardHeight() ; i++)
	{
		std::cout << aCard[i] << "\t\t\t" << bCard[i] << std::endl;
	}

	return;
	Start();
}

void Game::Start()
{
	ShowTitleScreen();
	MonsterCreation();
	StartGameLoop();

	system("cls");
	Start();
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
		"          |_____/|_|_| |_| |_|\\__,_|_|\__,_|\\__\\___/|_|             \n";

	std::cout << title << std::endl;
}

void Game::StartGameLoop()
{
	CanTheyHurtEachother();
	WhoseTurnIsIt();
	DrawFightScene();
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

			system("cls");

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

			system("cls");

			std::cout << "You created: " << contenders[i]->printStats() << std::endl;

			break;
		}

		std::cout << "Press any key to continue..." << std::endl;
		system("pause");
	}

	contenders[0]->setOpponent(contenders[1]);
	contenders[1]->setOpponent(contenders[0]);

	system("cls");

	std::cout << "THE CONTENDERS:\n" << contenders[0]->printStats() << '\n' << contenders[1]->printStats() << std::endl;
	std::cout << "Press any key to start the fight!" << std::endl;
	system("pause");
	
	system("cls");
}

void Game::Fight()
{
	auto delay = std::chrono::milliseconds(fightDelay);
	std::this_thread::sleep_for(delay);

	system("cls");

	roundCount++;
	whoseTurn->doAttack();

	if (whoseTurn->getOpponent()->getHealth() <= 0.f)
	{
		system("cls");
		
		std::cout << whoseTurn->getName() << " won!\n" << std::endl;
		std::cout << "This fight took " << roundCount << " rounds.\n" << std::endl;
		
		std::cout << "Press any key to return to the menu." << std::endl;
		system("pause");

		return;
	}
	else
	{
		DrawFightScene();
		WhoseTurnIsIt();
	}

	Fight();
}

// TODO
void Game::DrawFightScene()
{
	system("cls");

	for (int i = 1; i <= Monster::getMonsterCardHeight(); i++)
	{
		std::cout << contenders[0]->getMonsterCard()[i] << "\t\t\t" << contenders[1]->getMonsterCard()[i] << std::endl;
	}
	std::cout << std::endl;

	ShowHealthBar(contenders[0]->getHealth(), 100); //contenders[0]->getBaseHealth()
	std::cout << "\t\t\t" << std::endl;
	ShowHealthBar(contenders[1]->getHealth(), 100);

	system("pause");

	/*for (int i = 0; i < 2; i++)
	{
		std::cout << contenders[i]->getName() << " has " << contenders[i]->getHealth() << " hp." << std::endl;
	}*/
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
		system("cls");
	}
	else
	{
		whoseTurn = whoseTurn == contenders[0] ? contenders[1] : contenders[0];
	}
}

void Game::CanTheyHurtEachother()
{
	if (!(contenders[0]->calculateDamage() == 0.f && contenders[1]->calculateDamage() == 0.f)) return;

	system("cls");
	std::cout << "One or both monster are unable to do damage!" << std::endl;
	std::cout << "Tip: The attack of one monster should be higher than the defense of the other.\n" << std::endl;
	std::cout << "Press any key to return to the main menu..." << std::endl;
	system("pause");
	system("cls");
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
	std::cout << "}" << std::endl;
}
