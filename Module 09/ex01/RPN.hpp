#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

enum TOKEN {
	OTHER = 0,
	OPERATOR = 1,
	OPERAND = 2
};

void	RPN(const char *expression);
int		parse_token(std::string token);
bool	isoperator(char c);
void	compute_expression(std::stack<int> & s, std::string & token);

#endif
