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
		MutantStack<T, U>(const MutantStack & src) { /* insert code here */ }
		const MutantStack &	operator=(const MutantStack & rhs) {/* Insert code here */ }
		~MutantStack<T, U>(void) {}

		// Stack based functions:
		bool	empty(void)						const	{ return _stack.empty(); }
		size_t	size(void)						const	{ return _stack.size(); }
		T		top(void)						const	{ return _stack.top(); }
		void	push(T element)							{ _stack.push(element); }
		void	pop(void)								{ _stack.pop(); }
		void	swap(const MutantStack & stack)			{ std::swap(_stack, stack); }
	
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
				iterator&	operator=(const T & rhs) 
				{
					if(this == &rhs)
					{
						return *this;
					}
					return &rhs; 
				}
				T&			operator*(void) const { return *_p; }
				bool		operator==(const iterator & rhs) const { return _p == rhs._getPointer(); }
				bool		operator!=(const iterator & rhs) const { return _p != rhs._getPointer(); }
				iterator&	operator++(void) { --_p; return *this; }
				iterator	operator++(int) 
				{
					iterator	tmp = *this;

					operator++();
					return tmp;
				}
				iterator&	operator--(void) { ++_p; return *this; }
				iterator	operator--(int) 
				{
					iterator	tmp = *this;

					operator--();
					return tmp;
				}
		};
		
		// Pointers accessors
		iterator	begin(void) { return iterator(&_stack.top()); }

		iterator	end(void)	{

			// std::stack<T>	tmp;
			// // int					value;
			// // std::vector<T>		vector;
			// MutantStack::iterator	it;

			// std::swap(tmp, _stack);
			// it = &_stack.top();
			// std::swap(tmp, _stack);
			// // // while(!tmp.empty())
			// // {
			// // 	value = tmp.top();


			// // }
			size_t	size = _stack.size();
			for(size_t i = 0; i < size -; i++)
			{
				_stack.pop();
			}
			
			return	iterator(&_stack.top());
		}

};

#endif