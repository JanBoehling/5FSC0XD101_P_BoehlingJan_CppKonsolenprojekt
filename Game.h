#pragma once
#define NOMINMAX // This fixes min() and max() from the istream

#include <iostream>
//#include <thread>
//#include <chrono>
#include <vector>
#include <Windows.h>
#include <winuser.h>

#include "CustomExtensions.h"
#include "Monster.h"
#include "Orc.h"
#include "Troll.h"
#include "Goblin.h"

class Game
{
private:
	const int contendersAmount = 2;
	Monster* contenders[2];
	Monster* whoseTurn;
	unsigned int roundCount = 0;
	const int fightDelay = 500;
	POINT* cursorPosition;

public:
	Game();
	~Game();
	void Start();
	void ShowTitleScreen();
	void StartGameLoop();
	void MonsterCreation();
	void Fight();
	void DrawFightScene(int damage);
	void WhoseTurnIsIt();
	void CanTheyHurtEachother();
	static void ShowHealthBar(int health, int baseHealth);
	void DrawDamageIndicator(int damage);
};
