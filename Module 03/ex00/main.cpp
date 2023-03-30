#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap boby("Boby");
	ClapTrap daisy("Daisy");
	std::cout << std::endl;
	for(int i = 0; i < 11; i++)
	{	
		std::cout << "{boby}: HP{" << boby.getHitPoints() << "}" << std::endl;
		daisy.attack(boby.getName());
		boby.takeDamage(daisy.getAttackDamage());
		std::cout << "{boby}: HP{" << boby.getHitPoints() << "}" << std::endl;
		boby.beRepaired(1);
		std::cout << "{boby}: HP{" << boby.getHitPoints() << "} EP{" << boby.getEnergyPoints() << "}" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}