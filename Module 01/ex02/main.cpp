#include <iostream>
#include <string>

int main(void)
{
	std::string 	msg = "HI THIS IS BRAIN";
	std::string*	stringPTR = &msg;
	std::string&	stringREF = msg;

	std::cout << "string address is: " << &msg << std::endl;
	std::cout << "address in stringPTR is: " << stringPTR << std::endl;
	std::cout << "address in stringREF is: " << &stringREF << std::endl;

	std::cout << "string value is: " << msg << std::endl;
	std::cout << "value pointed by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF is: " << stringREF << std::endl;
	
	return (0);
}