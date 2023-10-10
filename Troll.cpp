#include "Troll.h"

void Troll::setMonsterCard()
{
	// Sources:
	// https://www.asciiart.eu/video-games/other
	// https://www.shutterstock.com/de/image-illustration/troll-fantasy-creature-inquisative-expression-leaning-1908957499
	// https://ascii-generator.site/
	monsterCard =
		" ________________________________________\n"
		"|\\ ____________________________________ /|\n"
		"| | _                                _ | |\n"
		"| |(+)         -----------          (+)| |\n"
		"| | ~           T R O L L            ~ | |\n"
		"| |             ---------              | |\n"
		"| |                                    | |\n"
		"| |                   .                | |\n"
		"| |             :=-=++==:.             | |\n"
		"| |           =*+++##*#+++=-:.         | |\n"
		"| |         .=+#####*####*+=---        | |\n"
		"| |        .=++*##%###%%##*+===-.      | |\n"
		"| |       :==**#+#%%#%%###%#*+==-:     | |\n"
		"| |      .====*-  +#%%%%%###*=+===.    | |\n"
		"| |     .+-+*+.  .+%%%%#%%%%=:+==*+    | |\n"
		"| |     .*-==   .=**#%%%%%%%+ :-++=    | |\n"
		"| |      +===   .**+*##%%##%*.===+:    | |\n"
		"| |      ===-    *++*##%%###*:===-     | |\n"
		"| |      :==:    *+##=+%%%###.===.     | |\n"
		"| |      .+=-    :=*#--%%%%#=.==+.     | |\n"
		"| |      :+=--:.   +**. =#+::-==+:     | |\n"
		"| |      :++==++:-+*+.  .-++====*=     | |\n"
		"| |       -=---:.          :==*++:     | |\n"
		"| | _                                _ | |\n"
		"| |(+)                              (+)| |\n"
		"| | ~                                ~ | |\n"
		"|/ ------------------------------------ \\|\n"
		" ----------------------------------------\n";
}

//std::vector<std::string> Troll::getMonsterCard() const
//{
//	const int height = Monster::getMonsterCardHeight();
//
//	std::vector<std::string> card(height);
//
//	int lastPosition = -1;
//	for (int i = 0; i < height; i++)
//	{
//		int breakPos = Troll::monsterCard.find('\n', lastPosition + 1);
//		card[i] = Troll::monsterCard.substr(lastPosition + 1, breakPos);
//		lastPosition = breakPos;
//	}
//
//	return card;
//}
