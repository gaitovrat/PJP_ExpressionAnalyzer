#pragma once

#include <regex>

class ExpressionValidator
{
public:
	ExpressionValidator();

	bool Validate(const std::string& expression);

private:
	std::regex m_regex;
};
