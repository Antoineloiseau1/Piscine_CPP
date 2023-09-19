#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template<typename T>
void	iter(T *addr, size_t const size, void (&fct)(T&)) {
	for(size_t i = 0; i < size; i++)
		fct(addr[i]);
}

#endif