#include "ScavTrap.hpp"
#include <iostream>


/* Deefault Constructor */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << this->getName() << " has been ";
	std::cout << "created out of a wonderful ClapTrap body" << std::endl;
}


/* Parametric Constructor */
ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap") {
	std::cout << "ScavTrap " << this->getName() << " has been ";
	std::cout << "created out of a wonderful ClapTrap body" << std::endl;
}


/* Copy Constructor */
ScavTrap::ScavTrap(ScavTrap const &src) {
	*this = src;
	std::cout << "ScavTrap " << this->_name << " is a vulgar copy of " << src.getName() << std::endl;	
}


/* Assignation Operator Overload */
ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		std::cout << "ScavTrap " << this->_name << " has been assigned from " << &rhs << std::endl;
	}
	return *this;
}


/* Default Destructor */
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->getName() << " has been, ";
	std::cout << "like any other kind of ClapTraps, sent to the scrapyard" << std::endl;
}


/* Attack one foe and deal _attackDamage damage(s). This uses one ernergy point */
void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " needs to be repaired to attack" << std::endl;
		return ;
	}
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << ((this->_attackDamage <= 1)? " point" : " points") << " of damage !" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is out of energy to attack" << std::endl;
}


/* Enter Gate Keeper Mode */
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " entered Gate keeper mode !" << std::endl;
}
