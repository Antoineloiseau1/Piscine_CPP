#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie	*horde = zombieHorde(N, "lucie");
	for (int i; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}