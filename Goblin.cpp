#include "Goblin.h"

void Goblin::setMonsterCard()
{
	// Source: 
	// https://www.asciiart.eu/video-games/other
	// https://ascii.co.uk/art/goblin
	monsterCard =
		" ________________________________________\n"
		"|\\ ____________________________________ /|\n"
		"| | _                                _ | |\n"
		"| |(+)        -------------         (+)| |\n"
		"| | ~          G O B L I N           ~ | |\n"
		"| |            -----------             | |\n"
		"| |                                    | |\n"
		"| |                                    | |\n"
		"| |              ,      ,              | |\n"
		"| |             /(.-\"\"-.)\\             | |\n"
		"| |         |\\  \\/      \\/  /|         | |\n"
		"| |         | \\ / =.  .= \\ / |         | |\n"
		"| |         \\( \\   o\\/o   / )/         | |\n"
		"| |          \\_, '-/  \\-' ,_/          | |\n"
		"| |            /   \\__/   \\            | |\n"
		"| |            \\ \\__/\\__/ /\\           | |\n"
		"| |          ___\\ \\|--|/ /___          | |\n"
		"| |        /`    \\      /    `\\        | |\n"
		"| |       /       '----'       \\       | |\n"
		"| |                                    | |\n"
		"| |                                    | |\n"
		"| |                                    | |\n"
		"| |                                    | |\n"
		"| | _                                _ | |\n"
		"| |(+)                              (+)| |\n"
		"| | ~                                ~ | |\n"
		"|/ ------------------------------------ \\|\n"
		" ----------------------------------------\n";
}

//std::vector<std::string> Goblin::getMonsterCard() const
//{
//	std::vector<std::string> card(Monster::getMonsterCardHeight());
//
//	int lastPosition = -1;
//	for (int i = 0; i < Monster::getMonsterCardHeight(); i++)
//	{
//		int breakPos = Goblin::monsterCard.find('\n', lastPosition + 1);
//		card[i] = Goblin::monsterCard.substr(lastPosition + 1, breakPos);
//		lastPosition = breakPos;
//	}
//
//	return card;
//}
