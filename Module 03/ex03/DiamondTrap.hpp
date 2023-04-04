#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap {

	private:

		std::string	_name;

	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap& operator=(const DiamondTrap &rhs);
		~DiamondTrap(void);

		void	attack(const std::string& target);
		void	whoAmI(void);

};

#endif