#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>

class ClapTrap {

	protected:

		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		int			_maxHitPoints;

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		ClapTrap&	operator=(ClapTrap const &rhs);
		~ClapTrap(void);

		const std::string&	getName(void) const;
		int					getHitPoints(void) const;
		int					getEnergyPoints(void) const;
		int					getAttackDamage(void) const;
		int					getMaxHitPoints(void) const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif