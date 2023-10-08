﻿#include "Troll.h"

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

std::string Troll::getMonsterCard() const
{
	return monsterCard;
}
