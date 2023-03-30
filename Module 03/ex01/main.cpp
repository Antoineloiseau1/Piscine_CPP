#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	fernando("Fernando");
	ScavTrap	gonzales("Gonzales");
	std::cout << std::endl;
	for(int i = 0; i < 11; i++)
	{	
		std::cout << "{" << gonzales.getName() << "}: HP{" << gonzales.getHitPoints() << "}" << std::endl;
		fernando.attack(gonzales.getName());
		gonzales.takeDamage(fernando.getAttackDamage());
		std::cout << "{" << gonzales.getName() << "}: HP{" << gonzales.getHitPoints() << "}" << std::endl;
		gonzales.beRepaired(10);
		std::cout << "{" << gonzales.getName() << "}: HP{" << gonzales.getHitPoints() << "} EP{" << gonzales.getEnergyPoints() << "}" << std::endl;
		std::cout << std::endl;
	}
	fernando.guardGate();

	return (0);
}