#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <vector>
# include <iostream>

class Span {

	private:

		std::vector<int>	_data;
		unsigned int		_maxSize;

	public:

		// Canonical class functions 
		Span(unsigned int N);
		Span(Span const & src);
		Span &	operator=(Span const & rhs);
		~Span(void);

		// Mandatory functions
		void				addNumber(int n);
		void				addSetOfNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
	 	int					shortestSpan(void);
		int					longestSpan(void);

		// Accessors
		std::vector<int>	getData(void) const;
		int					getMaxSize(void) const;

		// Exception Classes
		class NotEnoughElementException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
		class MaximumCapacityException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream & out, const Span & instance);

#endif