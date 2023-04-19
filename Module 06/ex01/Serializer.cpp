#include "Serializer.hpp"

Serializer::Serializer(void) { return; }
Serializer::Serializer(Serializer const & src) { static_cast<void>(src); return; }
Serializer&	Serializer::operator=(Serializer const & rhs) { static_cast<void>(rhs); return *this; }
Serializer::~Serializer(void) { return; }

unsigned int*	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<unsigned int*>(ptr);
}

Data*	Serializer::deserialize(unsigned int* raw) {
	return reinterpret_cast<Data*>(raw);
}
