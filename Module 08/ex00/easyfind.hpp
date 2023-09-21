#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include<iterator>
# include<stdexcept>
# include<algorithm>

/* Returns an iterator to the first occurrence of key in container, 
throw an exception if nothing is found */
template<typename T>
typename T::iterator easyfind(T & container, int key) {

	typename T::iterator	it = std::find(container.begin(), container.end(), key);

	if(it == container.end())
		throw std::out_of_range("easyfind: couldn't find key in container");
	return(it);
}

#endif