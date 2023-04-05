#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define TAB_SIZE 10

int	main(void) {
	std::cout << "SUBJECT TESTS" << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	delete j;
	delete i;
	
	//const Animal *pet = new Animal;
	//Animal	pet;

	std::cout << std::endl << "COPY TEST" << std::endl;

	Animal	*a = new Cat();
	Cat		*cast = dynamic_cast<Cat *>(a);
	Animal	*b = new Cat(*cast);

	std::cout << a->getType() << std::endl;
	a->makeSound();
	std::cout << b->getType() << std::endl;
	b->makeSound();
	delete a;
	delete b;

	std::cout << std::endl << "ARRAY TESTS" << std::endl;
	const Animal	*animal[TAB_SIZE];

	for (int i = 0; i < TAB_SIZE; i++) {
		if (i < TAB_SIZE / 2)
			animal[i] = new Dog();
		else 
			animal[i] = new Cat();
	}

	const Cat	*cat;
	const Dog	*dog;
	std::srand(time(NULL));

	for (int i = 0; i < TAB_SIZE; i++) {
		std::cout << animal[i]->getType() << std::endl;
		if (animal[i]->getType() == "Cat") {
			cat = dynamic_cast<const Cat *>(animal[i]);
			std::cout << cat->getBrain()->getIdea(std::rand() % 100) << std::endl;;
		}
		if (animal[i]->getType() == "Dog") {
			dog = dynamic_cast<const Dog *>(animal[i]);
			std::cout << dog->getBrain()->getIdea(std::rand() % 100) << std::endl;
		}
		animal[i]->makeSound();
	}

	for (int i = 0; i < TAB_SIZE; i++) {
		delete animal[i];
	}

	return (0);
}