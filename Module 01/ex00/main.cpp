#include "Zombie.hpp"

int main(void)
{
	Zombie	*newDead = newZombie("lucie");
	newDead->announce();
	randomChump("bob");
	delete newDead;
	return (0);
}