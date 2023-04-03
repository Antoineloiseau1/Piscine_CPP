#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap	richard("Richard");
	FragTrap	brandon("Brandon");
	std::cout << std::endl;
	for(int i = 0; i < 6; i++)
	{	
		std::cout << "{" << brandon.getName() << "}: HP{" << brandon.getHitPoints() << "}" << std::endl;
		richard.attack(brandon.getName());
		brandon.takeDamage(richard.getAttackDamage());
		std::cout << "{" << brandon.getName() << "}: HP{" << brandon.getHitPoints() << "}" << std::endl;
		brandon.beRepaired(10);
		std::cout << "{" << brandon.getName() << "}: HP{" << brandon.getHitPoints() << "} EP{" << brandon.getEnergyPoints() << "}" << std::endl;
		std::cout << std::endl;
	}
	richard.highFiveGuys();

	return (0);
}