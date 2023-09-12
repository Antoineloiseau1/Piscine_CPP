#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src), _target(src.getTarget()) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs) { 
	(void)rhs;
	return *this; 
}

std::string const	RobotomyRequestForm::getTarget(void) const { return this->_target; }

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	this->checkPrerequisites(executor);
	std::srand(std::time(0));
	int	randomNum = std::rand() % 2;
	if (randomNum == 1) {
		std::cout << "Whirrrrrr... Whirrrrrr... Whirrrrrr... " << this->_target << " has been robotomised" << std::endl;
	}
	else
		std::cout << "Shoot... robotomy operation has failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}