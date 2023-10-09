#include "RPN.hpp"
#include <iostream>
#include <ctype.h> //isdigit
#include <sstream>
#include <cstdlib> //atoi

void	RPN(const char *expression)
{
	std::stack<int>		s;
	std::string			token;
	std::istringstream	iss(expression);
	
	while(iss >> token)
	{
		int t = parse_token(token);
		switch (t)
		{
			case OPERAND:
				s.push(std::atoi(token.c_str()));
				break ;
			case OPERATOR:
				//ex: "1 +"
				if(s.size() < 2)
				{
					std::cout << "Error\n";
					return ;
				}
				compute_expression(s, token);
				break ;
			//token other than "+-*/123456789"
			default:
				std::cout << "Error\n";
				return ;
		}
	}
	//if last token is not an operator ex: "1 2 + 1"
	if (parse_token(token) != OPERATOR)
	{
		std::cout << "Error\n";
	}
	else
	{
		//print result
		std::cout << s.top() << std::endl;
	}
}

int	parse_token(std::string token)
{
	if (token.length() == 1)
	{	
		if (isoperator(token[0]))
		{
			return OPERATOR;
		}
		else if (isdigit(token[0]))
		{
			return OPERAND;
		}
	}
	return OTHER;
}
		
bool	isoperator(char c)
{
	return  (c == '+' || c == '-' || c == '*' || c == '/');
}

void	compute_expression(std::stack<int> & s, std::string & token)
{
	int	rhs = s.top();
	s.pop();
	int lhs = s.top();
	s.pop();

	if (token == "+")
	{
		s.push(lhs + rhs);
	}
	else if (token == "-")
	{
		s.push(lhs - rhs);
	}
	else if (token == "*")
	{
		s.push(lhs * rhs);
	}
	else
	{
		s.push(lhs / rhs);
	}
}

