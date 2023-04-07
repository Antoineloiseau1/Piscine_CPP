#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {

	/* TOO HIGH */
	try
	{
		std::cout << "/* TOO HIGH ON INSTANCE*/" << std::endl;
		Bureaucrat gerard("Gerard", 0);

	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;;
	}

	/* TOO LOW */
	try
	{
		std::cout << "/* TOO LOW ON INSTANCE */" << std::endl;
		Bureaucrat gerard("Gerard", 151);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	/* TRY TO UPGRADE*/
	try
	{
		std::cout << "/* TRY TO UPGRADE */" << std::endl;
		Bureaucrat francis("Francis", 1);
		std::cout << francis << std::endl << ">>> UPGRADING <<<" << std::endl;;
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
		std::cout << francis << std::endl << ">>> DOWNGRADING <<<" << std::endl;
		francis.downgrade();
		std::cout << francis << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << "*do some stuff after catch *" << std::endl;
	return (0);
}