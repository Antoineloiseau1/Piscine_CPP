#include "Character.hpp"
#include <iostream>


Character::Character(void) : Character("Unknown Adventurer") {
	// std::cout << this->getName() << " entered the world" << std::endl; 
}

Character::Character(std::string name) : _name(name) {
	std::cout << this->getName() << " entered the world" << std::endl; 
}

Character::~Character(void) {
	std::cout << this->getName() << " left this world" << std::endl;
}

std::string const & Character::getName(void) const {
	return this->_name;
}

void	Character::use(int idx, ICharacter & target) {
	this->tab[idx]->use(target);
	delete this->tab[idx];
}