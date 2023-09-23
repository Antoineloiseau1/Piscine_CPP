#include "Span.hpp"
#include <algorithm>
#include <limits.h>
#include <iostream>

//Canonical class functions
Span::Span(unsigned int N) : _maxSize(N) { _data.clear(); }
Span::Span(Span const & src)
{
	_data.clear();
	_maxSize = src.getMaxSize();
	for(std::vector<int>::iterator	it = src.getData().begin(); it != src.getData().end(); it++)
	{
		_data.push_back(*it);
	}
}
Span &	Span::operator=(Span const & rhs)
{
	if(this != &rhs)
	{
		_maxSize = rhs.getMaxSize();
		_data.erase(_data.begin(), _data.end());
		for(std::vector<int>::iterator	it = rhs.getData().begin(); it != rhs.getData().end(); it++)
		{
			_data.push_back(*it);
		}
	}
	return *this;
}
Span::~Span(void) {}

// Accessors
std::vector<int>	Span::getData(void) const { return this->_data; }
int					Span::getMaxSize(void) const { return this->_maxSize; }

//Push a number back to vector
void	Span::addNumber(int n) 
{
	if(this->_data.size() >= _maxSize)
	{
		throw	Span::MaximumCapacityException();
	}
	this->_data.push_back(n);
}

//Add a set of numbers to vector
void	Span::addSetOfNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if(std::distance(first, last) + _data.size() > _maxSize)
	{
		throw MaximumCapacityException();
	}
	this->_data.insert(_data.end(), first, last);
}

//Returns the lowest difference between two numbers in the sorted set 
int	Span::shortestSpan(void) 
{	
	int	shortestSpan = INT_MAX;
	std::vector<int>	tmp(_data);

	if(_data.size() <= 1 ) 
	{
		throw NotEnoughElementException();
	}
	std::stable_sort(tmp.begin(), tmp.end());
	for(std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++) 
	{
		if (*(it + 1) - *it <= shortestSpan)
		{
			shortestSpan = *(it + 1) - *it;
		}
	}
	return shortestSpan;
}

//Returns the difference between highest and lowest number in set
int Span::longestSpan(void) 
{

	if(_data.size() <= 1 ) 
	{
		throw NotEnoughElementException();
	}
	return (*std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end()));
}

const char	*Span::MaximumCapacityException::what(void) const throw() { return "MaximumCapacityException: failed to add number due to maximum container capacity"; }
const char	*Span::NotEnoughElementException::what(void) const throw() { return "NotEnoughElementException: need at least 2 elements"; }

std::ostream	&operator<<(std::ostream &out, const Span & instance)
{

	out << "{";
	for(std::vector<int>::iterator it = instance.getData().begin(); it != instance.getData().end(); ++it) 
	{
		out << *it;
		if(it != (instance.getData().end() - 1))
		{
			out << ", ";
		}
	}
	out << "}";
	return out;
}