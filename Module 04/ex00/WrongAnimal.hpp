#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

	protected:

		std::string _type;
	
	public:

		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal&	operator=(const WrongAnimal &rhs);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void	makeSound(void) const;
};

#endif