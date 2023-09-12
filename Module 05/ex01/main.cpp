#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {

	std::cout << "*** Blank Form ***" << std::endl;
	Form	blank;
	std::cout << blank << std::endl << std::endl;

	std::cout << "*** Form too low ***" << std::endl;
	try
	{
		Form	tooLow("tooLow", 151, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n*** Form too High ***" << std::endl;
	try
	{
		Form	tooHigh("tooHigh", 52, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n*** Normal Form ***" << std::endl;
	Form	important("important", 52, 52);
	std::cout << important << std::endl << std::endl;

	Bureaucrat	john("John", 53);
	std::cout << john << std::endl << std::endl;

	std::cout << "*** Grade Too Low Test ***" << std::endl;
	john.signForm(important);
	std::cout << important << std::endl << std::endl;

	std::cout << "*** Upgrading John ***" << std::endl;
	john.upgrade();
	std::cout << john << std::endl;
	std::cout << ">>> TRYING TO SIGN FORM <<<\n";
	john.signForm(important);
	std::cout << important << std::endl;
	
	std::cout << std::endl << "*** resigning form ***" << std::endl;
	john.signForm(important);
	
	std::cout << std::endl << "*** Downgrading John ***" << std::endl;
	john.downgrade();
	std::cout << john << std::endl;
	john.signForm(blank);

	return (0);
}