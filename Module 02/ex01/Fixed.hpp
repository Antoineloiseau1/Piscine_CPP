#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
	
		int					_fixedPointValue;
		static int const	_nbFractionnalBits = 8;

	public:

		Fixed(void);							//default constructor
		Fixed(int const i);						//int paramater constructor
		Fixed(float const f);					//float parameter constructor
		Fixed(Fixed const &src);				//copy constructor
		~Fixed(void);							//destructor
		Fixed&	operator=(Fixed const &rhs);	//assignation overload

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const ;
};

std::ostream&	operator<<(std::ostream& out, Fixed const& instance);

#endif