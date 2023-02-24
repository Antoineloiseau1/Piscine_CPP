#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponRef) : _name(name), _weapon(weaponRef)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << ": attacks with their " << this->_weapon.getType() << std::endl;
}