#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {

	AMateria	*a = new Ice;
	AMateria	*b = new Cure;

	AMateria *c = a->clone();
	AMateria *d = b->clone();
	Character	bob;
	// std::cout << a->getType() << ": ";
	// std::cout << a->use() << std::endl;
	// std::cout << b->getType() << ": ";
	// std::cout << b->use() << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}