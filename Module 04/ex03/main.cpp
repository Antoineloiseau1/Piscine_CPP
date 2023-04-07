#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	/* Learning Materias */
	IMateriaSource* src = new MateriaSource();
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0 )
			src->learnMateria(new Ice);
		else
			src->learnMateria(new Cure);

	}
	ICharacter* me = new Character("me");

	/* Create and Equip */
	AMateria* tmp;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			tmp = src->createMateria("ice");
		else
			tmp = src->createMateria("cure");
		std::cout << "Materia of type \"" << tmp->getType() << "\" with address: " << tmp << " equiped" << std::endl;
		me->equip(tmp);
	}

	ICharacter* bob = new Character("bob");

	/* Use or unequip */
	for (int i = 0; i < 6; i++)
	{
		me->unequip(i);
		me->use(i, *bob);
	}

	delete bob;
	delete me;
	delete src;
	return 0;
}