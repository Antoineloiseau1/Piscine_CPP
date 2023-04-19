#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class Serializer {

	public:
		Serializer(void);
		Serializer(Serializer const & src);
		Serializer&	operator=(Serializer const & rhs);
		~Serializer(void);

		static unsigned int*	serialize(Data* ptr);
		static Data*			deserialize(unsigned int* raw);
};

#endif