#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include "AForm.hpp"
# include <string>

class AForm;

class Bureaucrat {

	private:

		std::string const	_name;
		unsigned int		_grade;
	
	public:

		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				upgrade(void) throw(GradeTooHighException);
		void				downgrade(void) throw(GradeTooLowException);
	
		void	signForm(AForm & form);
		void	executeForm(const AForm & form) const;

		class	GradeTooHighException: public std::exception {
			public:
				const char * what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char * what(void) const throw();
		};

};

std::ostream &	operator<<(std::ostream& out, const Bureaucrat & instance);

#endif