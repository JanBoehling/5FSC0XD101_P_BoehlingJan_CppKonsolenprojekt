#pragma once
#include <functional>
#include <iostream>
#include <string>

template <typename T>
class CustomExtensions
{
public:
	inline static void inputPromt(std::string inputText, T* variable, std::function<bool()> breakCondition, std::string failText)
	{
		while (1)
		{
			std::cout << inputText << ": " << std::endl;
			std::cin >> *variable;

			if (breakCondition == nullptr) break;
			if (breakCondition()) break;
			
			std::cin.clear(); // Clears bad input flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards input buffer with max amount of characters
			std::cout << failText << std::endl;
		}

		variable = nullptr;
		breakCondition = nullptr;
	}
};
