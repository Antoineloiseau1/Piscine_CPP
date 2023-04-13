#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:

		const std::string	_name;
		bool				_signed;
		const unsigned int 	_signGrade;
		const unsigned int	_execGrade;

	public:

		AForm(void);
		AForm(const std::string & name, unsigned int signGrade, unsigned int execGrade) throw(GradeTooHighException, GradeTooLowException);
		AForm(const AForm & src);
		AForm&	operator=(const AForm & rhs);
		~AForm(void);

		const std::string	getName(void) const;
		bool				isSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

		void				beSigned(const Bureaucrat & worker) throw(GradeTooLowException);
		void				checkPrerequisites(const Bureaucrat & executor) const throw(GradeTooLowException, FormNotSignedException);
		virtual void		execute(const Bureaucrat & executor) const = 0;
		

		class GradeTooHighException: public std::exception {
			public:
				const char *	what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *	what(void) const throw();
		};
		class FormNotSignedException: public std::exception {
			public:
				const char *	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, AForm const& instance);

#endif