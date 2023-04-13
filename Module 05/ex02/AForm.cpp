#include "AForm.hpp"
#include <iostream>


/* Default Constructor */
AForm::AForm(void) : _name("Blank"), _signed(false), _signGrade(150),_execGrade(150) {} 

AForm::AForm(const std::string & name, unsigned int signGrade, unsigned int execGrade) throw(GradeTooHighException, GradeTooLowException) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooHighException();
}

/* Parametric Constructor */
AForm::AForm(const AForm & src) : _name(src.getName()), _signed(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

/* Assignment Operator Overload */
AForm&	AForm::operator=(const AForm & rhs) {
	if (this != &rhs)
		this->_signed = rhs.isSigned();
	return *this;
}


/* Accessors */
const std::string AForm::getName(void) const { return this->_name; }
bool	AForm::isSigned(void) const { return this->_signed; }
unsigned int	AForm::getSignGrade(void) const { return this->_signGrade; }
unsigned int	AForm::getExecGrade(void) const { return this->_execGrade; }


/* Check if worker has the right to sign form and sign it */
void	AForm::beSigned(const Bureaucrat & worker) throw(GradeTooLowException) {
	if (worker.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw (AForm::GradeTooLowException());
}

/* Checks if executor has the right to execute form and if form has been signed */
void	AForm::checkPrerequisites(const Bureaucrat & executor) const throw(GradeTooLowException, FormNotSignedException) {
	if (this->_signed) {
		if (executor.getGrade() > this->_execGrade)
			throw(GradeTooLowException());
	}
	else
		throw(FormNotSignedException());
}

/* Virtual Function that will execute form */
void	AForm::execute(const Bureaucrat & executor) const { (void)executor ;}

/* Error Exceptions */
const char *	AForm::GradeTooHighException::what(void) const throw() { return "Error: Grade too high"; }
const char *	AForm::GradeTooLowException::what(void) const throw() { return "Error: Grade too low"; }
const char *	AForm::FormNotSignedException::what(void) const throw() { return "Error: form needs to be signed to be executed"; }

/* Default destructor */
AForm::~AForm(void) {}


/* Non-Member function */
std::ostream&	operator<<(std::ostream& out, AForm const & instance) {
	out << "\""<< instance.getName() << "\" Form has grade " << instance.getSignGrade();
	out << " to be signed and grade " << instance.getExecGrade() << " to be executed." << std::endl;
	out << "This Form has " << ((instance.isSigned()) ? "been signed." : "not been signed yet.");
	return out;
}


