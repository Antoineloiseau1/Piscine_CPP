#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
{	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;}

{	std::cout << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound();
	wmeta->makeSound();
	delete wmeta;
	delete wi;}


{	std::cout << std::endl;
	Animal* meta = new Animal();
	Dog j;
	Cat i;
	std::cout << j.getType() << " " << std::endl;
	std::cout << i.getType() << " " << std::endl;
	i.makeSound(); //will output the cat sound!
	j.makeSound();
	meta->makeSound();
	Dog	iris = j;
	Cat	chamouth(i);}

	return 0;
}