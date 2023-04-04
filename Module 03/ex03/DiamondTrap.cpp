#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("ClapTrap_clap_name"), ScavTrap(), FragTrap() {
	this->_name = "DiamondTrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_maxHitPoints = this->_hitPoints;
	std::cout << "DiamondTrap " << this->_name;
	std::cout << " monstruosity is the result of the union between a ScavTrap and a FragTrap"; 
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_maxHitPoints = this->_hitPoints;
	std::cout << "DiamondTrap " << this->_name;
	std::cout << " monstruosity is the result of the union between a ScavTrap and a FragTrap"; 
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) {
	*this = src;
	std::cout << "How dared you making a copy of this monstruosity called ";
	std::cout << this->_name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		this->_maxHitPoints = rhs.getMaxHitPoints();
	}
		std::cout << "DiamondTrap " << this->_name << " has been assigned from " << &rhs << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name;
	std::cout << " was just a bad dream" << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) {
    std::cout << "I am a DiamondTrap named " << _name << ". My grand dad is "
        << ClapTrap::_name << std::endl;
}