#ifndef SPAN_HPP
# define SPAN_HPP

# include<stdexcept>
# include <vector>
# include <iostream>

class Span {

	private:

		std::vector<int>	_set;
		unsigned int		_maxSize;

	public:

		Span(unsigned int N);
		~Span(void);

		void	addNumber(int n);
		void	addSetOfNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);

		std::vector<int>	getSet(void) const;	
		int		shortestSpan(void);
		int		longestSpan(void);

		class NotEnoughElementException: public std::exception {
			public:
				const char	*what(void) const throw();
		};

		class MaximumCapacityException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Span instance);

#endif