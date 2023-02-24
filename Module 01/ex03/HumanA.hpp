#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		Weapon&		_weapon;
		std::string _name;

	public:

		HumanA(std::string name, Weapon& weaponRef);
		~HumanA(void);

		void attack(void) const;
};

#endif