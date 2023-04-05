#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {

	private:

		Brain*	_brain;

	public:

		Cat(void);
		Cat(const Cat &src);
		Cat&	operator=(const Cat &rhs);
		~Cat(void);

		virtual void	makeSound(void) const override;
		Brain*	getBrain(void) const;
		void	displayIdeas(int start, int end) const;
};

#endif