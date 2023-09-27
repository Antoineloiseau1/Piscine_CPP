#include "Base.hpp"
#include <iostream>

int main(void) {
	Base	*b1 = generate();
	Base	*b2 = generate();
	Base	&b3 = *b1;
	
	identify(b1);
	identify(b2);
	identify(b3);

	delete b1;
	delete b2;

}