#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

//Iterates and apply function f on every elements of a templated array
template<typename T, typename U>
void	iter(T *array, size_t const size, U f) {
	for(size_t i = 0; i < size; i++)
		f(array[i]);
}

template<typename T>
void	display(T &data) { std::cout << data << std::endl; }

template<typename T>
void	addOne(T &data) { data++; }

#endif