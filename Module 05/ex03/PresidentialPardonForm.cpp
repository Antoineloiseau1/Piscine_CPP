#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 2), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src), _target(src.getTarget()) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs) { 
	(void)rhs;
	return *this; 
}

std::string const	PresidentialPardonForm::getTarget(void) const { return this->_target; }

void	PresidentialPardonForm::execute(const Bureaucrat & executor) const {
	this->checkPrerequisites(executor);
	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}