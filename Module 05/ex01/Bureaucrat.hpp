#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include "Form.hpp"
# include <string>

class Bureaucrat {

	private:

		std::string const	_name;
		unsigned int		_grade;
		const unsigned int	_minGrade = 150;
		const unsigned int	_maxGrade = 1;
	
	public:

		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				upgrade(void);
		void				downgrade(void);

		void	signForm(const Form & form);
	
		class	GradeTooHighException: public std::exception {
			public:
				const char * what(void) const noexcept override;
		};
		class GradeTooLowException: public std::exception {
			public:
				const char * what(void) const noexcept override;
		};



};

std::ostream &	operator<<(std::ostream& out, const Bureaucrat & instance);

#endif