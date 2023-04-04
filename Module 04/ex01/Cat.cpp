#include "Cat.hpp"
#include <iostream>


Cat::Cat(void) : Animal("Cat") {
	this->_brain = new Brain;
	std::cout << this->_type << " Default Constructor Called" << std::endl; 
}

Cat::Cat(const Cat &src) {
	*this = src;
	std::cout << this->_type << "Copy Constructor Called" << std::endl;
}

Cat&	Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << this->_type << " Desctructor Called" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "* Meow *" << std::endl;
}

void	Cat::displayIdeas(void) const {
	for (int i = 0; i < 100; i++)
		std::cout << this->_brain->getIdea(i) << std::endl;
}