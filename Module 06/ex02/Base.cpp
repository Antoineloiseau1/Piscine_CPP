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
	std::cout << "class pointed by p is type: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A class" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B class" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C class" << std::endl;
}

void	identify(Base& p) {
	std::cout << "class referred by p is type: ";
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A class\n";
	}
	catch(const std::exception& e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B class\n";
	}
	catch(const std::exception& e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C class\n";
	}
	catch(const std::exception& e) {}
}