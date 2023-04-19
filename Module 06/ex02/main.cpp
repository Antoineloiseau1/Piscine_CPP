#include "Base.hpp"
#include <iostream>

int main(void) {
	identify(generate());
	identify(*generate());
}