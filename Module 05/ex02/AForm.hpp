#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:

		const std::string	_name;
		bool				_isSigned;
		const unsigned int 	_signGrade;
		const unsigned int	_execGrade;

	public:

		AForm(void);
		AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);
		AForm(const AForm & src);
		AForm&	operator=(const AForm & rhs);
		virtual ~AForm(void);

		const std::string	getName(void) const;
		bool				isSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

		void				beSigned(Bureaucrat & worker);
		void				checkPrerequisites(const Bureaucrat & executor) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
		

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