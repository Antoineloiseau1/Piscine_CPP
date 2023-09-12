#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {

	Bureaucrat	average;
	std::cout << average << std::endl << std::endl;

	/* TOO HIGH */
	std::cout << "/* TRYING TO INSTANCIATE GRADE 0 */\n";
	try
	{
		Bureaucrat gerard("Gerard", 0);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;;
	}

	/* TOO LOW */
	std::cout << "/* TRYING TO INSTANCIATE GRADE 151 */\n";
	try
	{
		Bureaucrat gerard("Gerard", 151);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	/* TRY TO UPGRADE*/
	std::cout << "/* TRY TO UPGRADE */\n";
	try
	{
		Bureaucrat francis("Francis", 1);
		std::cout << francis << "\n>>> UPGRADING <<<\n";
		francis.upgrade();
		std::cout << francis << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	/* TRY TO DOWNGRADE*/
	try
	{
		std::cout << "/* TRY TO DOWNGRADE */" << std::endl;
		Bureaucrat francis("Francis", 150);
		std::cout << francis << "\n>>> DOWNGRADING <<<\n";
		francis.downgrade();
		std::cout << francis << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	Bureaucrat	antoine("Antoine", 42);
	Bureaucrat	copy(antoine);
	Bureaucrat	equal;
	equal = antoine;
	std::cout << antoine << std::endl;
	std::cout << copy << std::endl;
	std::cout << equal << std::endl;
	try
	{
		std::cout << "\n>>> DOWNGRADING ANTOINE <<<\n";
		antoine.downgrade();
		std::cout << antoine << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n>>> UPGRADING ANTOINE <<<\n";
		antoine.upgrade();
		std::cout << antoine << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}