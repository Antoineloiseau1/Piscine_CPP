#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <cstddef>
# include <iostream>

template <typename T, typename U = std::deque<T> >
class MutantStack {

	private:

		std::stack<T, U>	_stack;

	public:

		// Other type of container as construction parameter
		template<typename V>
		MutantStack<T, U>(const V & container) : _stack(container) {}

		// Canonical Form Class Constructors
		MutantStack<T, U>(void) {}
		MutantStack<T, U>(const MutantStack & src) {}
		const MutantStack &	operator=(const MutantStack & rhs) {}
		~MutantStack<T, U>(void) {}

		// Stack based functions:
		bool	empty(void)						const	{ return _stack.empty(); }
		size_t	size(void)						const	{ return _stack.size(); }
		T		top(void)						const	{ return _stack.top(); }
		void	push(T element)							{ _stack.push(element); }
		void	pop(void)								{ _stack.pop(); }
		void	swap(const MutantStack & stack)			{ _stack.swap(stack); }
	
		// Creating an iterator to MutantStack class:
		class iterator : std::iterator<std::input_iterator_tag, T>
		{
			private:

				T*				_p;
				T*				_getPointer(void) const { return _p; }

			public:

				// Canonical form class functions
				iterator(void) {}
				iterator(T* addr): _p(addr) {}
				iterator(const iterator & src) :  _p(src._getPointer()) {}

				// Operators overloads functions
				iterator&	operator=(const T & rhs) { return &rhs; }
				T&			operator*(void) const { return *_p; }
				bool		operator==(const iterator & rhs) const { return _p == rhs._getPointer(); }
				bool		operator!=(const iterator & rhs) const { return _p != rhs._getPointer(); }
				iterator&	operator++(void) { ++_p; return *this; }
				iterator	operator++(int) 
				{
					iterator	tmp = *this;

					operator++();
					return tmp;
				}
		};
		
		// Pointers accessors
		iterator	begin(void) { 
			
			typename U::iterator	it = U.begin();
			return iterator(it); 
		}

		iterator	end(void)
		{
			std::stack<int>	tmp(_stack);

			while(tmp.size())
			{
				tmp.pop();
			}
			return iterator(&tmp.top());
		}

};

#endif