#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;

	public:

		HumanA(std::string name, Weapon& weaponRef);
		~HumanA(void);

		void attack(void) const;
};

#endif