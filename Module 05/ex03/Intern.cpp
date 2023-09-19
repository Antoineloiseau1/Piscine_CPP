#include "Intern.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/* Canonical class constructors */
Intern::Intern(void) {}
Intern::Intern(const Intern& src) { (void)src; }
Intern&	Intern::operator=(const Intern& rhs) { (void)rhs; return *this; }
Intern::~Intern(void) {}


/* Error Exception */
const char*	Intern::FormTypeNotFoundException::what(void) const throw() {
	return "Intern::FormTypeNotFoundException: Type of Form not found";
}


/* Form Creation Private functions */
AForm*	Intern::_createPresidentialPardonForm(std::string target) { return new PresidentialPardonForm(target); }
AForm*	Intern::_createRobotomyRequestForm(std::string target) { return new RobotomyRequestForm(target); }
AForm*	Intern::_createShrubberryCreationForm(std::string target) { return new ShrubberryCreationForm(target); }


AForm*	Intern::makeForm(std::string type, std::string target) {
	
	/* Struct that contains all type of forms with their function pointers creators */
	struct
	{
		std::string	name;
		AForm*	(Intern::*funcPtr)(std::string);
	} formTypes[] = {
		{"robotomy request", &Intern::_createRobotomyRequestForm},
		{"shrubberry creation", &Intern::_createShrubberryCreationForm},
		{"presidential pardon", &Intern::_createPresidentialPardonForm}};
	
	for(int i = 0; i < 3; i++)
	{
		if (formTypes[i].name == type)
		{
			AForm* form = (this->*formTypes[i].funcPtr)(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return  form;
		}
	}
	throw (FormTypeNotFoundException());
	return NULL;
}