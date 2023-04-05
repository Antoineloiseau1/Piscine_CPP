#include "Cat.hpp"
#include <iostream>


Cat::Cat(void) : Animal("Cat"), _brain(new Brain) {
	std::cout << this->_type << " Default Constructor Called" << std::endl; 
}

Cat::Cat(const Cat &src) : Animal(src) {
	this->_brain = new Brain(*(src.getBrain()));
	std::cout << this->_type << " Copy Constructor Called" << std::endl;
}

Cat&	Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << this->_type << " Assignement Operator Called" << std::endl;
	return *this;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << this->_type << " Desctructor Called" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "* Meow *" << std::endl;
}

void	Cat::displayIdeas(int start, int end) const {
	for (int i = start; i < end; i++)
		std::cout << this->_brain->getIdea(i) << std::endl;
}

Brain*	Cat::getBrain(void) const {
	return this->_brain;
}