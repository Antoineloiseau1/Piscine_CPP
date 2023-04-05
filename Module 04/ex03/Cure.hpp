#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {

	public:

		Cure(void);
		Cure(const Cure & src);
		Cure& operator=(const Cure & rhs);
		~Cure(void);

		Cure* clone(void) const;
		void	use(ICharacter & target) override;
};

#endif