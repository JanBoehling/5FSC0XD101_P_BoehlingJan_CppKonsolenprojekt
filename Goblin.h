#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	void setMonsterCard() override;
	std::string getMonsterCard() const;
};
