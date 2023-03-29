#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(100), _energyPoints(50) , _attackDamage(20) {
	std::cout << "ClapTrap " << this->_name << " has been created by god himslef" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "ClapTrap " << this->_name << " has been created by god himself" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout << "ClapTrap " << this->_name << " is a vulgar copy of " << src.getName() << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "ClapTrap " << rhs.getName() << " has been created by assignation" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

const std::string&	ClapTrap::getName(void) const{
	return this->_name;
}

int	ClapTrap::getHitPoints(void) const{
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const{
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage(void) const{
	return this->_attackDamage;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " has been sent to the scrapyard" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << ((this->_attackDamage <= 1)? " point" : " points") << " of damage !" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << ((amount <= 1)? " point" : " points") << " of damage !" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is out of hit points, please repair" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount;
		std::cout << ((amount <= 1)? " point" : " points") << " of hit points !" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy for being repaired" << std::endl;
}
