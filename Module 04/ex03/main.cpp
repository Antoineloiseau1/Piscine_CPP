#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "Materia of type \"" << tmp->getType() << "\" has address: " << tmp << std::endl;
	tmp = src->createMateria("cure"); //Does not exists yet
	me->equip(tmp);
	me->use(1, *me);
	src->learnMateria(new Cure());
	tmp = src->createMateria("cure"); 
	std::cout << "Materia of type \"" << tmp->getType() << "\" has address: " << tmp << std::endl;
	me->equip(tmp);
	for (int i = 0; i < 3; i++)
	{
		if (i / 2 < 5)
			tmp = src->createMateria("ice");
		else
			tmp = src->createMateria("cure");
		std::cout << "Materia of type \"" << tmp->getType() << "\" has address: " << tmp << std::endl;
		me->equip(tmp);
	}

	ICharacter* bob = new Character("bob");

	for (int i = 0; i < 10; i++)
	{
		me->use(i, *bob);
		me->unequip(i);
		me->use(i, *bob);
	}


	delete bob;
	delete me;
	delete src;
	return 0;
}