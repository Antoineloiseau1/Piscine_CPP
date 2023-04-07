#include "Bureaucrat.hpp"
#include <iostream>

/* Parametric Constructor */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (grade < _maxGrade)
		throw	Bureaucrat::GradeTooHighException();
	if (grade > _minGrade)
		throw	Bureaucrat::GradeTooLowException();
}

/* Default Constructor */
Bureaucrat::Bureaucrat(void) : Bureaucrat("Random Guy", 150) {}

/* Copy Constructor */
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src.getName() + "_copy"), _grade(src.getGrade()) {}

/* Assignement Operator */
Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & rhs) {
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}


/* Returns Bureaucrat's name */
std::string const	Bureaucrat::getName(void) const {
	return this->_name;
}

/* Returns Bureaucrat's grade */
unsigned int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

/* Upgrades Bureaucrat */
void	Bureaucrat::upgrade(void) {
	if (this->_grade - 1 < _maxGrade)
		throw	Bureaucrat::GradeTooHighException();
	this->_grade--;
}

/* Downgrade Bureaucrat */
void	Bureaucrat::downgrade(void) {
	if (this->_grade + 1 > _minGrade)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade++;
}

/* what function of GradeTooHighExecpetion Class */
const char *	Bureaucrat::GradeTooHighException::what(void) const noexcept{ 
	return "Error: Grade is to high";
}

/* what function of GradeTooLowExecpetion Class */
const char *	Bureaucrat::GradeTooLowException::what(void) const noexcept {
	return "Error: Grade is to low";
}

/* Default Desctructor */
Bureaucrat::~Bureaucrat(void) {}

/* Insertion Operator Overload */
std::ostream&	operator<<(std::ostream& out, Bureaucrat const& instance) {
	out << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return out;
}