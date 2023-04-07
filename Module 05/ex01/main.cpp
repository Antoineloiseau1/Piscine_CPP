#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {

	Form	blank;
	Form	important("important", 1, 1);

	std::cout << blank << std::endl;
	std::cout << important << std::endl;
	return (0);
}