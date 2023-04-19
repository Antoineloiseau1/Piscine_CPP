#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base::~Base(void) { return; }

Base*	generate(void) {
	std::srand(std::time(NULL));
	switch(std::rand() % 3) {
		default:
			return new A;
			break;
		case 1:
			return new B;
			break;
		case 2:
			return new C;
			break;
	}
}

void	identify(Base* p) {
	std::cout << reinterpret_cast<B*>(p) << std::endl;
	std::cout << reinterpret_cast<unsigned int*>(p) << std::endl;
}