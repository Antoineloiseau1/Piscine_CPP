#pragma once

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character: public ICharacter {

	private:

		std::string	_name;
		AMateria	*_materia[4];

	public:

		/* Canonical form Constructors */
		Character(void);
		Character(std::string name);
		Character(const Character & src);
		Character & operator=(const Character & rhs);
		~Character(void);

		/* Accessors and settors */
		AMateria*	getMateria(int idx) const;
		std::string const & getName(void) const;

		/* Member functions */
		void	use(int idx, ICharacter& target);
		void	equip(AMateria* m);
		void	unequip(int idx); 
};

#endif