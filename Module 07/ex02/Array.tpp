#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

template<typename T>
class Array {

	private:

		T*		_array;
		size_t	_size;
	
	public:

		Array<T>(void) : _array(NULL), _size(0) {}
		Array<T>(unsigned int n) :  _array(new T[n]()), _size(n) {}

		Array<T>(Array<T> & src) :  _array(new T[src.size()]), _size(src.size()) {
			for(size_t i = 0; i < _size; i++)
				_array[i] = src[i];
		}

		Array<T> &	operator=(Array<T> & rhs) {
			if(this == &rhs)
				return *this;
			if(this->size() != rhs.size())
			{
				T* temp = new T[rhs.size()]();
				delete[] _array;
				_array = temp;
				_size = rhs.size();
			}
			for (size_t i = 0; i < this->size(); i++)
				_array[i] = rhs[i];
			return *this;
		}

		T&	operator[](size_t index) {
			if(index >= this->size())
				throw outOfBoundsException();
			return _array[index];
		}

		// for (T) _array[index] = (T) data
		const T&  operator[](size_t index) const {
			if(index >= this->size())
				throw outOfBoundsException();
			return _array[index];
		}

		size_t	size(void) const { return _size; }

		class	outOfBoundsException : public std::exception {
				const char *what(void) const throw() { return "Array<Unknown> : outOfBoundsException: Trying to access memory at invalid index"; }
		};

		~Array<T>(void) { delete[] _array; }
};

#endif