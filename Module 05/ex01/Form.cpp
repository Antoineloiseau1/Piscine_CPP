#include "Form.hpp"
#include <iostream>

/* Default Constructor */
Form::Form(void) : _name("Blank"), _isSigned(false), _signGrade(150),_execGrade(150) {} 

/* Parametric Constructor */
Form::Form(const std::string name, unsigned int signGrade, unsigned int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

/* Copy Constructor */
Form::Form(const Form & src) : _name(src.getName()), _isSigned(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

/* Assignment Operator Constructor */
Form&	Form::operator=(const Form & rhs) {
	if (this != &rhs)
		this->_isSigned = rhs.isSigned();
	return *this;
}

/* Getters */
unsigned int		Form::getSignGrade(void) const { return this->_signGrade; }
unsigned int		Form::getExecGrade(void) const { return this->_execGrade; }
const std::string	Form::getName(void) const { return this->_name; }
bool				Form::isSigned(void) const { return this->_isSigned; }


void	Form::beSigned(Bureaucrat & bureaucrat) {

	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

/* what functions of exception classes */
const char *	Form::GradeTooHighException::what(void) const throw() { return "Form::GradeTooHighException: Grade can't exceed 1";}
const char *	Form::GradeTooLowException::what(void) const throw() { return "Form::GradeTooLowException: Grade too low";}

Form::~Form(void) {}

std::ostream&	operator<<(std::ostream& out, Form const & instance) {
	out <<  instance.getName() << " has grade " << instance.getSignGrade();
	out << " to be signed and grade " << instance.getExecGrade() << " to be executed, ";
	out << "this form has " << ((instance.isSigned()) ? "been signed" : "not been signed yet");
	return out;
}


