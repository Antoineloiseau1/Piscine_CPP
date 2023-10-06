#include "RPN.hpp"
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <cstdlib>


int	parse_token(std::string token)
{
	if (token.length() > 1)
		return OTHER;
	else if (isoperator(token[0]))
		return OPERATOR;
	else if (isdigit(token[0]))
		return DIGIT;
	else
		return OTHER;
}
		
bool	isoperator(char c)
{
	return  (c == '+' || c == '-' || c == '*' || c == '/');
}

void	add(std::stack<int> & s)
{
	int result = 0;

	while(!s.empty())
	{
		result += s.top();
		s.pop();
	}
	s.push(result);
}

void	substract(std::stack<int> & s)
{
	int result = 0;

	while(!s.empty())
	{
		result -= s.top();
		s.pop();
	}
	s.push(result);
}

void	multiply(std::stack<int> & s)
{
	int result = 0;

	while(!s.empty())
	{
		result *= s.top();
		s.pop();
	}
	s.push(result);
}

void	divide(std::stack<int> & s)
{
	int result = 0;

	while(!s.empty())
	{
		result /= s.top();
		s.pop();
	}
	s.push(result);
}

void	compute_expression(std::stack<int> & s, std::string token)
{
	if (token == "+")
	{
		add(s);
	}
	else if (token == "-")
	{
		substract(s);
	}
	else if (token == "*")
	{
		multiply(s);
	}
	else
	{
		divide(s);
	}
}

void	RPN(const char *expression)
{
	std::stack<int>		s;
	std::istringstream	iss(expression);
	std::string			token;
	
	while(iss >> token)
	{
		int t = parse_token(token);
		switch (t)
		{
			case DIGIT:
				s.push(std::atoi(token.c_str()));
				break ;
			case OPERATOR:
				compute_expression(s, token);
				break ;
			default:
				std::cout << "Error\n";
				return ;
		}
	}
	if (parse_token(token) != OPERATOR)
	{
		std::cout << "Error\n";
	}
	else
	{
		std::cout << s.top() << std::endl;
	}
}
