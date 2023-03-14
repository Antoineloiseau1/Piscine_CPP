#ifndef HARL_H
# define HARL_H

#include <string>

class	Harl
{
	private:
	
		void _debug(void) const;
		void _info(void) const;
		void _warning(void) const;
		void _error(void) const;

	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);
};

#endif