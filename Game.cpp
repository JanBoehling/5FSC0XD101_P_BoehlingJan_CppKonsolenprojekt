#include "Game.h"

// The SetCursorPosition define is from Patrick. It fixes the Windows 11 console bugs with which I have extensively dealt with in my first semester assignment.
#define SetCursorPosition(x, y) printf("\033[%d;%dH",(y), (x))
#define cls printf("\x1b[2J\x1b[3J\x1b[0;0H")
#define pause system("pause")

Game::Game()
{
	Start();
}

Game::~Game()
{
	for (int i = 0; i < contendersAmount; i++)
	{
		delete contenders[i];
		contenders[i] = nullptr;
	}

	delete cursorPosition;
	cursorPosition = nullptr;
}

/// <summary>
/// Initializes the game
/// </summary>
void Game::Start()
{
	ShowTitleScreen();
	MonsterCreation();
	StartGameLoop();

	cls;
}

/// <summary>
/// Prints the ascii art title screen to the console
/// </summary>
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

/// <summary>
/// Initializes the game loop.
/// First it checks, whether the contenders can hurt each other,
/// then it is determined, whose turn it is,
/// then the fight scene is drawed
/// and finally, the fight is started.
/// </summary>
void Game::StartGameLoop()
{
	CanTheyHurtEachother();
	WhoseTurnIsIt();
	DrawFightScene(0);
	Fight();
}

/// <summary>
/// First, it allocates the memory for each monster using a vector.
/// Next, it prints the possible monsters to the console, then lets the player decide, which one they wants to create.
/// After this query, the player is asked to enter the values for the monster.
/// This loops two times.
/// After that, the memory for the available monsters is freed, the contenders' opponents are set and the contenders are printed to the console.
/// </summary>
void Game::MonsterCreation()
{
	std::vector<Monster*> avaliableMonsters;

	avaliableMonsters.emplace_back(new Orc);
	avaliableMonsters.emplace_back(new Troll);
	avaliableMonsters.emplace_back(new Goblin);

	for (int i = 0; i < contendersAmount; i++)
	{
		std::cout << "Please choose your monster:\n" << std::endl;
		for (int j = 0; j < avaliableMonsters.size(); j++)
		{
			std::cout << j + 1 << ": " << typeid(*avaliableMonsters.at(j)).name() << std::endl;
		}

		while (1)
		{
			int chosenMonster;
			std::cout << ">> ";
			std::cin >> chosenMonster;

			int chosenMonsterIndex = chosenMonster - 1;

			if (!(chosenMonster > 0 && chosenMonster <= avaliableMonsters.size()) || avaliableMonsters[chosenMonsterIndex] == nullptr)
			{
				std::cin.clear(); // Clears bad input flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards input buffer with max amount of characters
				continue;
			}

			contenders[i] = avaliableMonsters[chosenMonsterIndex];
			avaliableMonsters.erase(avaliableMonsters.begin() + chosenMonster - 1);

			cls;

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

			cls;

			std::cout << "You created: " << contenders[i]->printStats() << std::endl;

			break;
		}

		std::cout << "Press any key to continue..." << std::endl;
		pause;
	}

	for (int i = 0; i < avaliableMonsters.size(); i++)
	{
		delete avaliableMonsters.at(i);
	}

	contenders[0]->setOpponent(contenders[1]);
	contenders[1]->setOpponent(contenders[0]);

	cls;

	std::cout << "THE CONTENDERS:\n" << contenders[0]->printStats() << '\n' << contenders[1]->printStats() << std::endl;
	std::cout << "Press any key to start the fight!" << std::endl;
	pause;
	
	cls;
}

/// <summary>
/// The damage for the current monster is calculated, then, if the health of one opponent is not zero, the fight scene is redrawn and the next monster gets the turn.
/// Else, the fight is ended and a fight summary is printed to the console.
/// This method is called recursively, as long as the the health of one opponent is not zero.
/// </summary>
void Game::Fight()
{
	//auto delay = std::chrono::milliseconds(fightDelay);
	//std::this_thread::sleep_for(delay);

	cls;

	roundCount++;
	int damage = whoseTurn->doAttack();

	if (whoseTurn->getOpponent()->getHealth() <= 0.f)
	{
		cls;
		
		std::cout << whoseTurn->getName() << " won!\n" << std::endl;
		std::cout << "This fight took " << roundCount << " rounds.\n" << std::endl;
		
		std::cout << "Press any key to return to the menu." << std::endl;
		pause;

		return;
	}
	else
	{
		DrawFightScene(damage);
		WhoseTurnIsIt();
	}

	Fight();
}

