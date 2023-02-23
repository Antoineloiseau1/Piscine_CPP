#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack(void) const
{
	//std::cout << this->_name << ": attacks with their " << this->_weapon.getType() << std::endl;
}

void	HumanB::setWeapon(std::string type)
{
	this->_weapon = new Weapon(type);
}