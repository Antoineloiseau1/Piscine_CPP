#include "Bureaucrat.hpp"
#include <iostream>

/* Default Constructor */
Bureaucrat::Bureaucrat(void) : _name("Average employee"), _grade(150) {}

/* Parametric Constructor */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

/* Copy Constructor */
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src.getName()), _grade(src.getGrade()) {}

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

void	Bureaucrat::signForm(AForm & form) {

	if (!form.isSigned())
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->_name << " couldn't sign " << form.getName() << " because his/her grade is too low\n";
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << form.getName() << " has already been signed\n";
}

void	Bureaucrat::executeForm(const AForm & form) const {
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << std::endl;
		std::cerr << e.what() << '\n';
	}
}

/* what functions of exception Classes */
const char *	Bureaucrat::GradeTooHighException::what(void) const throw() { return "Bureaucrat::GradeTooHighException: Grade can't exceed 1"; }
const char *	Bureaucrat::GradeTooLowException::what(void) const throw() { return "Bureaucrat::GradeTooLowException: Grade can't be lower than 150"; }

/* Default Desctructor */
Bureaucrat::~Bureaucrat(void) {}

/* Insertion Operator Overload */
std::ostream&	operator<<(std::ostream& out, Bureaucrat const& instance) {
	out << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return out;
}