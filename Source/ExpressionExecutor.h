#pragma once

#include <vector>
#include <string>

class ExpressionExecutor
{
public:
	float Execute(const std::string& expression);

private:
	void Action(char operand);

	bool IsOperation(char operand);

	int Priority(char operand);

	std::vector<float> m_values;
	std::vector<char> m_operators;
};
