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
		Form(const std::string & name, unsigned int signGrade, unsigned int execGrade);
		Form(const Form & src);
		Form&	operator=(const Form & rhs);
		~Form(void);

		const std::string	getName(void) const;
		bool				isSigned(void) const;
		const unsigned int	getSignGrade(void) const;
		const unsigned int	getExecGrade(void) const;

		void	beSigned(const Bureaucrat & worker);

		class GradeTooHighException: public std::exception {
			public:
				const char *	what(void) const noexcept override;
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *	what(void) const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& out, Form const& instance);

#endif