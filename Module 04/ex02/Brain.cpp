#include "Brain.hpp"
#include <iostream>


/* Default Constructor */
Brain::Brain(void) {
	for (int i = 0; i < 100; i++)
		setIdea(i, std::to_string(i + 1));
	std::cout << "Brain Constructor Called" << std::endl;
}


/* Copy Constructor */
Brain::Brain(const Brain &src) {
	for (int i = 0; i < 100 ; i++)
		this->_ideas[i] = src.getIdea(i);
	std::cout << "Brain Copy Constructor Called" << std::endl;
}


/* Assignment Operator */
Brain&	Brain::operator=(const Brain &rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdea(i);
	}
	std::cout << "Brain Assignement Operator Called" << std::endl;
	return *this;
}

/* Default Destructor */
Brain::~Brain(void) {
	std::cout << "Brain Destructor Called" << std::endl;
}

/* Get Idea of Index */
std::string	Brain::getIdea(int index) const{
	return this->_ideas[index];
}

/* Set Idea of Index */
void	Brain::setIdea(int index, const std::string idea) {
	this->_ideas[index] = idea;
}