#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	for (int i = 0; i < 100; i++)
		this->setIdea(i, std::to_string(i + 1));
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain &src) {
	*this = src;
}

Brain&	Brain::operator=(const Brain &rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdea(i);
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor Called" << std::endl;
}

std::string	Brain::getIdea(int index) const{
	return this->_ideas[index];
}

void	Brain::setIdea(int index, const std::string idea) {
	this->_ideas[index] = idea;
}