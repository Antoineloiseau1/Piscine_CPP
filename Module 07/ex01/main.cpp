#include "iter.hpp"
#include "ClassA.hpp"
#include <iostream>
#include <vector>

template<typename T>
void	display(T &data) { std::cout << data << std::endl; }

template<typename T>
void	addOne(T &data) { data++; }

int main(void)
{
	A<>*	array = new A<>[3];
	for (int i = 0; i < 3; i++)
		array[i] = A<>(i + 10);
	int			numbers[3] = {1, 2, 3};
	std::string	str[3] = {"foo", "bar", "toto"};
	float		pointed[3] = {3.14, 1.52, 978.4};


	std::cout << "USING DISPLAY\n";
	std::cout << "With Ints\n";
	iter(numbers, 3, &display);

	std::cout << "\nWith floats\n";
	iter(pointed, 3, &display);

	std::cout << "\nWith strings\n";
	iter(str, str->size(), &display);

	std::cout << "\nWith array of Class A\n";
	iter(array, 3, &display);


	std::cout << "\nAdding 1 to ints\n";
	iter(pointed, 3, &addOne);
	iter(pointed, 3, &display);

	std::cout << "\nAdding 1 to floats\n";
	iter(numbers, 3, &addOne);
	iter(numbers, 3, &display);

	std::cout << "\nAdding 1 to array\n";
	iter(array, 3, &addOne);
	iter(array, 3, &display);

	delete[] array;
 	return 0;
}