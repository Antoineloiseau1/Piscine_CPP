#include "Bureaucrat.hpp"
#include <iostream>

/* Parametric Constructor */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

/* Default Constructor */
Bureaucrat::Bureaucrat(void) : _name("Random Guy"), _grade(150) {}

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
	if (this->_grade - 1 < 1)
		throw	Bureaucrat::GradeTooHighException();
	this->_grade--;
}

/* Downgrade Bureaucrat */
void	Bureaucrat::downgrade(void) {
	if (this->_grade + 1 > 150)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade++;
}

/* what function of GradeTooHighExecpetion Class */
const char *	Bureaucrat::GradeTooHighException::what(void) const throw(){ 
	return "Error: Grade is to high";
}

/* what function of GradeTooLowExecpetion Class */
const char *	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Error: Grade is to low";
}

void	Bureaucrat::signForm(AForm & form) {
	if (!form.isSigned())
	{
		if (this->_grade <= form.getSignGrade())
		{
			form.beSigned(*this);
			std::cout << this->_name << " signed \"" << form.getName() << "\" form" << std::endl;
		}
		else
		{
			std::cout << this->_name << " couldn't sign \"" << form.getName() << "\" form because his grade is too low" << std::endl;
			form.beSigned(*this);
		}
	}
	else
	{
		form.beSigned(*this);
		std::cout << "\"" << form.getName() << "\"" << " has already been signed" << std::endl;
	}

}

void	Bureaucrat::executeForm(const AForm & form) const {
	form.execute(*this);
	std::cout << this->_name << " executed \"" << form.getName() << "\" form" << std::endl;
}

/* Default Desctructor */
Bureaucrat::~Bureaucrat(void) {}

/* Insertion Operator Overload */
std::ostream&	operator<<(std::ostream& out, Bureaucrat const& instance) {
	out << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return out;
}