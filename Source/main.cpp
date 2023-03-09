// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <ranges>

#include "ExpressionValidator.h"
#include "ExpressionExecutor.h"


int main()
{
	int count;
	std::string expression;
	ExpressionValidator validator;
	ExpressionExecutor executor;

	std::cout << "PJP - ExpressionAnalyzer\n";
	std::getline(std::cin, expression);
	count = std::stoi(expression);
	
	if (count <= 0)
	{
		std::cout << "Unable to parse it to number.\n";
		return EXIT_FAILURE;
	}

	for (const auto& _ : std::ranges::views::iota(0, count))
	{
		std::getline(std::cin, expression);
		
		if (validator.Validate(expression))
		{
			expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end());
			auto val = executor.Execute(expression);
			std::cout << val << std::endl;
		}
		else
		{
			std::cout << "ERROR\n";
		}
	}

	return EXIT_SUCCESS;
}
