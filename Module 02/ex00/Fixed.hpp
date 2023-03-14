#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
	
		int					_value;
		static int const	_nbFractionnalBits = 8;

	public:

		Fixed(void);							//default constructor
		Fixed(Fixed const &src);				//copy constructor
		~Fixed(void);							//destructor
		Fixed&	operator=(Fixed const &rhs);	//assignation overload
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif