#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Monster
{
private:
    Monster* opponent;
    static int const monsterCardHeight = 28;
    static int const monsterCardWidth = 42;

protected:
    std::string name;
    int health = 0;
    int attack = 0;
    int defense = 0;
    int speed = 0;
    std::string monsterCard;

public:
    virtual ~Monster() = default;

    void Init(std::string name, int health, int attack, int defense, int speed);
    virtual void setMonsterCard();

    int calculateDamage();
    void doAttack();
    void reduceHealth(int damage);
    void setOpponent(Monster* opponent);
    Monster* getOpponent() const;
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;
    std::vector<std::string> getMonsterCard() const;
    static int const getMonsterCardWidth();
    static int const getMonsterCardHeight();

    std::string printStats();
};
