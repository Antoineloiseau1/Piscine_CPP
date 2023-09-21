#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include<iterator>
# include<stdexcept>
# include<iostream>

/* Find the first occurrence of key in container, 
throw an exception if nothing is found */
template<typename T>
void easyfind(T & container, int key) {

	typename T::const_iterator	it;
	typename T::const_iterator	ite = container.end();

	for(it = container.begin(); it != ite; it++)
	{
		if(*it == key) {
			std::cout << key << " found at " << &it << std::endl;
			return ;
		}
	}
	throw std::out_of_range("easyfind: couldn't find key in container");
}

#endif