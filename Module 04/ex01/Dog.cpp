#include "Dog.hpp"
#include <iostream>


Dog::Dog(void) : Animal("Dog"), _brain(new Brain) {
	std::cout << this->_type << " Default Constructor Called" << std::endl; 
}

Dog::Dog(const Dog &src) : Animal(src) {
	this->_brain = new Brain(*(src.getBrain()));
	std::cout << this->_type << " Copy Constructor Called" << std::endl;
}

Dog&	Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << this->_type << " Assignement Operator Called" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << this->_type << " Desctructor Called" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "* Bark *" << std::endl;
}

Brain*	Dog::getBrain(void) const {
	return this->_brain;
}

void	Dog::displayIdeas(int start, int end) const {
	for (int i = start; i < end; i++)
		std::cout << this->_brain->getIdea(i) << std::endl;
}