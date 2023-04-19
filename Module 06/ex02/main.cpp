#include "Base.hpp"
#include <typeinfo>
#include <iostream>

int main(void) {
	Base* base = generate();
	std::cout << typeid(*base).name() << std::endl;
	identify(base);
	delete base;
}