#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

		const std::string	_name;
		bool				_signed;
		const unsigned int 	_signGrade;
		const unsigned int	_execGrade;

	public:

		Form(void);
		Form(const std::string & name, unsigned int signGrade, unsigned int execGrade) throw(GradeTooHighException, GradeTooLowException);
		Form(const Form & src);
		Form&	operator=(const Form & rhs);
		~Form(void);

		const std::string	getName(void) const;
		bool				isSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

		void				beSigned(const Bureaucrat & worker) throw(GradeTooLowException);

		class GradeTooHighException: public std::exception {
			public:
				const char *	what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, Form const& instance);

#endif