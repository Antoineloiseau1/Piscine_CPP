#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap boby("Boby");
	ClapTrap daisy("Daisy");
	std::cout << std::endl;
	for(int i = 0; i < 11; i++)
	{		
		daisy.attack(boby.getName());
		boby.takeDamage(daisy.getAttackDamage());
		boby.beRepaired(1);
		std::cout << std::endl;
	}

	return (0);
}