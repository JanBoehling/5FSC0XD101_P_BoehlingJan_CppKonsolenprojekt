#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	 void setMonsterCard() override;
	 std::string getMonsterCard() const;
};
