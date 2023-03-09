#include "ExpressionValidator.h"

ExpressionValidator::ExpressionValidator() : m_regex("^(\\(?\\d+\\s?[\\+\\-\\*\\/]\\s?)+\\d+\\)?$")
{
}

bool ExpressionValidator::Validate(const std::string& expression)
{
	return std::regex_match(expression, m_regex);
}
