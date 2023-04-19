#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {

	private:

		static char	_detectType(const std::string& literal);
		static void	_convertInteger(std::string literal);
		static void	_convertChar(std::string literal);
		static void	_convertFloat(std::string literal);
		static void	_displayError(void);

		enum	_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		};

	public:

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);

		ScalarConverter&	operator=(ScalarConverter const & rhs);

		static void			convert(const std::string& literal);
};

#endif