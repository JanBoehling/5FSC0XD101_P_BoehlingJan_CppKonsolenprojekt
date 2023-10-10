#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>

#include "CustomExtensions.h"
#include "Monster.h"
#include "Orc.h"
#include "Troll.h"
#include "Goblin.h"

class Game
{
private:
	Monster* contenders[2];
	Monster* whoseTurn;
	unsigned int roundCount = 0;
	const int fightDelay = 500;

public:
	Game();
	void Start();
	void ShowTitleScreen();
	void StartGameLoop();
	void MonsterCreation();
	void Fight();
	void DrawFightScene();
	void WhoseTurnIsIt();
	void CanTheyHurtEachother();
	static void ShowHealthBar(float health, float baseHealth);
};
