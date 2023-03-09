#include "ExpressionExecutor.h"

float ExpressionExecutor::Execute(const std::string& expression)
{
	for (auto it = expression.cbegin(); it != expression.cend(); ++it)
	{
		auto ch = *it;

		if (ch == '(')
		{
			m_operators.push_back(ch);
		}
		else if (ch == ')')
		{
			while (m_operators.back() != '(')
			{
				Action(m_operators.back());
				m_operators.pop_back();
			}

			m_operators.pop_back();
		}
		else if (IsOperation(ch))
		{
			while (m_operators.size() > 0 && Priority(m_operators.back()) >= Priority(ch))
			{
				Action(ch);
				m_operators.pop_back();
			}

			m_operators.push_back(ch);
		}
		else
		{
			std::string number;
			for (; it != expression.cend() && std::isdigit(*it); ++it)
			{
				number.push_back(*it);
			}

			--it;
			m_values.push_back(std::stoi(number));
		}
	}

	while (m_operators.size() > 0)
	{
		Action(m_operators.back());
		m_operators.pop_back();	
	}

	return m_values.back();
}

void ExpressionExecutor::Action(char operand)
{
	auto right = m_values.back();
	m_values.pop_back();
	auto left = m_values.back();
	m_values.pop_back();

	switch (operand)
	{
	case '+':
		m_values.push_back(right + left);
		break;
	case '-':
		m_values.push_back(right - left);
		break;
	case '*':
		m_values.push_back(right * left);
		break;
	case '/':
		m_values.push_back(right / left);
		break;
	}
}

bool ExpressionExecutor::IsOperation(char operand)
{
	return operand == '+' || operand == '-' || operand == '*' || operand == '/';
}

int ExpressionExecutor::Priority(char operand)
{
	switch (operand)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}
