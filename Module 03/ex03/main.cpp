#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{

	DiamondTrap stacy("Stacy");
	DiamondTrap	hillary;

	std::cout << std::endl;
	for(int i = 0; i < 6; i++)
	{	
		std::cout << "{" << hillary.getName() << "}: HP{" << hillary.getHitPoints() << "}" << std::endl;
		stacy.attack(hillary.getName());
		hillary.takeDamage(stacy.getAttackDamage());
		std::cout << "{" << hillary.getName() << "}: HP{" << hillary.getHitPoints() << "}" << std::endl;
		hillary.beRepaired(10);
		std::cout << "{" << hillary.getName() << "}: HP{" << hillary.getHitPoints() << "} EP{" << hillary.getEnergyPoints() << "}" << std::endl;
		std::cout << std::endl;
	}
	stacy.highFiveGuys();
	hillary.guardGate();
	stacy.whoAmI();
	return (0);
}