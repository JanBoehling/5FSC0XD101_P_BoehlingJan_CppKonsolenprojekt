#include "Monster.h"

Monster::~Monster()
{
	opponent = nullptr;
}

/// <summary>
/// Initializes the monster with its player-chosen values
/// </summary>
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

/// <summary>
/// Calculates the damage based on the attack and the opponent's defense.
/// If damage is less than zero, it is set to zero.
/// </summary>
/// <returns></returns>
int Monster::calculateDamage()
{
	int damage = attack - opponent->getDefense();
	return (damage < 0) ? 0 : damage;
}

/// <summary>
/// Reduces the health of the opponent by the calculated damage.
/// </summary>
/// <returns></returns>
int Monster::doAttack()
{
	int damage = calculateDamage();
	opponent->reduceHealth(damage);
	return damage;
}

/// <summary>
/// Reduces the health by the given damage value
/// </summary>
/// <param name="damage">The amount of damage, the health should be reduced by</param>
void Monster::reduceHealth(int damage)
{
	health -= damage;
}

/// <summary>
/// Sets the opponent to the given value
/// </summary>
void Monster::setOpponent(Monster* opponent)
{
	this->opponent = opponent;
}

/// <summary>
/// Gets a pointer to the opponent
/// </summary>
Monster* Monster::getOpponent() const
{
	return opponent;
}

/// <summary>
/// Gets the name of the monster
/// </summary>
std::string Monster::getName() const
{
	return name;
}

/// <summary>
/// Gets the health value of the monster
/// </summary>
int Monster::getHealth() const
{
	return health;
}

/// <summary>
/// Gets the base health value of the monster
/// </summary>
int Monster::getBaseHealth() const
{
	return baseHealth;
}

/// <summary>
/// Gets the attack value of the monster
/// </summary>
int Monster::getAttack() const
{
	return attack;
}

/// <summary>
/// Gets the defense value of the monster
/// </summary>
int Monster::getDefense() const
{
	return defense;
}

/// <summary>
/// Gets the speed value of the monster
/// </summary>
int Monster::getSpeed() const
{
	return speed;
}

/// <summary>
/// Gets the monsters' ascii art card as a list of every line
/// </summary>
/// <returns>A list containing every line of the ascii art, separated by the newline-char</returns>
std::vector<std::string> Monster::getMonsterCard() const
{
	const int height = Monster::getMonsterCardHeight();
	const std::string _monsterCard = monsterCard;

	std::vector<std::string> card(height);

	int lastPosition = -1;
	for (int i = 0; i < height; i++)
	{
		int first = lastPosition + 1;
		int breakPos = static_cast<unsigned int>(_monsterCard.find('\n', first));

		int last = breakPos - lastPosition - 1;
		card[i] = _monsterCard.substr(first, last);

		lastPosition = breakPos;
	}

	return card;
}

/// <summary>
/// Gets the width of the ascii art monster card
/// </summary>
int const Monster::getMonsterCardWidth()
{
	return monsterCardWidth;
}

/// <summary>
/// Gets the height of the ascii art monster card
/// </summary>
int const Monster::getMonsterCardHeight()
{
	return monsterCardHeight;
}

/// <summary>
/// Generates a string with the stats of the monster.
/// </summary>
std::string Monster::printStats()
{
	std::stringstream stream;

	stream
		<< typeid(*this).name()
		<< " "
		<< name
		<< " with "
		<< health
		<< " HP, "
		<< attack
		<< " attack, "
		<< defense
		<< " defense, "
		<< speed
		<< " speed."
		<< std::endl;

	return stream.str();
}
