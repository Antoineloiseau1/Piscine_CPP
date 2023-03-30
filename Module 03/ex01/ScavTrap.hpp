#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

	public:

		/* Canonical class form */
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap&	operator=(ScavTrap const &rhs);
		~ScavTrap(void);

		/* Member functions */
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif