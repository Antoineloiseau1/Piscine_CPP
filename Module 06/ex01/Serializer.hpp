#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class Serializer {

	public:
		Serializer(void);
		Serializer(Serializer const & src);
		~Serializer(void);
		Serializer&	 			operator=(Serializer const & rhs);

		static unsigned int*	serialize(Data* ptr);
		static Data*			deserialize(unsigned int* raw);
};

#endif