#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << this->getName() << " has been ";
	std::cout << "created out of a wonderful ClapTrap body" << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap") {
	std::cout << "ScavTrap " << this->getName() << " has been ";
	std::cout << "created out of a wonderful ClapTrap body" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	*this = src;
	std::cout << "ScavTrap " << this->_name << " is a vulgar copy of " << src.getName() << std::endl;	
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->getName() << " has been, ";
	std::cout << "like any other kind of ClapTraps, sent to the scrapyard" << std::endl;
}