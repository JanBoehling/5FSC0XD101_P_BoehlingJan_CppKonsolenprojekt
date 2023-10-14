#include "Monster.h"

void Monster::Init(std::string name, int health, int attack, int defense, int speed)
{
	Monster::name = name;
	Monster::health = health;
	Monster::baseHealth = health;
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

int Monster::doAttack()
{
	int damage = calculateDamage();
	opponent->reduceHealth(damage);
	return damage;
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

int Monster::getBaseHealth() const
{
	return baseHealth;
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

std::vector<std::string> Monster::getMonsterCard() const
{
	const int height = Monster::getMonsterCardHeight();
	const std::string _monsterCard = monsterCard;

	std::vector<std::string> card(height);

	int lastPosition = -1;
	for (int i = 0; i < height; i++)
	{
		int breakPos = _monsterCard.find('\n', lastPosition + 1);
		card[i] = _monsterCard.substr(lastPosition + 1, breakPos - lastPosition - 1);
		lastPosition = breakPos;
	}

	return card;
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
