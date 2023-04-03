#include "FragTrap.hpp"
#include <iostream>


/* Default Constructor */
FragTrap::FragTrap(void) : ClapTrap("FragTrap") {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = this->_hitPoints;
	std::cout << "FragTrap " << this->_name << " has been ";
	std::cout << "created out of a wonderful ClapTrap body" << std::endl;
}

/* Parametric Constructor */
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = this->_hitPoints;
	std::cout << "FragTrap " << this->_name << " has been ";
	std::cout << "created out of a wonderful ClapTrap body" << std::endl;
}

/* Copy Constructor */
FragTrap::FragTrap(const FragTrap& src) {
	*this = src;
	std::cout << "FragTrap " << this->_name << " is a vulgar copy of " << src.getName() << std::endl;
}

/* Assignment Operator Overload */
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		this->_maxHitPoints = rhs.getMaxHitPoints();
		std::cout << "FragTrap " << this->_name << " has been assigned from " << &rhs << std::endl;
	}
	return *this;
}

/* Default Destructor */
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " has been, ";
	std::cout << "like any other kind of ClapTraps, sent to the scrapyard" << std::endl;
}

/* Ask for a high five */
void	FragTrap::highFiveGuys(void) {
	std::cout << "FragTrap " << this->_name << ": ✋ Come on guys don't keep me waiting ! ✋" << std::endl;
}
