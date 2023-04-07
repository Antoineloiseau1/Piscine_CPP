#pragma once

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {

	private:

		AMateria*	_items[4];
	
	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource & src);
		MateriaSource &	operator=(const MateriaSource & rhs);
		~MateriaSource(void);

		std::string	getType(int idx) const;
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif