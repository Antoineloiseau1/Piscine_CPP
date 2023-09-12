#include "Bureaucrat.hpp"
#include <iostream>

/* Parametric Constructor */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

/* Default Constructor */
Bureaucrat::Bureaucrat(void) : _name("Random_Bureaucrat"), _grade(150) {}

/* Copy Constructor */
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src.getName() + "_copy"), _grade(src.getGrade()) {}

/* Assignement Operator */
Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & rhs) {
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}


/* Getters */
std::string const	Bureaucrat::getName(void) const { return this->_name; }
unsigned int	Bureaucrat::getGrade(void) const { return this->_grade; }


/* Upgrades Bureaucrat */
void	Bureaucrat::upgrade(void) {
	if (this->_grade - 1 < 1)
		throw	Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

/* Downgrade Bureaucrat */
void	Bureaucrat::downgrade(void) {
	if (this->_grade + 1 > 150)
		throw	Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

/* what function of GradeTooHighExecpetion Class */
const char *	Bureaucrat::GradeTooHighException::what(void) const throw() { 
	return "GradeTooHighException: Grade must not exceed 1";
}

/* what function of GradeTooLowExecpetion Class */
const char *	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "GradeTooLowException: Grade must not be lower than 150";
}

/* Default Desctructor */
Bureaucrat::~Bureaucrat(void) {}

/* Insertion Operator Overload */
std::ostream&	operator<<(std::ostream& out, Bureaucrat const& instance) {
	out << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return out;
}