#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"
# include <fstream>

class ShrubberryCreationForm: public AForm {
	private:

		const std::string _target;

	public:

		ShrubberryCreationForm(std::string target);
		ShrubberryCreationForm(const ShrubberryCreationForm & src);
		ShrubberryCreationForm & operator=(const ShrubberryCreationForm & rhs);
		~ShrubberryCreationForm(void);

		std::string const	getTarget(void) const;
		void				execute(Bureaucrat const & executor) const;
};

#endif