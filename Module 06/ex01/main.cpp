#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data d = {65, 3.14, "Hello, World!"};
	std::cout << "Data struct: " << d << std::endl << "Its address is: " << &d << std::endl << std::endl;

	unsigned int*	ptr = Serializer::serialize(&d);
	std::cout << "return value of serialize: " << ptr << std::endl;

	std::cout << "Deserializing...\n";
	Data* dptr = Serializer::deserialize(ptr);
	std::cout << "return value of deserialize: "<< *dptr << std::endl << "with adress: " << dptr << std::endl;
	
	std::cout << std::endl << "chained: " << *Serializer::deserialize(Serializer::serialize(&d)) << std::endl;
} 