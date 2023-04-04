#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal Parametric Constructor Called Initialised with \"";
	std::cout << this->_type << "\" type" << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "Animal Assigment Operator Overload Called" << std::endl;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal Desctructor Called" << std::endl;
}

std::string	Animal::getType(void) const{
	return this->_type;
}

void	Animal::makeSound(void) const{
	std::cout << "* sound of an animal *" << std::endl;
}