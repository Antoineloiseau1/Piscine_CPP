#include "ClapTrap.hpp"
#include <iostream>


/* Default Constructor */
ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10) , _attackDamage(0) {
	this->_maxHitPoints = this->_hitPoints;
	std::cout << "ClapTrap " << this->_name << " has been created by god himslef" << std::endl;
}


/* Parametric Constructor */
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	this->_maxHitPoints = this->_hitPoints;
	std::cout << "ClapTrap " << this->_name << " has been created by god himself" << std::endl;
}


/* Copy Constructor */
ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout << "ClapTrap " << this->_name << " is a vulgar copy of " << src.getName() << std::endl;
}


/* Assignation Operator Overlaod */
ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		this->_maxHitPoints = rhs.getMaxHitPoints();
		std::cout << "ScavTrap " << this->_name << " has been assigned from " << &rhs << std::endl;
	}
	return *this;
}


const std::string&	ClapTrap::getName(void) const{
	return this->_name;
}

int ClapTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
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
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " needs to be repaired to attack" << std::endl;
		return ;
	}
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
		if (this->_hitPoints - (int)amount < 0)
		{
			amount = (this->_hitPoints);
			this->_hitPoints = 0;
		}
		else
			this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << ((amount <= 1)? " point" : " points") << " of damage !" << std::endl;
		if (this->_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is out of hit points, please repair." << std::endl;
	}
	else
		std::cout << "Claptrap " << this->_name << " needs to be repaired,  don't be cruel !" << std::endl;
}


void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0)
	{
		if ((this->_hitPoints + amount ) > this->_maxHitPoints)
			amount = this->_maxHitPoints - this->_hitPoints;
		std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount;
		std::cout << " hit" << ((amount <= 1)? " point" : " points") << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy for being repaired" << std::endl;
}
