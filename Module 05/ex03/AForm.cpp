#include "AForm.hpp"
#include <iostream>

/* Default Constructor */
AForm::AForm(void) : _name("Blank"), _isSigned(false), _signGrade(150),_execGrade(150) {} 

/* Parametric Constructor */
AForm::AForm(const std::string name, unsigned int signGrade, unsigned int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

/* Copy Constructor */
AForm::AForm(const AForm & src) : _name(src.getName()), _isSigned(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

/* Assignment Operator Constructor */
AForm&	AForm::operator=(const AForm & rhs) {
	if (this != &rhs)
		this->_isSigned = rhs.isSigned();
	return *this;
}

/* Getters */
unsigned int		AForm::getSignGrade(void) const { return this->_signGrade; }
unsigned int		AForm::getExecGrade(void) const { return this->_execGrade; }
const std::string	AForm::getName(void) const { return this->_name; }
bool				AForm::isSigned(void) const { return this->_isSigned; }


void	AForm::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

/* Checks if executor has the right to execute Aform and if Aform has been signed */
void	AForm::checkPrerequisites(const Bureaucrat & executor) const {
	if (this->_isSigned) {
		if (executor.getGrade() > this->_execGrade)
			throw(GradeTooLowException());
	}
	else
		throw(FormNotSignedException());
}

/* Virtual Function that will execute Aform */
void	AForm::execute(Bureaucrat const & executor) const { (void)executor ;}

/* what functions of exception classes */
const char *	AForm::GradeTooHighException::what(void) const throw() { return "AForm::GradeTooHighException: Grade can't exceed 1"; }
const char *	AForm::GradeTooLowException::what(void) const throw() { return "AForm::GradeTooLowException: Grade too low"; }
const char *	AForm::FormNotSignedException::what(void) const throw() { return "AForm::FormNotSignedException: form needs to be signed to be executed"; }

AForm::~AForm(void) {}

std::ostream&	operator<<(std::ostream& out, AForm const & instance) {
	out <<  instance.getName() << " has grade " << instance.getSignGrade();
	out << " to be signed and grade " << instance.getExecGrade() << " to be executed, ";
	out << "this form has " << ((instance.isSigned()) ? "been signed" : "not been signed yet");
	return out;
}


