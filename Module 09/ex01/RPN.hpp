#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

enum TOKEN {
	OTHER = 0,
	OPERATOR = 1,
	DIGIT = 2
};

void	RPN(const char *expression);
int		parse_token(std::string token);
bool	isoperator(char c);
void	add(std::stack<int> & s);
void	substract(std::stack<int> & s);
void	multiply(std::stack<int> & s);
void	divide(std::stack<int> & s);

#endif
