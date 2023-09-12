#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main(void) {

	Intern	antoine;
	Bureaucrat	michou("Michou", 2);
	std::cout << michou << std::endl << std::endl;
	std::string	types[] = {"presidential pardon", "robotomy request", "shrubberry creation", "toto"};
	for(int i = 0; i < 4; i++)
	{
		try
		{
			AForm*	test = antoine.makeForm(types[i], "bender");
			std::cout << *test << std::endl; 
			michou.signForm(*test);
			michou.executeForm(*test);
			std::cout << std::endl;
			delete test;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}