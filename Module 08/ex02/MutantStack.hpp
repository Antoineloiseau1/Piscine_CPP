#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> 
{

	public:

		MutantStack(void) {}
		MutantStack(const MutantStack &src) 
		{ 
			for (iterator it = src.begin(); it != src.end(); it++) 
			{
				push(*it); 
			}
		}
		~MutantStack(void) {}

		MutantStack &	operator=(const MutantStack &rhs) 
		{
			if(this != &rhs)
			{
				std::stack<T, Container>().swap(this);
				for (iterator it = rhs.begin(); it != rhs.end(); it++) 
				{
					push(*it);
				}
			}
			return *this;
		}

		/*	- typename keyword tell the compiler the next sentence is considered as a type
			- here, the type is std::stack<T, Container>::container_type::iterator
			- container_type is referred to  the underlying container of std::stack<T, Container>
			- typedef creates an "alias" named "iterator" to the whole line */
		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		//this->c is a pointer to c (underlying container)
		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }

};

#endif