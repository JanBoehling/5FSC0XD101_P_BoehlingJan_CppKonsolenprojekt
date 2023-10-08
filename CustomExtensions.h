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

			if (breakCondition == nullptr) return;
			if (breakCondition()) break;
			else std::cout << *variable << std::endl;
		}
	}
};
