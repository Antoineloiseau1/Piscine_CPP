#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {

	private:

		T*		_array;
		size_t	_size;
	
	public:

		//Default Constructor
		Array(void) : _array(NULL), _size(0) {}

		//Parametric Constructor
		Array<T>(unsigned int n) :  _array(new T[n]()), _size(n) {}

		//Copy Constructor
		Array<T>(Array<T> & src) :  _array(new T[src.size()]), _size(src.size()) {
			for(size_t i = 0; i < _size; i++)
				_array[i] = src[i];
		}

		//Assignment Operator Overload
		Array<T> &	operator=(Array<T> & rhs) {
			if(this != &rhs)
			{
				delete[] _array;
				_size = rhs.size();
				_array = new T[_size]();
				for (size_t i = 0; i < _size; i++)
					_array[i] = rhs[i];
			}
			return *this;
		}

		/* Array Subscript Operator Overload */
		T&	operator[](size_t index) {
			if(index >= this->size())
				throw std::out_of_range("Array<T>: index is out of bounds");
			return _array[index];
		}

		//_size Accessor
		size_t	size(void) const { return _size; }
	
		//Default Destructor
		~Array<T>(void) { delete[] _array; }

};

#endif