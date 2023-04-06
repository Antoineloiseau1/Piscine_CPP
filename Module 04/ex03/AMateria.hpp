#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria {

	protected:

		std::string const _type;

	public:

		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &src);
		AMateria& operator=(const AMateria &rhs);
		virtual	~AMateria(void);


		std::string const getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif