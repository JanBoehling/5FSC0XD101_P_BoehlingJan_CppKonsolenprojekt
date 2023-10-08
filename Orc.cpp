#include "Orc.h"

void Orc::setMonsterCard()
{
	// Sources:
	// https://www.asciiart.eu/video-games/other
	// https://www.shutterstock.com/de/image-vector/orc-silhouette-monster-villain-fantasy-vector-732856054
	// https://ascii-generator.site/
	monsterCard =
		" ________________________________________\n"
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

std::string Orc::getMonsterCard() const
{
	return monsterCard;
}
