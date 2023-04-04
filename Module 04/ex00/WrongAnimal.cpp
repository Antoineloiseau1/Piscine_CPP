#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal Parametric Constructor Called Initialised with \"";
	std::cout << this->_type << "\" type" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	*this = src;
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "WrongAnimal Assigment Operator Overload Called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Desctructor Called" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return this->_type;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "* sound of a WrongAnimal *" << std::endl;
}