/// <summary>
/// The monster-card-line-vectors are cashed and then displayed line by line next to each other.
/// When the cards are finished printing, healthbars displaying their current health are printed below the cards.
/// Lastly, a damage indicator is drawn below one card.
/// </summary>
/// <param name="damage">The value that is displayed by the damage indicator</param>
void Game::DrawFightScene(int damage)
{
	cls;

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

	pause;
}

/// <summary>
/// Determines, whose turn it currently is.
/// If no monster has the turn, one is determined by their speed. The monster with the higher speed gets the turn.
/// If both monsters have the same speed, a random contender is selected.
/// After that, a message, who was selected, is printed to the console.
/// If a contender already had the turn, the contender is switched.
/// </summary>
void Game::WhoseTurnIsIt()
{
	if (whoseTurn == nullptr)
	{
		if (contenders[0]->getSpeed() == contenders[1]->getSpeed())
		{
			srand(static_cast<unsigned int>(time(NULL)));
			whoseTurn = contenders[rand() % 2];
		}
		else if (contenders[0]->getSpeed() > contenders[1]->getSpeed())
		{
			whoseTurn = contenders[0];
		}
		else whoseTurn = contenders[1];

		std::cout << whoseTurn->getName() << " was faster! It attacks first.\n\n" << std::endl;

		std::cout << "Press any key to continue..." << std::endl;
		pause;
		cls;
	}
	else
	{
		whoseTurn = whoseTurn == contenders[0] ? contenders[1] : contenders[0];
	}
}

/// <summary>
/// Checks, if the contenders can hurt eachother.
/// If both contenders do zero damage, a message is printed to the console and the start method is called again.
/// </summary>
void Game::CanTheyHurtEachother()
{
	if (!(contenders[0]->calculateDamage() == 0.f && contenders[1]->calculateDamage() == 0.f)) return;

	cls;
	std::cout << "One or both monster are unable to do damage!" << std::endl;
	std::cout << "Tip: The attack of one monster should be higher than the defense of the other.\n" << std::endl;
	std::cout << "Press any key to return to the main menu..." << std::endl;
	pause;
	cls;
	Start();
}

/// <summary>
/// Draws a colored healthbar to the screen.
/// Allocated memory with the size of the monster card and fills the memory with whitespace chars.
/// Then it overwrites the whitespace characters with #, for how many health the monster percentally has.
/// Then draws the healthbar in color to the console. 
/// </summary>
/// <param name="health">The current health amount of the monster</param>
/// <param name="baseHealth">The maximum health of the monster</param>
void Game::ShowHealthBar(int health, int baseHealth)
{
	auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int redTextColor = 12;
	const int whiteTextColor = 7;
	
	int size = Monster::getMonsterCardWidth() - 2;
	char* healthbar = (char*)malloc(size);

	// Check if memory allocation was successful
	if (healthbar == nullptr) return;

	for (int i = 0; i < size; i++)
	{
		healthbar[i] = ' ';
	}

	float percent = (static_cast<float>(health) / baseHealth) * size;

	// Prevent buffer overrun
	if (percent > size) {
		return;
	}

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

	free(healthbar);
	healthbar = nullptr;
}

/// <summary>
/// Draws a damage indicator below one of the two cards on the console.
/// When first invoked, gets the current cursor position.
/// If the left opponent has the turn, the cursor is set below the right card.
/// Lastly, the indicator text is printed to the console.
/// </summary>
/// <param name="damage"></param>
void Game::DrawDamageIndicator(int damage)
{
	if (damage != 0)
	{
		if (cursorPosition == nullptr)
		{
			cursorPosition = new POINT;
			GetCursorPos(cursorPosition);
		}
		
		int cursorHeight = (*cursorPosition).y;

		if (whoseTurn != nullptr && whoseTurn == contenders[0])
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
