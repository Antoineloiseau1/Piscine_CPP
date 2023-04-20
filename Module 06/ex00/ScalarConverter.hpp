#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {

	private:

		static bool	_isTypeInt(const std::string& literal);
		static bool	_isTypeFloat(const std::string& literal);
		static bool	_isTypeDouble(const std::string& literal);
		static char	_detectType(const std::string& literal);
		static void	_convertInteger(const std::string& literal);
		static void	_convertChar(const std::string& literal);
		static void	_convertFloat(const std::string& literal);	
		static void	_convertDouble(const std::string& literal);
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