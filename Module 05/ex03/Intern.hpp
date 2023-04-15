#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {

	private:

		AForm*	_createRobotomyRequestForm(std::string target);
		AForm*	_createShrubberryCreationForm(std::string target);
		AForm*	_createPresidentialPardonForm(std::string target);

	public:

		Intern(void);
		Intern(const Intern & src);
		Intern&	operator=(const Intern & rhs);
		~Intern(void);

		class FormTypeNotFoundException: public std::exception {
			public:
				const char*	what() const throw();
		};

		AForm*	makeForm(std::string form, std::string target);
};

#endif