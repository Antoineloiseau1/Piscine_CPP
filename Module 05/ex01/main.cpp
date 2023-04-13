#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {

	std::cout << "*** Blank Form ***" << std::endl;
	Form	blank;
	std::cout << blank << std::endl << std::endl;

	std::cout << "*** Normal Form ***" << std::endl;
	Form	important("important", 52, 52);
	std::cout << important << std::endl << std::endl;

	Bureaucrat	john("John", 53);
	std::cout << john << std::endl << std::endl;

	std::cout << "*** Grade Too Low Test ***" << std::endl;
	try
	{
		john.signForm(important);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << important << std::endl << std::endl;

	std::cout << "*** Upgrading John ***" << std::endl;
	john.upgrade();
	std::cout << john << std::endl;
	try
	{
		john.signForm(important);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "*** resigning form ***" << std::endl;
	john.signForm(important);
	
	std::cout << std::endl << "*** Downgrading John ***" << std::endl;
	john.downgrade();
	std::cout << john << std::endl;
	try
	{
		john.signForm(important);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}