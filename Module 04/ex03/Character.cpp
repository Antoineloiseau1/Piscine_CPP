#include "Character.hpp"
#include <iostream>
#include <Cure.hpp>
#include <Ice.hpp>

/* Default Constructor */
Character::Character(void) : Character("Unknown Adventurer") {
	return ;
}

/* Parametric Constructor */
Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << this->getName() << " entered the world" << std::endl; 
}

/* Copy Constructor */
Character::Character(const Character & src) : Character(src) {
	for (int i = 0; i < 4; i++) {
			this->_materia[i] = src.getMateria(i)->clone();
		}
}

/* Assignement Operator */
Character &	Character::operator=(const Character & rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++) {
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			this->_materia[i] = rhs.getMateria(i)->clone();
		}
	}
	return *this;
}

/* Returns _materia[idx] */
AMateria*	Character::getMateria(int idx) const {
	return this->_materia[idx];
}

/* Returns Character's name */
std::string const & Character::getName(void) const {
	return this->_name;
}

/* Save Materia m in the first available slot in _materia[] */
void	Character::equip(AMateria* m) {
	int	i = 0;
	while (i < 4) {
		if (this->_materia[i] == NULL)
			this->_materia[i] = m;
	}
}

/* Discard Materia[idx] */
void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	this->_materia[idx] = NULL;
}

/* Use Materia[idx] on target */
void	Character::use(int idx, ICharacter & target) {
	if (idx < 0 || idx > 3)
		return ;
	if (this->_materia[idx] != NULL)
	{
		this->_materia[idx]->use(target);
		delete this->_materia[idx];
		this->_materia[idx] = NULL;
	}
}

/* Default Destructor */
Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		delete this->_materia[i];
	}
}