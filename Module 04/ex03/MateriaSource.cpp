#include "MateriaSource.hpp"

/* Default Consctructor */
MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

/* Copy Constructor*/
MateriaSource::MateriaSource(const MateriaSource & src) {
	for (int i = 0; i < 4; i++)
		this->_items[i] = src._items[i]->clone();
}

MateriaSource &	MateriaSource::operator=(const MateriaSource & rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_items[i];
			this->_items[i] = rhs._items[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_items[i] == NULL)
		{
			this->_items[i] = materia;
			return ;
		}
	}
	delete materia; //fallen
}
AMateria* MateriaSource::createMateria(std::string const & type) {
	for(int i = 0; i < 4; i++)
	{
		if (this->_items[i] && this->_items[i]->getType() == type)
			return this->_items[i]->clone();
	}
	return 0;
	
}

std::string	MateriaSource::getType(int idx) const {
	return this->_items[idx]->getType();
}

MateriaSource::~MateriaSource(void) {
	for(int i = 0; i < 4; i++)
		delete this->_items[i];
}