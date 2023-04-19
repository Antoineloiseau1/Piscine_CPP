#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data d = {65, 3.14, "Hello, World!"};
	std::cout << "Data struct: " << d << std::endl << "its address is: " << &d << std::endl;
	unsigned int*	ptr = Serializer::serialize(&d);
	std::cout << "return value of serialize: " << ptr << std::endl;
	Data* dptr = Serializer::deserialize(ptr);
	std::cout << "return value of deserialize: "<< *dptr << std::endl;
	std::cout << "with adress: " << dptr << std::endl;
} 