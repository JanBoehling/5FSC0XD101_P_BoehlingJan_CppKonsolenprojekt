#pragma once
#include <functional>
#include <iostream>
#include <string>

template <typename T>
class CustomExtensions
{
public:
	/// <summary>
	/// Asks the user for input. 
	/// Gets user input, then checks for break condition. If condition is not met, input is cleared and fail text is displayed.
	/// </summary>
	/// <param name="inputText">The prompt text</param>
	/// <param name="variable">The variable to store the value in</param>
	/// <param name="breakCondition">The condition that validates the input</param>
	/// <param name="failText">The text that is displayed when input is invalid</param>
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
