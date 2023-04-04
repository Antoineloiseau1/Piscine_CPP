#include "Dog.hpp"
#include <iostream>


Dog::Dog(void) : Animal("Dog") {
	std::cout << this->_type << " Default Constructor Called" << std::endl; 
}

Dog::Dog(const Dog &src) {
	*this = src;
	std::cout << this->_type << "Copy Constructor Called" << std::endl;
}

Dog&	Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << this->_type << " Desctructor Called" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "* Bark *" << std::endl;
}