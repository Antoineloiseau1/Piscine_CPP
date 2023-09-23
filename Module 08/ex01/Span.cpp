#include "Span.hpp"
#include <algorithm>
#include <limits.h>
#include <iostream>

//Canonical class functions
Span::Span(unsigned int N) : _maxSize(N) { _set.erase(_set.begin(), _set.end()); }
Span::~Span(void) {}

std::vector<int>	Span::getSet(void) const { return _set; }

//Push a number back to vector
void	Span::addNumber(int n) {
	if(this->_set.size() >= _maxSize)
		throw	Span::MaximumCapacityException();
	this->_set.push_back(n);
}

//Add a set of numbers to vector
void	Span::addSetOfNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	for(std::vector<int>::iterator it = first; it != last; it++)
		addNumber(*it);
}

//Returns the lowest difference between two numbers in the sorted set 
int	Span::shortestSpan(void) {
	if(_set.size() <= 1 )
		throw NotEnoughElementException();
	int	shortestSpan = INT_MAX;

	std::stable_sort(_set.begin(), _set.end());
	for(std::vector<int>::iterator it = _set.begin(); it != _set.end() - 1; it++)
	{
		if (*(it + 1) - *it < shortestSpan)
			shortestSpan = *(it + 1) - *it;
	}
	return shortestSpan;
}

//Returns the difference between highest and lowest number in set
int Span::longestSpan(void) {
	if(_set.size() <= 1 )
		throw NotEnoughElementException();
	return (*std::max_element(_set.begin(), _set.end()) - *std::min_element(_set.begin(), _set.end()));
}

const char	*Span::MaximumCapacityException::what(void) const throw() { return "MaximumCapacityException: failed to add number due to maximum container capacity"; }
const char	*Span::NotEnoughElementException::what(void) const throw() { return "NotEnoughElementException: need at least 2 elements"; }

std::ostream	&operator<<(std::ostream &out, Span instance)
{
	out << "{ ";
	for(std::vector<int>::iterator it = instance.getSet().begin(); it != instance.getSet().end(); ++it)
	{
		out << *it;
		if(it != (instance.getSet().end() - 1))
			out << ", ";
	}
	out << " }";
	return out;
}