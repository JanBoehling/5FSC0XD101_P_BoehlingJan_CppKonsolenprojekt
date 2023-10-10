#include "Orc.h"

void Orc::setMonsterCard()
{
	// Sources:
	// https://www.asciiart.eu/video-games/other
	// https://www.shutterstock.com/de/image-vector/orc-silhouette-monster-villain-fantasy-vector-732856054
	// https://ascii-generator.site/
	monsterCard = "________________________________________\n"
		"|\\ ____________________________________ /|\n"
		"| | _                                _ | |\n"
		"| |(+)        -------------         (+)| |\n"
		"| | ~             O R C              ~ | |\n"
		"| |            -----------             | |\n"
		"| |                                    | |\n"
		"| |                                    | |\n"
		"| |                ..                  | |\n"
		"| |        .:*%@@- .=+-                | |\n"
		"| |       -@@@@%*: #@@@                | |\n"
		"| |        #%+#+  .+@@@@+.             | |\n"
		"| |           .@.  +@@@@@@*-           | |\n"
		"| |           -@* +@@@@@@@@@=          | |\n"
		"| |            *@@@#%@@@@#=@@:         | |\n"
		"| |             #*  +@@@@- #@=         | |\n"
		"| |             -= =@@@@@@-+@=         | |\n"
		"| |               +@@@@@@@@.           | |\n"
		"| |               %@:#@@.*%=           | |\n"
		"| |               @@.-+:  *@:          | |\n"
		"| |              -@%       %*          | |\n"
		"| |             +*=:       %@-         | |\n"
		"| |                        ..          | |\n"
		"| | _                                _ | |\n"
		"| |(+)                              (+)| |\n"
		"| | ~                                ~ | |\n"
		"|/ ------------------------------------ \\|\n"
		" ----------------------------------------\n";
}

//std::vector<std::string> Orc::getMonsterCard() const
//{
//
//	// Traverse char[]
//	// if char[i] == '\0' break
//	// write char[i] into temp string
//	// if char[i] == '\n', add temp string to vector and iterate forward
//	/*std::vector<std::string> card(Monster::getMonsterCardHeight());
//	std::string str = Orc::monsterCard;
//
//	while (1) {
//		int index = str.find('\n');
//		if (index != std::string::npos) {
//			card.push_back(str.substr(0, index));
//			str = str.substr(index + 1);
//			if (str.size() == 0) card.push_back(str);
//		}
//		else {
//			card.push_back(str);
//			break;
//		}
//	}*/
//
//	/*const char* cardArr = monsterCard.c_str();
//	std::string temp;
//	int i = 1;
//	int stringCount = 0;
//	while (1)
//	{
//		if (cardArr[i] == '\0') break;
//		if (cardArr[i] == '\n')
//		{
//			card.emplace_back(temp);
//			i++;
//			stringCount++;
//			continue;
//		}
//
//		temp += cardArr[i];
//		i++;
//	}*/
//
//	//signed int lastPosition = -1;
//	//for (int i = 0; i < Monster::getMonsterCardHeight(); i++)
//	//{
//	//	signed int breakPos = monsterCard.find('\n');
//	//	card[i] = monsterCard.substr(lastPosition + 1, breakPos);
//	//	lastPosition = breakPos;
//	//}
//
//	std::vector<std::string> card(Monster::getMonsterCardHeight());
//
//	int lastPosition = -1;
//	for (int i = 0; i < Monster::getMonsterCardHeight(); i++)
//	{
//		int breakPos = Orc::monsterCard.find('\n', lastPosition + 1);
//		card[i] = Orc::monsterCard.substr(lastPosition + 1, breakPos);
//		lastPosition = breakPos;
//	}
//
//	return card;
//}
