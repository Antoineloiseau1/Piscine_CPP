#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main(void) {

	Intern	antoine;
	AForm*	test = antoine.makeForm("presidential pardo", "bender");
	std::cout << *test << std::endl << std::endl;
	delete test;
	Bureaucrat	michel("Michel", 138);
	std::cout << michel << std::endl << std::endl;
	return (0);
}