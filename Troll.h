#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
	void setMonsterCard() override;
	std::string getMonsterCard() const;
};
