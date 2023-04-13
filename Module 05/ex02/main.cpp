#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {

	ShrubberryCreationForm test("pine");
	std::cout << test << std::endl << std::endl;
	Bureaucrat	michel("Michel", 138);
	std::cout << michel << std::endl << std::endl;

	std::cout << "*** Form Not Signed Test ***" << std::endl;
	try
	{
		test.execute(michel);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	michel.signForm(test);

	std::cout << std::endl << "*** GradeTooLow to be executed ***" << std::endl;
	try
	{
		michel.executeForm(test);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl << std::endl;
 	}
	michel.upgrade();
	std::cout << michel << std::endl << std::endl;
	std::cout << "*** Executing ShrubberryCreationForm ***" << std::endl;
	michel.executeForm(test);

	RobotomyRequestForm	robotomy("Michel");
	std::cout << std::endl << robotomy << std::endl << std::endl;
	Bureaucrat jacquie("Jacquie", 45);
	std::cout << jacquie << std::endl << std::endl;

	std::cout << "*** Executing RobotomyRequestForm *** " << std::endl;
	jacquie.signForm(robotomy);
	std::cout << std::endl;
	jacquie.executeForm(robotomy);

	PresidentialPardonForm	pardon("merci");
	std::cout << std::endl << pardon << std::endl << std::endl;
	Bureaucrat hank("Hank", 2);
	std::cout << hank << std::endl;
	hank.signForm(pardon);

	std::cout << std::endl;
	std::cout << "*** Executing PresidentialPardonForm ***" << std::endl;
	hank.executeForm(pardon);
	return (0);
}