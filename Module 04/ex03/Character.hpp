#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter {

	private:

		std::string	_name;
		AMateria	*tab[4];

	public:

		Character(void);
		Character(std::string name);
		~Character(void);

		std::string const & getName(void) const override;
		void use(int idx, ICharacter& target) override;
};

#endif