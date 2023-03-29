#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	fernando("Fernando");
	ScavTrap	anotherSpanishGuy(fernando);
	std::cout << "name is " << fernando.getName() << std::endl;
	std::cout << "name is " << anotherSpanishGuy.getName() << std::endl;

	return (0);
}