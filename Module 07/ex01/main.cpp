#include "iter.hpp"
#include "ClassA.hpp"

int main(void)
{
	A			array[5] = {1, 2, 3, 4, 5};
	int			numbers[3] = {1, 2, 3};
	std::string	str[3] = {"foo", "bar", "toto"};
	float		pointed[3] = {3.14, 1.52, 978.4};


	std::cout << "USING DISPLAY\n";
	std::cout << "With Ints\n";
	iter(numbers, 3, display<int>);

	std::cout << "\nWith floats\n";
	iter(pointed, 3, display<float>);

	std::cout << "\nWith strings\n";
	iter(str, str->size(), display<std::string>);

	std::cout << "\nWith array of Class A\n";
	iter(array, 3, display<A>);


	std::cout << "\nAdding 1 to floats\n";
	iter(pointed, 3, addOne<float>);
	iter(pointed, 3, display<float>);

	std::cout << "\nAdding 1 to ints\n";
	iter(numbers, 3, addOne<int>);
	iter(numbers, 3, display<int>);

	std::cout << "\nAdding 1 to array\n";
	iter(array, 3, addOne<A>);
	iter(array, 3, display<A>);

 	return 0;
}