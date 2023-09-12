#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <string>

class Bureaucrat {

	private:

		const std::string	_name;
		unsigned int		_grade;
	
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