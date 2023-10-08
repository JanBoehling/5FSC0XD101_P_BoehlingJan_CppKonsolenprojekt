#include "Monster.h"

void Monster::Init(std::string name, int health, int attack, int defense, int speed)
{
	Monster::name = name;
	Monster::health = health;
	Monster::defense = defense;
	Monster::attack = attack;
	Monster::speed = speed;

	setMonsterCard();
}

void Monster::setMonsterCard()
{
}

int Monster::calculateDamage()
{
	int damage = attack - opponent->getDefense();
	return (damage < 0) ? 0 : damage;
}

void Monster::doAttack()
{
	int damage = calculateDamage();
	opponent->reduceHealth(damage);
}

void Monster::reduceHealth(int damage)
{
	health -= damage;
}

void Monster::setOpponent(Monster* opponent)
{
	this->opponent = opponent;
}

Monster* Monster::getOpponent() const
{
	return opponent;
}

std::string Monster::getName() const
{
	return name;
}

int Monster::getHealth() const
{
	return health;
}

int Monster::getAttack() const
{
	return attack;
}

int Monster::getDefense() const
{
	return defense;
}

int Monster::getSpeed() const
{
	return speed;
}

std::string Monster::getMonsterCard() const
{
	return monsterCard;
}

int const Monster::getMonsterCardWidth()
{
	return monsterCardWidth;
}

int const Monster::getMonsterCardHeight()
{
	return monsterCardHeight;
}

std::string Monster::printStats()
{
	std::stringstream stream;
	stream << typeid(*this).name() << " " << name << " with " << health << " HP, " << attack << " attack, " << defense << " defense, " << speed << " speed." << std::endl;
	return stream.str();
}
