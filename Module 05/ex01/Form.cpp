#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("Blank"), _signed(false), _signGrade(150),_execGrade(150) {} 

Form::Form(const std::string & name, unsigned int signGrade, unsigned int execGrade) : _name(name), _signGrade(signGrade), _signed(false), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooHighException();
}

Form::Form(const Form & src) : _name(src.getName()), _signed(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

Form&	Form::operator=(const Form & rhs) {
	if (this != &rhs)
		this->_signed = rhs.isSigned();
	return *this;
}

const std::string Form::getName(void) const {
	return this->_name;
}

bool	Form::isSigned(void) const {
	return this->_signed;
}

const unsigned int	Form::getSignGrade(void) const {
	return this->_signGrade;
}

const unsigned int	Form::getExecGrade(void) const {
	return this->_execGrade;
}

void	Form::beSigned(const Bureaucrat & worker) {
	if (worker.getGrade() <= this->_signGrade)
	{
		this->_signed = true;
		worker.signForm(this);
	}
	else
		throw GradeTooLowException();
}

const char *	Form::GradeTooHighException::what(void) const noexcept {
	return "Error: Grade too high";
}

const char *	Form::GradeTooLowException::what(void) const noexcept {
	return "Error: Grade too low";
}

Form::~Form(void) {}

std::ostream&	operator<<(std::ostream& out, Form const & instance) {
	out << instance.getName() << " form has grade " << instance.getSignGrade();
	out << " to be signed and grade " << instance.getExecGrade() << " to be executed." << std::endl;
	out << "This form has " << ((instance.isSigned()) ? "been signed." : "not been signed yet.");
	return out;
}


